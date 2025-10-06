/*
 * @lc app=leetcode.cn id=778 lang=cpp
 * @lcpr version=30204
 *
 * [778] 水位上升的泳池中游泳
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
// I.
struct Entry {
    int i;
    int j;
    int val;
    bool operator<(const Entry& other) const {
        return this->val > other.val;
    }
    Entry(int ii, int jj, int val): i(ii), j(jj), val(val) {}
};

class Solution {
    // I. 优先队列
    // 假设时间t时刻能到达位置(i, j), 对于任何一个与之相邻的位置(i', j')
    // 若grid[i'][j'] <= grid[i][j], 则(i', j')更低，时刻t也能到达
    // 否则grid[i'][j'] > grid[i][j], 则至少需要等到时刻grid[i'][j']方能到达
    // 从原点出发，每一步试图多访问一个位置，并记录到此为止的最短用时
    // 下一步我们考虑已访问方格能到达的所有方格，选择高度最低的进行下一步访问
    // 类似Dijkstra, 用优先队列维护所有能到达方格中的最小值即可
    // tc: O(n^2logn) (每次要从n^2中找到优先队列最小值 O(4n^2 * log(n^2)) = O(n^2logn))
    // sc: O(n^2)

    // II. 二分查找
    // 考虑这样一个问题：
    // 给定整数阈值threshold，是否存在一个路径, 
    // 使得threshold时间内从起点到达终点？
    // 解法其实很直观：执行BFS, 只去访问那些高度不超过threshold的方格
    // 如果能访问到终点，则说明路径存在
    // 如果能在threshold内找到，则同样能在threshold+1时间内找到，
    // 于是我们二分查找，寻找最小可能的threshold
    // tc: O(n^2logn) sc: O(n^2)

    // III. 并查集
    // 仿照II, 考虑threshold，我们将方格看做图中的顶点，两个相邻方格
    // 当且仅当他们的高度都不超过threshold的时候，将二者链接。
    // 从起点是否能到达终点，等价于对应的顶点是否连通，我们通过并查集维护节点之间的连通关系
    // 当然，我们也能通过二分查找寻找最小threshold，但是二分要重新构建并查集，得不偿失
    // 所以我们从小到大考虑threshold，每次考虑新值时，只需要在上一个阶段
    // 添加新边，而无需构建整张图，
public:
    // II.
    // bool check(vector<vector<int>>& grid, int threshold) {
    //     if (grid[0][0] > threshold) {
    //         return false;
    //     }
    //     int n = grid.size();
    //     vector<vector<int>> visited(n, vector<int>(n, 0));
    //     visited[0][0] = 1;
    //     queue<pair<int, int>> q;
    //     q.push(make_pair(0, 0));

    //     vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //     while (!q.empty()) {
    //         auto [i, j] = q.front();
    //         q.pop();

    //         for (const auto [di, dj]: directions) {
    //             int ni = i + di, nj = j + dj;
    //             if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
    //                 if (visited[ni][nj] == 0 && grid[ni][nj] <= threshold) {
    //                     q.push(make_pair(ni, nj));
    //                     visited[ni][nj] = 1;
    //                 }
    //             }
    //         }
    //     }
    //     return visited[n - 1][n - 1] == 1;
    // }

    // III.
    int find(vector<int>& f, int x) {
        if (f[x] == x) { // f: parent 列表
            return x;
        }
        int fa = find(f, f[x]);
        f[x] = fa; // 路径压缩，根直接作为x的父
        return fa;
    }
    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y); // fx, fy是各自的根
        f[fx] = fy;
    }

    int swimInWater(vector<vector<int>>& grid) {
        // I
        // int n = grid.size();
        // priority_queue<Entry, vector<Entry>, function<bool(const Entry& x, const Entry& other)>> pq(&Entry::operator<);
        // vector<vector<int>> visited(n, vector<int>(n, 0));

        // pq.push(Entry(0, 0, grid[0][0]));
        // int ret = 0;
        // vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // while (!pq.empty()) {
        //     Entry x = pq.top();
        //     pq.pop();
        //     if (visited[x.i][x.j] == 1) {
        //         continue;
        //     }
        //     visited[x.i][x.j] = 1;
        //     ret = max(ret, grid[x.i][x.j]);
        //     if (x.i == n - 1 && x.j == n - 1) {
        //         break;
        //     }
        //     for (const auto [di, dj]:directions) {
        //         int ni = x.i + di, nj = x.j + dj;
        //         if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
        //             if (visited[ni][nj] == 0) {
        //                 pq.push(Entry(ni, nj, grid[ni][nj]));
        //             }
        //         }
        //     }
        // }
        // return ret;

        // II.
        // int n = grid.size();
        // int left = 0, right = n * n - 1;
        // while (left < right) {
        //     int mid = (left + right) / 2;
        //     if (check(grid, mid)) {
        //         right = mid;
        //     } else {
        //         left = mid + 1;
        //     }
        // }
        // return left;

        // III.
        int n = grid.size();
        vector<int> f(n * n);
        for (int i = 0; i < n * n; i++) {
            f[i] = i;
        }
        vector<pair<int, int>> idx(n * n); // 存储每个平台高度对应的位置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                idx[grid[i][j]] = make_pair(i, j);
            }
        }

        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0},{-1, 0}};
        for (int threshold = 0; threshold < n * n; threshold++) {
            auto [i, j] = idx[threshold];
            for (const auto [di, dj]: directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= threshold) {
                    merge(f, i * n + j, ni * n + nj);
                }
            }
            if (find(f, 0) == find(f, n * n - 1)) {
                return threshold;
            }
        }
        return -1; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]\n
// @lcpr case=end

 */


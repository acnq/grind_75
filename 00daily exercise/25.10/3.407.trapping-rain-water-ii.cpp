/*
 * @lc app=leetcode.cn id=407 lang=cpp
 * @lcpr version=30204
 *
 * [407] 接雨水 II
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
typedef pair<int, int> pii;
class Solution {
    // 不愧是困难题，好久没有遇到直接没思路的题了
    // I. 最小堆
    // 首先思考一下什么样的方块一定可以接住雨水：
    // 1. 不能是最外层的方块
    // 2. 自身高度接水后比上下左右四个相邻的方块高度都要低
    // 设方块索引为(i, j), 高度heightMap[i][j],
    // 接水后，其高度变为water[i][j]
    // water[i][j] = max(heightMap[i][j], min(water[i-1][j], water[i+1][j],
    //                                      water[i][j + 1], water[i][j - 1]))
    // 而实际接水的容量为water[i][j] - heightMap[i][j]
    // 首先可以确定，最外层方块无法接水，所以有water[i][j] = heightMap[i][j]
    // 然后，我们根据木桶原理，直到容器内水能达到的最高高度就是四周最低高度
    // 这之后，我们还需要更新此高度为水面高度，以此类推。
    // 如此即可计算所有接水高度，最后计算容积即可
    // tc: O(MNlog(MN)) (log是最小堆调整的时间)，sc: O(MN)
    // II. DFS
    // 我们首先假设每个方块(i, j)接水后高度均为water[i][j] = maxHeight
    // 根据I中的公式，我们每次发现当前接水高度water[i][j] 小于相邻4个模块的接水高度时
    // 调整高度, 将其相邻的4方块的接水高度调整到与(i, j)保持一致，直到所有接水高度满足要求即可
    // tc: O(M^2N^2), sc: O(MN)
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // I.
        // if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
        //     return 0;
        // }
        // int m = heightMap.size();
        // int n = heightMap[0].size();
        // priority_queue<pii, vector<pii>, greater<pii>> pq;
        // // greater默认先比较第一个元素再比较第二个。
        // vector<vector<bool>> visit(m, vector<bool>(n, false));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
        //             pq.push({heightMap[i][j], i * n + j});
        //             visit[i][j] = true;
        //         }
        //     }
        // }

        // int res = 0;
        // int dirs[] = {-1, 0, 1, 0, -1};
        // while(!pq.empty()) {
        //     pii curr = pq.top();
        //     pq.pop();
        //     for (int k = 0; k < 4; k++) {
        //         int nx = curr.second / n + dirs[k];
        //         int ny = curr.second % n + dirs[k + 1];
        //         if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
        //             if (heightMap[nx][ny] < curr.first) {
        //                 res += curr.first - heightMap[nx][ny];
        //             }
        //             visit[nx][ny] = true;
        //             pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
        //         }
        //     }
        // }
        // return res;

        // II.
        int m = heightMap.size(), n = heightMap[0].size();
        int maxHeight = 0;
        int dirs[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
        }
        vector<vector<int>> water(m, vector<int>(n, maxHeight));
        queue<pair<int, int>> qu;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (water[i][j] > heightMap[i][j]) {
                        water[i][j] = heightMap[i][j];
                        qu.push(make_pair(i, j));
                    }
                }
            }
        }
        while (!qu.empty()) {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
                    water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
                    qu.push(make_pair(nx, ny));
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]\n
// @lcpr case=end

 */


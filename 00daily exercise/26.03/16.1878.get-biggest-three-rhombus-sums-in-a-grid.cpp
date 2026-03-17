/*
 * @lc app=leetcode.cn id=1878 lang=cpp
 * @lcpr version=30204
 *
 * [1878] 矩阵中最大的三个菱形和
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

struct Answer {
    array<int, 3> ans{};
    
    void put(int x) {
        if (x > ans[0]) {
            tie(ans[0], ans[1], ans[2]) = tuple{x, ans[0], ans[1]};
        } else if (x != ans[0] && x > ans[1]) {
            tie(ans[1], ans[2]) = tuple{x, ans[1]};
        } else if (x != ans[0] && x != ans[1] && x > ans[2]) {
            ans[2] = x;
        }
    }

    vector<int> get() const {
        vector<int> ret;
        for (int num: ans) {
            if (num) {
                ret.push_back(num);
            }
        }
        return ret;
    }
};
class Solution {
public:
    // I. 枚举所有的菱形
    // 用2个变量表示菱形上顶点的坐标,1个变量表示菱形的宽度
    // sum1[x][y]: 表示位置(x - 1, y - 1)开始往左上方走,走到边界为止的所有格子的元素和
    // sum2[x][y]: 表示位置(x - 1, y - 1)开始往右上方走,走到边界为止的所有格子的元素和
    // sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1]
    // sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1]
    // i,j\in[1,m]以及[1,n]
    // 上下左右顶点的位置依次记为(ux, uy), (dx, dy), (lx, ly), (rx, ry)
    // 我们分解为五个部分:
    // sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]
    // sum1[rx + 1][ry + 1] - sum1[ux][uy]
    // sum1[dx + 1][dy + 1] - sum1[lx][ly]
    // sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]
    // grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]
    // (1) + (2) + (3) + (4) - (5)即是答案
    // tc: O(mnmin(m, n)), sc: O(mn)
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum1(m + 1, vector<int>(n + 2));
        vector<vector<int>> sum2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum1[i][j] = sum1[i - 1][j - 1] + grid[i][j];
                sum2[i][j] = sum2[i - 1][j + 1] + grid[i][j];
            }
        }
        Answer ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 单独格子是菱形
                ans.put(grid[i][j]);
                for (int k = i + 2; k < m; k += 2) {
                    int ux = i, uy = j;
                    int dx = k, dy = j;
                    int lx = (i + k) / 2, ly = j - (k - i) / 2;
                    int rx = (i + k) / 2, ry = j + (k - i) / 2;
                    if (ly < 0 || ry >= n) {
                        break;
                    }
                    ans.put(
                        (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                        (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                        (sum1[dx + 1][dy + 1] - sum1[lx][ly]) + 
                        (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                        (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry])
                    );
                }
            }
        }
        return ans.get();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[7,7,7]]\n
// @lcpr case=end

 */


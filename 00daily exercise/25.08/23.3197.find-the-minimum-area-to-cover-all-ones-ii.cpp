/*
 * @lc app=leetcode.cn id=3197 lang=cpp
 * @lcpr version=30204
 *
 * [3197] 包含所有 1 的最小矩形面积 II
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
class Solution {
    // I. 枚举 
    // 把grid分成三个不重叠的部分，然后每个部分用T3195的方法做就可以了
    // 总共六种可能，一种三横条，一种三竖条，剩下四种如下
    // ——   .. |: :|
    // ..   —— (3) (4)
    // (1)  (2)
    // 注意6种情况在旋转90°的下化约为3种 比如(1)转90°就是(4), (2)->(3), 三条也同样
public:
    int minimumSum(vector<vector<int>>& grid, int u, int d, int l, int r) {
        int min_i = grid.size(), max_i = 0;
        int min_j = grid[0].size(), max_j = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1) : INT_MAX / 3;
    }

    vector<vector<int>> rotate(vector<vector<int>>& vec) {
        int n = vec.size(), m = vec[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        return ret;
    }

    int solve(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res = min(res, minimumSum(grid, 0, i, 0, m - 1)
                    + minimumSum(grid, i + 1, n - 1, 0, j)
                    + minimumSum(grid, i + 1, n - 1, j + 1, m - 1));
                res = min(res, minimumSum(grid, 0, i, 0, j)
                    + minimumSum(grid, 0, i, j + 1, m - 1)
                    + minimumSum(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = min(res, minimumSum(grid, 0, i, 0, m - 1)
                    + minimumSum(grid, i + 1, j, 0, m - 1)
                    + minimumSum(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }

    int minimumSum(vector<vector<int>>& grid) {
        auto rgrid = rotate(grid);
        return min(solve(grid), solve(rgrid));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1,0],[0,1,0,1]]\n
// @lcpr case=end

 */


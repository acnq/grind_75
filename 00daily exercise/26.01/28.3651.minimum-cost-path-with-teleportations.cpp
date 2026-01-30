// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 * @lcpr version=30204
 *
 * [3651] 带传送的最小路径成本
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
    // I. 动态规划
    // costs[t][i][j]: 恰好t次传送，从(i, j)移动到终点(m - 1, n - 1)的最小成本
    // 考虑两种情况：
    //  1. 不使用任何传送, 从(i, j)移动到(i + 1, j) 或者(i, j + 1), 有
    //     costs[t][i][j] = min(costs[t][i + 1][j] + grid[i + 1][j], costs[t][i][j + 1] + grid[i][j + 1])
    //  2. 使用传送，可以传送到所有(x, y)且grid[x][y] <= grid[i][j], 有：
    //      costs[t][i][j] = min_{grid[x][y] <= grid[i][j]}costs[t - 1][x][y]
    // 记2.的最小值T(t - 1, i, j)
    // 使用points存放所有单元格坐标，按照grid值升序排列
    // 遍历points, 双指针记录值相同的区间[j, i], 维护已遍历单元格在costs[t - 1]的最小值
    // minCost, 更新区间内所有单元格points[r] = (x_r, y_r)的T(t - 1, x_r, y_r)为minCost
    // 因为costs[t]只依赖costs[t - 1], 省略t这一维度
    // tc: O((k + logmn) * mn) (k: 最多传送次数，mn: grid维度)， sc: O(mn)

public:
    
    int minCost(vector<vector<int>>& grid, int k)  {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(), [&](const auto& p1, const auto& p2)->bool {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i ++) {
                minCost = min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() && grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumAbsDifference
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 4\n[[0,1,3],[3,1,1],[2,3,4],[0,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,2,1],[2,1,1],[1,3,1],[2,3,3]]\n
// @lcpr case=end

 */


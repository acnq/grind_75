/*
 * @lc app=leetcode.cn id=3742 lang=cpp
 * @lcpr version=30204
 *
 * [3742] 网格中得分最大的路径
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
    // I. DP
    // 背包问题
    // 定义dp[i][j][c]: 到达位置(i, j), 花费c的最大得分
    // dp[i + 1][j][c + cost(i + 1, j)] = max(dp[i + 1][j][c + cost(i + 1, j)], dp[i][j][c] + grid[i + 1][j])
    // dp[i][j + 1][c + cost(i, j + 1)] = max(dp[i][j + 1][c + cost(i, j + 1)], dp[i][j][c] + grid[i][j + 1])
    // cost(i, j) = { 1, grid[i][j] != 0
    //              { 0, grid[i][j] = 0
    // init: dp[0][0][0] = 0
    // ans: max_{0<=c<=k}dp[m - 1][n - 1][c]
    // tc = sc = O(mnk)
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN))
        );
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN) {
                        continue;
                    }
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] = 
                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] =
                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0, 1],[2, 0]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0, 1],[1, 2]]\n1\n
// @lcpr case=end

 */


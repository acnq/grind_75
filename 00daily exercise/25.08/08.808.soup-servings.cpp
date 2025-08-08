/*
 * @lc app=leetcode.cn id=808 lang=cpp
 * @lcpr version=30204
 *
 * [808] 分汤
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
    // 四种分配都是25的倍数，我们n/25 (有余数补1)，四种分配记为
    // (4, 0), (3, 1), (2, 2), (1, 3), 概率1/4
    // dp(i, j): A汤剩下i,B汤剩下j所求的概率值（A先分配完的概率+AB同事分配完的概率/2)
    // dp(i, j) = 1/4(dp(i - 4, j) + dp(i - 3, j - 1) + dp(i - 2, j - 2) + dp(i - 1, j - 3))
    // i > 0, j = 0, 无法再分配了，dp(i, j) = 0;
    // i = 0, j = 0, dp(i, j) = 1.0 * 0.5 = 0.5;
    // i = 0, j > 0, dp(i, j) = 1.0
    // 注意这样的tc: O(n^2), 我们这么思考：一次分配A被分配的期望E(A) = 2.5
    // E(B) = 1.5, 所以显然，A被先分配完的概率几乎一定是1，注意n >= 4475, 所求概率和1<10^(-5)
    // 于是n比他大，返回1，否则动态规划，这样复杂度在n->\inf时不会趋近n^2
    // II. 记忆化搜索
    // 类推即可
public:
    vector<vector<double>> memo;
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1;
        } else if (b <= 0) {
            return 0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + 
                            dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return memo[a][b];
    }
    double soupServings(int n) {
        // I.
        // n = ceil((double) n / 25);
        // if (n >= 179) {
        //     return 1.0;
        // }
        // vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        // dp[0][0] = 0.5;
        // for (int i = 1; i <= n; i++) {
        //     dp[0][i] = 1.0;
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <=n; j++){
        //         dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
        //             dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
        //     }
        // }
        // return dp[n][n];

        // II.
        n = ceil((double) n / 25);
        if (n >= 179) {
            return 1.0;
        }
        memo = vector<vector<double>>(n + 1, vector<double>(n + 1));
        return dfs(n, n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 50\n
// @lcpr case=end

// @lcpr case=start
// 100\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 * @lcpr version=30204
 *
 * [2787] 将一个数字表示成幂的和的方案数
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

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. DP
    // 返回互不相同的整数组合个数，我们可以将n看做背包容量，而[1^x, 2^x, ......]
    // 则是背包物品，转化为背包问题，dp[i][j]:前i个数字选择不同数字的x次幂之和
    // 为j的方案数。从1开始枚举，假设当前枚举数字为i, 幂次和为j, 有
    // 不选择数字i, dp[i][j] = dp[i - 1][j]
    // 选择数字i, 要有i^x <= j, dp[i][j] = dp[i - 1][j - i^x]
    // 综上
    //j < i^x: dp[i][j] = dp[i - 1][j]
    // j >= i^x: dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i^x]

    // II. 空间优化
    // dp[j]表示用若干互不相同数得到x次幂和为j的总方案数，
    // j < i^x, dp[j]不变
    // j >= i^x, dp[j] = dp[j] + dp[j - i^x]
    // tc: O(n \sqrt*x(n)), sc: O(n)
public:
    int numberOfWays(int n, int x) {
        // I.
        // long long mod = 1e9 + 7;
        // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        // dp[0][0] = 1;
        // for (int i = 1; i <= n; i++) {
        //     long long val = pow(i, x);
        //     for (int j = 0; j <= n; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= val) {
        //             dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % mod;
        //         }
        //     }
        // }
        // return dp[n][n];

        // II. 
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            if (val > n) {
                break;
            }
            for (int j = n; j >= val; j--) {
                dp[j] = (dp[j] + dp[j - val]) % mod;
            }
        }
        return dp[n];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numberOfWays
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 10\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 * @lcpr version=30204
 *
 * [3129] 找出所有稳定的二进制数组 I
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
    // arr中每个长度超过limit的子串同时包含0/1，等价于
    // 所有长度=limt+1的子串同时包含0/1
    // dp0[i][j] := 已经填入了i个0和j个1, 最后填入的数字为0的可行方案数目
    // dp1[i][j] :=                   ...              1  ...
    // 以dp0[i][j]为例，我们分析如下：
    // - j = 0 && i \in [0, min(zero, limit)], 不断填入0即可，此时 dp0[i][j] = 1
    // - i = 0 || (j = 0 && i \in [0, min(zero, limit)]), dp0[i][j] = 0
    // - i > 0 && j > 0, dp0[i][j] 可以由dp0[i - 1][j]和dp1[i - 1][j]转移过来（最后是0，故i-1）
    //   - dp1[i - 1][j]: 最后填入0即可
    //   - dp0[i - 1][j]: i <= limit，最后填入0，否则需要考虑去除不可行方案
    //                    因为dp0[i-1][j]对应的, 除了最后limit个连续的0情况下都可行，
    //                    所以我们统计这些方案数目，这对应了dp1[i - limit - 1][j]个方案
    // dp0[i][j] = { 1,                                                     i \in [0, min(zero, limit)], j = 0
    //             { dp1[i - 1][j] + dp0[i - 1][j] - dp1[i - limit - 1][j], i > limit, j > 0
    //             { dp1[i - 1][j] + dp0[i - 1][j],                         i \in [0, limit], j > 0
    //             { 0,                                                     else
    // 同理，
    // dp1[i][j] = { 1,                                                     i = 0, j \in [0, min(one, limit)]
    //             { dp0[i][j - 1] + dp1[i][j - 1] - dp0[i][j - limit - 1]  i > 0, j > limit
    //             { dp0[i][j - 1] + dp1[i][j - 1],                         i \in [0, limit], j > 0
    //             { 0,                                                     else
    // ans = dp0[zero][one] + dp1[zero][one]
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));
        long long mod = 1e9 + 7;
        for (int i = 0; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                if (i > limit) {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
                } else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                if (j > limit) {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
                } else {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }
                dp[i][j][1]  = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n2\n
// @lcpr case=end

 */


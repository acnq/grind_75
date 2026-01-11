/*
 * @lc app=leetcode.cn id=712 lang=cpp
 * @lcpr version=30204
 *
 * [712] 两个字符串的最小ASCII删除和
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
    // m = len(s1), n =  len(s2), 创建(m + 1) * (n + 1)的二维数组dp
    // dp[i][j]: s1[0:i]和s2[0:j]相同的最小ASCII删除和
    // s1[0:0] = s2[0:0]都为空，dp[0][0] = 0;
    // i = 0 && j > 0, s1[0:i]为空且s2[0:j]不为空，要是二者相同
    //  只有将另一个字符串全部删除，dp[0][j] = dp[0][j - 1] + s2[j - 1];
    // j = 0 && i > 0, s2[0:j]为空且s1[0:i]不为，同理可得:
    //   dp[i][0] = dp[i - 1][0] + s1[i - 1]
    // i > 0 && j > 0
    //  1.s1[i - 1] = s2[j - 1], 则dp[i][j] = dp[i - 1][j - 1]
    //  2.s1[i - 1] != s2[j - 1]
    //      2.1 使得s1[0:i-1]和s2[0:j]相同的最小ASCII删除和，加上删除s1[i - 1]的ASCII值；
    //      2.2     s1[0:i]和s2[0:j-1]                     加上删除s2[j - 1]的
    // dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1])
    // 所以：
    // dp[i][j] = { dp[i - 1][j - 1]         s1[i - 1] = s2[j - 1]
    //            { min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]), s1[i - 1] != s2[j - 1]
    // tc = sc: O(mn)
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            char c1 = s1[i - 1];
            for (int j = 1; j <= n; j++) {
                char c2 = s2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "delete"\n"leet"\n
// @lcpr case=end

 */


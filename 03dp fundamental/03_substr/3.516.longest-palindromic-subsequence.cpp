/*
 * @lc app=leetcode.cn id=516 lang=cpp
 * @lcpr version=30204
 *
 * [516] 最长回文子序列
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
    // 感觉同样可以通过中心扩展算法
    // 而且不用区分双字符扩展还是单字符扩展，前者可以归并到后者之中
    // 不行，如果dp[i, j]表示s[i:j]是否是子序列，则找到内部的子序列会非常困哪
    // dp[i, j]表示s[i:j]内最长子序列的长度
    // dp[i, i] = 1
    // dp[i, j]: 分类讨论，s[i] == s[j], 则dp[i, j] = dp[i + 1, j - 1] + 2;
    //                    否则，则dp[i, j] = max(dp[i + 1, j], dp[i, j - 1]
    // 这时候可以看到，i需要从大到小列举，而j从小到大
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bbbab"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */


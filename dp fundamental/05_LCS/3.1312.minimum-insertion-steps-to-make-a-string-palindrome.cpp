/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 * @lcpr version=30204
 *
 * [1312] 让字符串成为回文串的最少插入次数
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
    // 我们假设最后变成的回文串s', 根据长度的奇偶性s'分类讨论
    // 1. s'为奇数，回文中心设为c, 易知c一定来自原字符串，否则便是添加的，
    //    而如若不添加，立刻得到一个更短的字符串
    // 2. s'为偶数，回文中心设为cc, 同理可知cc也是来自原字符串的“连续串”，
    //    如若不是，则把添加字符的那一步舍弃，也可得到更短的字符串，所以两个都来自原串
    //    而且因为只有添加，没有删除原字符串字符的操作，所以原字符串的这两个字符也必然是连续的
    // 如此，我们可以首先枚举回文中心（包括单字符或者连续两个字符），
    // 再对左串p和右串q进行操作
    // 通过最少的操作使得reverse(p) = q
    // 令p = reverse(p), 化为子问题：
    // 添加最少得字符，使得p和q变为相同的字符串，
    // 解法：找到p,q的最长公共子序列，设长度为l, 最少添加|p| + |q| - l * 2 个字符即可
    // 这样我们得到了一个O(N^3)的算法, 会超时
    // 优化思路：如何把枚举字符串和计算LCS结合起来呢？
    // 假定已经找到了回文中心（c/cc）和此时的最长子序列r, 注意到这三个部分拼接
    // inv(r) + c/cc + r也是s的子序列，此串越长，添加的字符越少，
    // 所以，问题直接转化为，在s中找到一个“最长回文子序列”，若长度l, 添加|s| - l个字符，就可得到回文串
    // 那么怎么找到最长回文串呢？
    // 简单来说，最长回文串r即是s的子序列，也是inv(s)的子序列，所以其实这就是s和inv(s)的LCS,
    // 于是时间复杂度降为O(N^2)

    // II. 区间DP
    // dp[i][j]: 子串s[i:j]变成回文串所需的最少字符数
    // 由外向内考虑，s[i] == s[j] => 外侧已经是回文串继续考虑 s[i + 1:j - 1]
    //                   !=      => 在s[i:j]末尾添加s[i] => 继续考虑s[i + 1: j]
    //                              或者在s[i:j]开头添加s[j] => 继续考虑s[i:j - 1]
    // dp[i][j] = { min(dp[i + 1][j] + 1, dp[i][j - 1] + 1)                    s[i] != s[j]
    //            { min(dp[i + 1][j] + 1, dp[i][j - 1] + 1, dp[i + 1][j - 1])  s[i] == s[j]
    // dp[i][j] = 0 if i >= j
    // 顺序：首先枚举长度span = j - i + 1, 再枚举起点i, 
    // 其实当时想到的首先是这个方法，但是感觉和标签的LCS无关，然后又没有信心写对，就直接看答案了，TAT，
    // 现在想来，其实不如试一试
public:
    int minInsertions(string s) {
        // int n = s.size();
        // string t(s.rbegin(), s.rend());
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //         if (s[i - 1] == t[j - 1])
        //         {
        //             dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        //         }
        //     }
        // }
        // return n - dp[n][n];

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int span = 2; span <= n; span++)
        {
            for (int i = 0; i <= n - span; i++)
            {
                int j = i + span - 1;
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                if (s[i] == s[j])
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "zzazz"\n
// @lcpr case=end

// @lcpr case=start
// "mbadm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */


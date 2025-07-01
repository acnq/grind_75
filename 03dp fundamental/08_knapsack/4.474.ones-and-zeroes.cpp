/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30204
 *
 * [474] 一和零
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
    // 这里和经典背包问题不同，我们有两种容量，即m和n
    // 经典背包问题使用二维规划求解，分别是物品和容量，本题两种容量需要三维DP
    // 3维分别是字符串，0容量，1容量
    // dp[i][j][k]: 前i个字符串中，使用j个0，k个1的情况下最多可以得到的字符串数量
    // ans = dp[len(str)][m][n]
    // init: dp[0][j][k] = 0, \forall j, k
    // 如果j < str[i]中的0数量，或者k < str[i]中1的数量，则不能选第i个字符串
    //      否则超过了容量，dp[i][j][k] = dp[i - 1][j][k];
    // 如果j >= str[i]中0的数量(记为zeros)，且k >= str[i]中1的数量(记为ones)，则可选可不选
    //      不选：dp[i][j][k] = dp[i - 1][j][k]
    //      选：dp[i][j][k] = dp[i - 1][j - zeros][k - ones] + 1]
    // 综上
    // dp[i][j][k] = { dp[i - 1][j][k]                                            j < zeros || k < ones
    //               { max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1])  j >= zeros && k >= ones

    // tc: O(lmn + L) l = strs.size(), L strs所有字符串的长度和, sc: O(lmn)

    // II. 滚动数组
    // 去掉dp的第一个维度 sc: O(mn)

public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++)
        {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        // int length = strs.size();
        // vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        // for (int i = 1; i <= length; i++)
        // {
        //     vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
        //     int zeros = zerosOnes[0], ones = zerosOnes[1];
        //     for (int j = 0; j <= m; j++)
        //     {
        //         for (int  k = 0; k <= n; k++)
        //         {
        //             dp[i][j][k] = dp[i -  1][j][k];
        //             if (j >= zeros && k >= ones)
        //             {
        //                 dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
        //             }
        //         }
        //     }
        // }
        // return dp[length][m][n];

        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++)
        {
            vector<int>&& zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */


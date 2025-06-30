// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30204
 *
 * [1143] 最长公共子序列
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
    // longestCommonSubsequence, abbr: LCS
    // lcs[i][j]: text1[0:i -1]和text[0:j - 1]的LCS的长度, bc: lcs[0][j] = lcs[i][0] = 0
    // lcs[i][j] = max_{i' <= i, j' <= j} lcs[i'][j'] + { 1; text1[i - 1] = text2[j - 1]
    //                                                  { 0;              != 
    // max下的等号不能同时成立
    // 发现lcs无论是关于i还是j都是递增的，
    // 所以text[i - 1] != text2[j - 1], 取max(lcs[i - 1][j], lcs[i][j - 1])
    //                 ==               取lcs[i - 1][j - 1] + 1即可
    // ans = lcs[n][m] (lcs[i][j])的i,j理解为对应字符串取用了“前几个”字符
    // 和参考答案没有本质区别，略去官方答案
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans;
        int n = text1.size(), m = text2.size();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            lcs[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            lcs[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                if (text1[i - 1] == text2[j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1; 
                    // 这里一开始错误写成了lcs[i][j]++, 
                    // 这样abb和b的lcs就错误变成了2而非1
                }
            }
        }
        ans = lcs[n][m];
        return ans;    
        // 初见通，40min, 思考花的时间比较多
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=longestCommonSubsequence
// paramTypes= ["string","string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

// @lcpr case=start
// "bsbininm"\n"jmjkbkjkv"\n
// @lcpr case=end


 */


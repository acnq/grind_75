/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    // I. dp
    // P(i, j)表示s的第i,到第j个字母组成的串是否是回文串
    // P(i, j) = False 包括两种情况， s[i, j]不是回文串，或者i>j (s[i, j]此时不合法)
    // P(i, j) = P(i + 1, j - 1) && (s[i] == s[j])
    // P(i, i) = T, P(i, i+1) = (s[i] == s[i + 1])
    // 答案为所有P(i, j) = T中，j - i + 1的最大值

    // II. 中心扩展
    // 所有的状态转移都是从某个中心开始的扩展
    // 枚举所有的回文中心，并尝试扩展，直到无法扩展为止

    // III. Manacher 算法
    // 复杂度O(n)，但是很难，一般不作为面试内容
    // 定义概念臂长，为上文中中心扩展算法向外扩展的长度
    // 利用上次扩展的信息指导下一次扩展
    // 位置j, 臂长length, j + length > i
    // 当i开始中心拓展时，找到i关于j的对称点2 * j - 1
    // 如果此点有臂长为n的串，点i的臂长至少为min(j + length - i, n)
    // 因此我们跳过i到i + min(......)这部分, 从i + min(j + length - i, n) + 1
    // 只需记录右臂在最右边的回文字符串，记录其中心j
    // 那偶数的情况呢？
    // 向字符串的每两个字符中间和头尾加上#
    // aaba => #a#a#b#a#, aba => #a#b#a#；都可化归为奇数情况
    // 对于每个位置，扩展要么从当前的最右侧臂长right开始，要么只进行一步，
    // 而right 最多向前走O(n)步, 所以时间复杂度为O(n)

public:

    // II.
    pair<int, int> expandfCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        { // while条件无法再放宽了，left>=1则s[0]无法判断，left>=-1则s[-1]无法访问
            --left;
            ++right;
        }
        return {left + 1, right - 1}; // 注意while的退出条件
    }

    // III.
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return (right - left - 2) / 2; // 臂长
    }
    string longestPalindrome(string s) {
        // I.
        // int n = s.size();
        // if (n < 2)
        // {
        //     return s;
        // }
        
        // int maxlen = 1;
        // int begin = 0;
        // // dp[i][j] = P(i, j)
        // vector<vector<int>> dp(n, vector<int>(n));
        // // init
        // for (int i = 0; i < n; i++)
        // {
        //     dp[i][i] = true;
        // }
        // // 递推开始
        // // 先枚举子串长度
        // for (int L = 2; L <= n; L++)
        // {
        //     // 枚举左边界
        //     for (int i = 0; i < n; i++)
        //     {
        //         // L, i 确定右边界，j - i + 1 = L
        //         int j = L + i - 1;
        //         // 右边界越界直接退出
        //         if (j >= n)
        //         {
        //             break;
        //         }
                
        //         if (s[i] != s[j])
        //         {
        //             dp[i][j] = false;
        //         } else {
        //             if (j - i < 3)
        //             {
        //                 dp[i][j] = true;
        //             } else {
        //                 dp[i][j] = dp[i + 1][j - 1];
        //             }
        //         }
                
        //         // dp[i][L] = T => P(i, j) = T;
        //         // 在这里判断最值即可
        //         if (dp[i][j] && j - i + 1 > maxlen)
        //         {
        //             maxlen = j - i + 1;
        //             begin = i;
        //         }
        //     }
        // }
        
        // return s.substr(begin, maxlen);

        // II. 
        // int start = 0, end = 0;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     auto [left1, right1] = expandfCenter(s, i, i);
        //     auto [left2, right2] = expandfCenter(s, i, i + 1);

        //     if (right1 - left1 > end - start)
        //     {
        //         start = left1;
        //         end = right1;
        //     }

        //     if (right2 - left2 > end - start)
        //     {
        //         start = left2;
        //         end = right2;
        //     }
        // }
        
        // return s.substr(start, end - start + 1);

        // III.
        int start = 0, end = -1;
        string t = "#";
        for(char c: s) {
            t += c;
            t += '#';
        }
        s += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int cur_arm_len;
            if (right >= i)
            {
                int i_sym = j * 2 - i; // arm_len[i_sym] = n
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right)
            {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start)
            {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; i++)
        {
            if (s[i] != '#')
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
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
    // I. 滑动窗口
    // 显然某个字符串的异位词一定和它本身长度相同，
    // 构造和p等长的花窗，当其中每种字符的数量和p中每种字母的数量相同时
    // 说明此窗口中的串为p的异位词

    // II. 优化窗口
    // 不在分别统计花窗和字符串p中每种字符的数目
    // 而是统计花窗和字符p中每种字符的数量差
    // 引入differ记录窗口与字符p中数量不同的字母的个数
    // 只要判断differ是否为0即可判断二者是否相同
public:
    vector<int> findAnagrams(string s, string p) {
        // int slen = s.size(), plen = p.size();
        // if (slen < plen)
        // {
        //     return vector<int>();
        // }

        // vector<int> ans;
        // vector<int> scount(26);
        // vector<int> pcount(26);

        // for (int i = 0; i < plen; i++)
        // {
        //     scount[s[i] - 'a']++;
        //     pcount[p[i] - 'a']++;
        // }
        // if (scount == pcount)
        // {
        //     ans.emplace_back(0);
        // }
        // for (int i = 0; i < slen - plen; i++)
        // {
        //     scount[s[i] - 'a']--;
        //     scount[s[i + plen] - 'a']++;

        //     if (scount == pcount)
        //     {
        //         ans.emplace_back(i + 1);
        //     }
        // }
        
        // return ans;
        int slen = s.size(), plen = p.size();
        if (slen < plen)
        {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < plen; i++)
        {
            count[s[i] - 'a']++;
            count[p[i] - 'a']--;
        }

        int differ = 0;
        for (int j = 0; j < 26; j++)
        {
            if (count[j] != 0)
            {
                differ++;
            }
            
        }
        
        if (differ == 0)
        {
            ans.emplace_back(0);
        }
        
        for (int i = 0; i < slen - plen; i++)
        {
            if (count[s[i] - 'a'] == 1)
            { // 窗口中字母s[i]的数量与字符串p中的数量从不同变得相同
                differ --;
            } else if (count[s[i] - 'a'] == 0)
            {// 窗口中字母s[i]的数量与字符串p中的数量从想通变得不同
                differ++;
            }
            count[s[i] - 'a']--;
            if (count[s[i + plen] - 'a'] == -1)
            {// 窗口中字母s[i + plen]的数量与字符串p中的数量从不同变得相同
                differ--;
            } else if (count[s[i + plen] - 'a'] == 0)
            {// 窗口中字母s[i + plen]的数量与字符串p中的数量从相同变得不同
                differ++;
            }
            count[s[i + plen] - 'a']++;
            
            if (differ == 0)
            {
                ans.emplace_back(i + 1);
            }
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */


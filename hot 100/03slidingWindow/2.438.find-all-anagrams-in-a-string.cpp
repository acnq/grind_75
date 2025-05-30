// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
public:
    vector<int> findAnagrams(string s, string p) {
        // vector<int> ans;
        // int psize = p.size();
        // int ssize = s.size();
        // if(ssize < psize) {
        //     return {};
        // }
        // unordered_map<char, int> occ;
        // for (int i = 0; i < psize; i++)
        // {
        //     occ[p[i]]++;
        // } 

        // unordered_map<char, int> cocc;
        // for (int i = 0; i < psize; i++)
        // {
        //     cocc[p[i]]++;
        // }
        
        // int i = 0, j = 0;
        // while (i <= s.size() - psize)
        // {
            
        //     if (cocc.count(s[j]) <= 0)
        //     {
        //         while (j < s.size() && cocc.count(s[j]) <= 0)
        //         {
        //             j++;
        //         }
        //         i = j;
        //         cocc = occ;
        //     }

        //     while (cocc.count(s[j]) > 0 && cocc[s[j]] > 0 && j - i < psize)
        //     {
        //         cocc[s[j]]--;
        //         j++;
        //     }
        //     if (j - i == psize)
        //     {
        //         ans.push_back(i);
        //     }
        //     cocc[s[i]]++;
        //     i++;
        // }
        // return ans;

        // 参考答案：注意题目中出现的p, s均只包含小写字符
        // 那么我们根本不用哈希表，我们只需要vector即可
        int n = s.size(), m = p.size();
        if(n < m) {
            return {};
        }
        vector<int> scnt(26, 0);
        vector<int> pcnt(26, 0);
        vector<int> res;

        for(int i = 0; i < p.size(); i++) {
            pcnt[p[i] - 'a']++;
            scnt[s[i] - 'a']++;
        }

        if(pcnt == scnt) {
            res.push_back(0);
        }
        for (int i = 0; i < n - m; i++) // 别写上i < n - m + 1
        {
            scnt[s[i] - 'a']--;
            scnt[s[i + m] - 'a']++;
            if (pcnt == scnt)
            {
                res.push_back(i + 1);
            }
        }
        return res;
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


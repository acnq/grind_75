// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        // unordered_map<char, int> stat;
        // if (s.size() != t.size())
        // {
        //     return false;
        // } else {
        //     int N = s.size();
        //     for (int i = 0; i < N; i++)
        //     {
        //         char s_char = s[i];
        //         if (stat.count(s_char) == 0)
        //         {
        //             stat[s_char] = 1;
        //         } else {
        //             stat[s_char]++;
        //         }
        //     }
        //     for(int j = 0; j < N; j++) {
        //         char t_char = t[j];
        //         if (stat.count(t_char) == 0)
        //         {
        //             return false;
        //         } else {
        //             stat[t_char]--;
        //         }
        //     }
        // }
        // for (auto it: stat)
        // {
        //     if (it.second != 0)
        //     {
        //         return false;
        //     }
        // }
        // return true;
        // 最好的方法是用26个元素的统计表，上述的哈希优化并不彻底
        vector<int> table(26, 0);
        if (s.size() != t.size())
        {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            table[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            table[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (table[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */


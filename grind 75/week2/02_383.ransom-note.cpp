/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine) {
        // my solution:
        // string my_magazine = magazine;
        // for (int i = 0; i < ransomNote.size(); i++)
        // {
        //     char ch = ransomNote[i];
        //     size_t pos = my_magazine.find(ch);
        //     if (pos == string::npos)
        //     {
        //         return false;
        //     } else {
        //         my_magazine[pos] = ' ';
        //     }
            
        // }
        // return true;
        // offical solution: (use magazine cnt)
        if (ransomNote.size() > magazine.size())
        {
            return false;
        } else {
            vector<int> cnt(26, 0);
            for (int i = 0; i < magazine.size(); i++)
            {
                char ch = magazine[i];
                cnt[ch - 'a']++;
            }
            
            for (int i = 0; i < ransomNote.size(); i++)
            {
                char ch = ransomNote[i];
                cnt[ch - 'a']--;
                if (cnt[ch - 'a'] < 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */


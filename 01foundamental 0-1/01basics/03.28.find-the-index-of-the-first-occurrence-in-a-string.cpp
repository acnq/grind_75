// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        
        for (int i = 0; i <= n - m; i++)
        {
            // if needle == haystack.substr(i, m)
            bool susbstrEqFlat = true;
            for (int j = 0; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    susbstrEqFlat = false;
                    break;                    
                }
            }
            if (susbstrEqFlat == true)
            {
                return i;
            }
            
            
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end


// @lcpr case=start
// "abc"\n"c"\n
// @lcpr case=end

// @lcpr case=start
// "mississippi"\n"issi"\n
// @lcpr case=end
 */


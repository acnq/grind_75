// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] 重复的子字符串
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

    bool repeatedStrPattern(string s, string p) {
        int n = s.size(), m = p.size();
        if (n == m || n % m != 0)
        {
            return false;
        }
        
        for (int i = 0; i < n - m + 1; i += m)
        {
            string cmp = s.substr(i, m);
            if (cmp != p)
            {
                return false;
            }
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        
        for(int i = 1; i < s.size() ; i++) {
            string node = s.substr(0, i);
            // 判断string能否全部由node构成
            if (repeatedStrPattern(s, node))
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

// @lcpr case=start
// "abac"\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n
// @lcpr case=end
 */


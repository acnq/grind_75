// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
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
    // 注意到：递增的枚举子串的开头，所对应的极长子串结尾也一定是递增的
    // 理由如下：开头为k的子串长度为r_k, 则开头为k+1的子串因为缺少了s[k+1]的字符，之后的无重复字符子串一定只长不短
    // 双指针，一个指向开头i，一个指向结尾j，枚举每个i开头的极长子串，同时取最大值即可
    // 为了在子串增长时记录有无重复，需要一个哈希集来记录出现过的字符
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int res = 0;
        
        if (n == 1)
        {
            return 1;
        }
        
        int i = 0, j = 0, cur=0;
        for (i = 0; i < n; i++)
        {
            while (occ.count(s[j]) == 0 && j < n)
            {
                occ.insert(s[j]);
                cur++;
                j++;
            }
            res = max(res, cur);
            occ.erase(s[i]);
            cur--;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end


// @lcpr case=start
// "dvdf"\n
// @lcpr case=end

// @lcpr case=start
// "au"\n
// @lcpr case=end
 */


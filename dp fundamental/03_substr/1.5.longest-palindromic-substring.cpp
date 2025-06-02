// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    // 我们直接用中心扩展算法叭
    // 所谓的动态规划大概是说
    // dp(i, j): s[i:j]是否为回文串
    // dp(i , i) = True
    // dp(i, i + 1) = (s[i] == s[j])
    // dp(i, j) = (s[i] == s[j]) && dp(i + 1, j - 1)
    // 我们枚举中心，并且向两边扩展，直到s[i] != s[j]
public:
    vector<int> longestPalI(string s, int centerL, int centerR) {
        // longest Palindrome with center i
        int n = s.size(), i = centerL, j = centerR;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            i--;
            j++;
        }
        return {i + 1, j - 1};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> maxPair = {0, 0}, curPair = {0, 0};
        for(int i = 0; i < n; i++) {
            vector<int> pair1 = longestPalI(s, i, i);
            vector<int> pair2 = longestPalI(s, i, i + 1);
            if (pair1[1] - pair1[0] + 1 > pair2[1] - pair2[0] + 1)
            {
                curPair[1] = pair1[1];
                curPair[0] = pair1[0];
            } else {
                curPair[1] = pair2[1];
                curPair[0] = pair2[0];
            }
            if (curPair[1] - curPair[0] > maxPair[1] - maxPair[0])
            {
                maxPair[1] = curPair[1];
                maxPair[0] = curPair[0];
            }
        }
        return s.substr(maxPair[0], maxPair[1] - maxPair[0] + 1);
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


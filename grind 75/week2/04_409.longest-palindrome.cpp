/*
 * @lc app=leetcode.cn id=409 lang=cpp
 * @lcpr version=30204
 *
 * [409] 最长回文串
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
    int longestPalindrome(string s) {
        unordered_map<char, int> stats;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            stats[ch]++;
        }
        int ans = 0;
        for(auto& p: stats) {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 && ans % 2 == 0)
            {
                ans++;
                continue;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abccccdd"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */


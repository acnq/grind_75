/*
 * @lc app=leetcode.cn id=1957 lang=cpp
 * @lcpr version=30204
 *
 * [1957] 删除字符使字符串变好
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
    string makeFancyString(string s) {
        string ans;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leeetcode"\n
// @lcpr case=end

// @lcpr case=start
// "aaabaaaa"\n
// @lcpr case=end

// @lcpr case=start
// "aab"\n
// @lcpr case=end

 */


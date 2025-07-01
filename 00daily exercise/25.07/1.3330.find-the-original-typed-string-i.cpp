/*
 * @lc app=leetcode.cn id=3330 lang=cpp
 * @lcpr version=30204
 *
 * [3330] 找到初始输入字符串 I
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
    int possibleStringCount(string word) {
        int posb = 1;
        vector<char> stats(26);
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                posb++;
            }
            
        }
        return posb;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbcccc"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

 */


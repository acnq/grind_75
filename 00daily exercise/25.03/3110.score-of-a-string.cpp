/*
 * @lc app=leetcode.cn id=3110 lang=cpp
 * @lcpr version=30204
 *
 * [3110] 字符串的分数
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
    int scoreOfString(string s) {
        int N = s.size();
        int sum = 0;
        for (int i = 0; i < N - 1; i++)
        {
            sum += abs(s[i] - s[i + 1]);
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "hello"\n
// @lcpr case=end

// @lcpr case=start
// "zaz"\n
// @lcpr case=end

 */


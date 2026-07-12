/*
 * @lc app=leetcode.cn id=3754 lang=cpp
 * @lcpr version=30204
 *
 * [3754] 连接非零数字并乘以其数字和 I
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

#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;

        string s = to_string(n);
        for (char c: s) {
            int d = c - '0';
            sum += d;
            if (d > 0) {
                x = x * 10 + d;
            }
        }
        return x * sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10203004\n
// @lcpr case=end

// @lcpr case=start
// 1000\n
// @lcpr case=end

 */


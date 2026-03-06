/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 * @lcpr version=30204
 *
 * [1784] 检查二进制字符串字段
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
    // 化约：
    // 因为不包含前导0，所以零个'1'连续1只能是0...0, 
    // 一个连续1只能使1......10...0,
    // 所以只要出现01,就说明出现违反规则
    // tc: O(n), sc: O(1)
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1001"\n
// @lcpr case=end

// @lcpr case=start
// "110"\n
// @lcpr case=end

 */


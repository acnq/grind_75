/*
 * @lc app=leetcode.cn id=3612 lang=cpp
 * @lcpr version=30204
 *
 * [3612] 用特殊操作处理字符串 I
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
    // I. 模拟
    // 遍历模拟即可
    // '*': 删除最后一个字符
    // '#': 复制一份并将副本添加到尾部
    // '%': 反转result
    // tc = sc: O(2^n)
public:
    string processStr(string s) {
        string result = "";
        for (auto it: s) {
            if (it == '*') {
                if (result.size()) {
                    result.pop_back();
                }
            } else if (it == '#') {
                result += result;
            } else if (it == '%') {
                result = string(result.rbegin(), result.rend());
            } else {
                result += it;
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a#b%*"\n
// @lcpr case=end

// @lcpr case=start
// "z*#"\n
// @lcpr case=end

 */


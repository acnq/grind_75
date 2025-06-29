/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
    // I. 栈
    // 遇到右括号时，取出栈顶的左括号判断是否相同类型，
    // 为了快速判断括号类型，可以用哈希表存储每一种括号，键为右括号，值为左
    // 注意遍历结束要检查栈中是否还有左括号，有的话说明有左括号没有闭合，也要返回False
    // 长度为奇数的字符串直接返回False，肯定有落单的括号
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch))
            {
                if (stk.empty() || stk.top() != pairs[ch])
                {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();       
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */


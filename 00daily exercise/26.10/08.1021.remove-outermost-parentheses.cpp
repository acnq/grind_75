/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 * @lcpr version=30204
 *
 * [1021] 删除最外层的括号
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
    // 我们用栈记录没有匹配的左括号，遇到'('入栈，遇到')'出栈
    // 那么显然，栈从空到下一次空的过程就是扫描一个原语的过程
    // 一个原语要去除首尾括号，因此如果遇到'('并将字符入栈后，
    // 只有此字符, 则不把它添加到结果字符串中; 
    // 遇到')'并把栈顶字符出栈后，如果栈空，也不把它放入结果
    // 其他情况下均把字符放入结果，则得答案
    // tc = sc = O(n)

    // II. 计数
    // 和之前一样我们把栈用计数器代替，遇到'('+1, 遇到')'-1
    // 和为0表示一个原语，
    // tc = sc = O(n)
public:
    string removeOuterParentheses(string s) {
        // I.
        // string res;
        // stack<char> stk;
        // for (auto c: s) {
        //     if (c == ')') {
        //         stk.pop();
        //     }
        //     if (!stk.empty()) {
        //         // 顺序放在这里保证最外层左右括号不会进入res
        //         res.push_back(c);
        //     }
        //     if (c == '(') {
        //         stk.emplace(c);
        //     }
        // }
        // return res;

        // II.
        int level = 0;
        string res;
        for (auto c: s) {
            if (c == ')') {
                level--;
            }
            if (level) {
                res.push_back(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()())(())"\n
// @lcpr case=end

// @lcpr case=start
// "(()())(())(()(()))"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

 */


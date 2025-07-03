/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    // I. DP
    // dp[i]: 以下标i字符结尾的最长有效括号长度
    // 显然'('结尾的子串对应的dp值必为0，所以我们只需要求解')'即可
    // 1. s[i] = ')' && s[i - 1] = '(': dp[i] = dp[i - 2] + 2
    // 2. s[i] = ')' && s[i - 1] = ')': 则若s[i - dp[i - 1] - 1] = '('
    //                                  dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
    // 形如：s1(s_2)), s1末尾下标i - dp[i - 1] - 2, s_2的长度（如果有效）就是dp[i - 1]
    // sc/tc: O(n)

    // II. 栈
    // 始终保持栈底元素为当前已经遍历过的元素中“最后一个没有被匹配的右括号下标”
    // 1. 遇到每个'(', 将它的下标放入栈中
    // 2. 遇到每个')', 弹出栈顶表示匹配右括号
    //      如果栈为空，说明当前右括号没有被匹配，将其下标放入栈中，更新“最后一个没有被匹配的右括号下标”
    //      如果不为空，当前右括号的下标减去栈顶元素即为“以该右括号为结尾的最长有效括号长度”
    // sc/tc: O(n)

    // III. 贪心
    // 用两个计数器left, right计数'('和')'的数量，每当二者相等，才计算当前有效字符串长度，记录最长字符串
    // right > left时，二者同时变为0
    // 那么如果左括号总是大于右括号的数量，不是都求不出来了么？
    // 解决方案也很简单，我们反向遍历，并且仿照此方案计算
    // left > right, 二者同时变为0
    // left = rigth, 计算当前有效字符串的长度，并记录字符串。
    // tc: O(n), sc: O(1)
public:
    int longestValidParentheses(string s) {
        // I.
        // int mxans = 0, n = s.length();
        // vector<int> dp(n, 0);
        // for (int i = 1; i < n; i++)
        // {
        //     if (s[i] == ')')
        //     {
        //         if (s[i - 1] == '(')
        //         {
        //             dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        //         } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
        //         {
        //             dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2]: 0) + 2;
        //         }
        //         mxans = max(mxans, dp[i]);
        //     }
        // }
        // return mxans;

        // II.
        // int maxans = 0;
        // stack<int> stk;
        // stk.push(-1); // 设定-1位置上有一个右括号
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (s[i] == '(')
        //     {
        //         stk.push(i);
        //     } else
        //     {
        //         stk.pop();
        //         if (stk.empty())
        //         {
        //             stk.push(i);
        //         } else {
        //             maxans = max(maxans, i - stk.top());
        //         }
        //     }
        // }
        // return maxans;

        int left = 0, right = 0, mxans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            } else
            {
                right++;
            }
            if (left == right)
            {
                mxans = max(mxans, 2 * right);
            } else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            } else
            {
                right++;
            }
            if (left == right)
            {
                mxans = max(mxans, 2 * left);
            } else if (left > right)
            {
                left = right = 0;
            }
        }
        return mxans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */


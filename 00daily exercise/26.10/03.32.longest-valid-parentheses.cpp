// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    // 显然以'('结尾的子串一定无效，dp为0
    // 然后我们从前往后遍历字符串，假设字符串为s
    // 1. s[i] = ')'且s[i - 1] = '(';
    //  dp[i] = dp[i - 2] + 2;
    // 2. s[i] = s[i - 1] = ')', 如果有s[i - dp[i - 1] - 1] = '('
    //     dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
    //  如果没有，则dp[i] = 0
    // 2应当如下理解：考虑倒数第二个')', 如果他是一个有效子串（subS)的一部分
    // 那么对于最后一个')', 他如果也有效，那就必须是更长有效子串的一部分
    // 他一定有一个对应的'(', 而且这个左括号一定在subS之前
    // 所以如果子串subS前恰好是'(', 就用2 + |subS|去更新dp[i]
    // 但是还是要考虑subS之前的有效子串，即dp[i - dp[i - 1] - 2]
    // |subS| = dp[i - 1]，另外，如果子串subS前不是'(', 
    // 则这个')'不是一个有效子串的结尾, dp[i] = 0
    // 于是答案就是max_i{dp[i]}
    // tc = sc = O(n)

    // II. 栈
    // 我们使用一个栈在遍历的时候统计最长有效括号的长度
    // 栈主要用来存放左括号，但是栈底要保存“最后一个没有被匹配的右括号的下标”
    // (这是为了处理边界情况【连续多个右括号造成的无效字符】，
    // 方便我们计算括号的长度)
    // 之后：
    // 1. 对于每个遇到的'(', 下标入栈
    // 2. 对于每个遇到的')', 弹出栈顶的左括号表示匹配了当前右括号
    //   2.1. 如果栈不为空，那么当然，右括号下标和栈顶元素的差就表示：
    //          "以该右括号为结尾的最长有效括号的长度"
    //   2.2. 如果栈为空，说明当前的右括号没有匹配，我们将其下标放入栈中
    //           更新栈底的“最后一个没有被匹配的右括号下标”
    // 栈在初始化的会后需要放一个值为-1的元素，保持统一
    // tc = sc = O(n)
    
    // III. 空间优化
    // 我们不使用栈，反而只使用两个计数器left/right统计左右括号
    // 如果left和right相等，计算当前有效字符串的长度，
    // 当right > left时，说明出现无效串，将二者同事变回0
    // 这种贪心方案考虑了当前字符下标结尾的有效括号长度
    // 二者一样多则计数，当右括号多的时候我们重新开始，
    // 于是这会漏掉左括永远多于右括号的情况，例如((), 
    // 这时我们无法计数
    // 但是我们也不需要开辟空间回归方法II, 我们只需要从左往右重复
    // 将判断条件改变即可：left > right, 则二者同时变回0，相等则计算长度
    // 显然这两次遍历就能涵盖所有情况
public:
    int longestValidParentheses(string s) {
        // I.
        // int maxans = 0, n = s.length();
        // vector<int> dp(n, 0);
        // for (int i = 1; i < n; i++) {
        //     if (s[i] == ')') {
        //         if (s[i - 1] == '(') {
        //             dp[i] = (i >= 2 ? dp[i - 2]: 0) + 2;
        //         } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
        //             dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        //         }
        //         maxans = max(maxans, dp[i]);
        //     }
        // }
        // return maxans;

        // II.
        // int maxans = 0;
        // stack<int> stk;
        // stk.push(-1);
        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] == '(') {
        //         stk.push(i);
        //     } else {
        //         stk.pop();  // 需要先出栈再判断
        //         if (stk.empty()) {
        //             // 栈空说明要直接更新最后一个右括号
        //             stk.push(i); 
        //         } else {    
        //             // 否则计算和之前最后一个未匹配左/右括号的坐标差
        //             // 结果即是以此右括号结尾的有效括号的长度
        //             maxans = max(maxans, i - stk.top() + 1);
        //         }
        //     }
        // }
        // return maxans;

        // III.
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
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


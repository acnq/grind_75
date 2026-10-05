/*
 * @lc app=leetcode.cn id=856 lang=cpp
 * @lcpr version=30204
 *
 * [856] 括号的分数
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
    // I. 分治
    // 我们设法把s分解为A + B或者(A)中的一种，具体区分方法如下：
    // 左括号为1，右括号-1，如果s的某个非空前缀对应的和为bal=0
    // 则这个前缀就是一个平衡串，如果这个前缀长度为s, 则应当分解为(A)
    // 的形式（注意s一定是平衡的）
    // 否则可以分解为A + B的形式，A为此前缀，s分解后，我们递归求解即可
    // |s|=2, 分数为1
    // tc = sc = O(n^2)

    // II. 栈
    // st记录平衡字符串目前为止的分数，开始前压入0，
    // 遍历s时：
    // 1. 遇到左括号，计算内部的子串A的分数，
    // 2. 遇到右括号，说明内部的A分数已经完成了计算，
    // 出栈保存在变量v中，如果v==0, 则子串A为空，(A) = 1
    // 否则(A)的分数就是2v， 然后我们将(A)的分数加到栈顶
    // 结束后栈顶元素即是s的分数
    // tc = sc = O(n)

    // III. 加法结合律
    // s的分数仅仅和'()'的深度有关，如果深度为bal, 则分数就是2^bal,
    // 统计所有的'()'的分数即可
    // tc: O(n), sc: O(1)
public:
    int scoreOfParentheses(string s) {
        // I.
        // if (s.size() == 2) {
        //     return 1;
        // }
        // int bal = 0, n = s.size(), len;
        // for (int i = 0; i < n; i++) {
        //     bal += (s[i] == '(' ? 1: -1);
        //     if (bal == 0) {
        //         len = i + 1;
        //         break;
        //     }
        // }
        // if (len == n) {
        //     return 2 * scoreOfParentheses(s.substr(1, n - 2));
        // } else {
        //     return scoreOfParentheses(s.substr(0, len)) + scoreOfParentheses(s.substr(len, n - len));
        // }
        
        // II.
        // stack<int> st;
        // st.push(0);
        // for (auto c: s) {
        //     if (c == '(') {
        //         st.push(0);
        //     } else {
        //         int v = st.top();
        //         st.pop();
        //         st.top() += max(2 * v, 1);
        //     }
        // }
        // return st.top();

        // III.
        int bal = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            bal += (s[i] == '(' ? 1 : -1);
            if (s[i] == ')' && s[i - 1] == '(') {
                res += 1 << bal;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "(())"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

// @lcpr case=start
// "(()(()))"\n
// @lcpr case=end

 */


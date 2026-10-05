/*
 * @lc app=leetcode.cn id=678 lang=cpp
 * @lcpr version=30204
 *
 * [678] 有效的括号字符串
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
    // dp[i][j]: s[i:j]是否为有效子串，0<=i<=j<=n;
    // 边界情况：
    // 1. n == 1: 只有s=='*'， 才算有效
    // 2. n == 2: 有效的有(), (*, *)和**
    // 3. n > 2: 只有满足如下条件之一才有dp[i][j] = true;
    //    3.1. s[i], s[j]分别为左右括号，或者至少一个为'*'
    //         则dp[i + 1][j - 1] = true => dp[i][j] = true;
    //    3.2. 存在k \in [i, j), s.t. dp[i][k] = dp[k + 1][j]
    //          均为true, 则dp[i][j] = true
    // 返回dp[0][n - 1]即可
    // tc: O(n^3), sc: O(n^2)

    // II. 栈
    // 我们需要两个栈分别存储左括号和星号，
    // 遇到'('和'*'则分别将下标入栈
    // 遇到')', 我们遵循优先和左括号匹配的原则：
    // 1. 左括号栈不为空，则左括号栈顶弹出元素
    // 2. 左括号栈空而星号不空，则星号栈顶弹出元素
    // 3. 二者都空，则返回false
    // 遍历完字符串之后，如果两个栈都还有元素，还需要将*和(匹配
    // 注意左括号必须出现在星号之前，分别弹出栈顶元素比较下标
    // 遇到左括号下标较大则直接返回false
    // 最终判断左括号栈是否为空即可，星号栈不空没关系，都可看做空串
    // 左括号栈不空则返回false, 否则true
    // tc = sc = O(n);

    // III. 贪心
    // 我们维护未匹配的左括号数量可能的最大值和最小值
    // 遍历时：
    // 1. 遇到左括号，最大最小值均+1；
    // 2. 遇到右括号，最大最小值均-1；
    // 3. 遇到星号，最小值-1(小到0则不变确保非负)，最大值+1;
    // 如果最大值变成负数，直接返回false(说明右括号太多了)
    // 遍历结束时，最小值为0，s才是有效的
    // 注意不能允许最小值为负数，免得左括号错误的抵消，
    // 例如'*(', 如果允许最小值为负数，会被错误的判断为有效
    // tc: O(n), sc: O(1)
public:
    bool checkValidString(string s) {
        // I.
        // int n = s.size();
        // vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));
        //
        // for (int i = 0; i < n; i++) {
        //     if (s[i] == '*') {
        //         dp[i][i] = true;
        //     }
        // }
        //
        // for (int i = 1; i < n; i++) {
        //     char c1 = s[i - 1];
        //     char c2 = s[i];
        //     dp[i - 1][i] = (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
        // }
        //
        // for (int i = n - 3; i >= 0; i--) {
        //     char c1 = s[i];
        //     for (int j = i + 2; j < n; j++) {
        //         char c2 = s[j];
        //         if ((c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*')) {
        //             dp[i][j] = dp[i + 1][j - 1];
        //         }
        //         for (int k = i; k < j && !dp[i][j]; k++) {
        //             dp[i][j] = dp[i][k] && dp[k + 1][j];
        //         }
        //     }
        // }
        // return dp[0][n - 1];
    
        // II.
        // stack<int> leftStack;
        // stack<int> asterStack;
        // int n = s.size();
        //
        // for (int i = 0; i < n; i++) {
        //     char c = s[i];
        //     if (c == '(') {
        //         leftStack.push(i);
        //     } else if (c == '*') {
        //         asterStack.push(i);
        //     } else {
        //         if (!leftStack.empty()) {
        //             leftStack.pop();
        //         } else if (!asterStack.empty()) {
        //             asterStack.pop();
        //         } else {
        //             return false;
        //         }
        //     }
        // }
        //
        // while (!leftStack.empty() && !asterStack.empty()) {
        //     int leftIdx = leftStack.top();
        //     leftStack.pop();
        //     int asterIdx = asterStack.top();
        //     asterStack.pop();
        //     if (leftIdx > asterIdx) {
        //         return false;
        //     }
        // }
        //
        // return leftStack.empty();
    
        // III.
        // int minCount = 0, maxCount = 0;
        // int n = s.size();
        // for (int i = 0; i < n; i++) {
        //     char c = s[i];
        //     if (c == '(') {
        //         minCount++;
        //         maxCount++;
        //     } else if (c == ')') {
        //         minCount = max(minCount - 1, 0);
        //         maxCount--;
        //         if (maxCount < 0) {
        //             return false;
        //         }
        //     } else {
        //         minCount = max(minCount - 1, 0);
        //         maxCount++;
        //     }
        // }
        // return minCount == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "(*)"\n
// @lcpr case=end

// @lcpr case=start
// "(*))"\n
// @lcpr case=end

 */


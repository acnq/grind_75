/*
 * @lc app=leetcode.cn id=1871 lang=cpp
 * @lcpr version=30204
 *
 * [1871] 跳跃游戏 VII
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
    // I: DP + 前缀和
    // f(i): 能否从0到达位置i;
    // s[i] = 1: f(i) = false;
    // s[i] = 0: 枚举j, 最后是j跳到i, j \in [i - maxJ, i-minJ]
    //           j >=0, 故只要\exists j s.t. f(j) = True 即可
    // f(i) = any(f(j)), s.t. j \in [i - maxJ, i - minJ] && j>=0
    // 答案为f(n - 1), 但是DP的t.c. = O(n^2), 超时
    // 记[li, ri] = i状态下j对应的位置，
    //    一般为[i - maxJ, i - minJ]去除越界部分
    // 记True = 1, False = 0
    // f(i) = 1, <=> s[i] = 0 && \sum_{j=li}^{ri} f(j) 不为0
    // 记pre(i) = \sum_{j=0}^i f(i)
    // \sum_{j=li}^{ri} f(j) = pre(ri) - pre(li - 1)
    // 所以我们可以在O(1)内状态转移，t.c. = O(n)
    // 起点f(0) = T = 1;
    // 从i=minJ开始，这样ri >= 0总成立，只需特殊处理li即可
    // sc = tc = O(n)
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);
        f[0] = 1;
        // 从i = minJ开始，预处理[0, minJ]
        for (int i = 0; i < minJump; i++) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; i++) {
            int li = i - maxJump, ri = i - minJump;
            if (s[i] == '0') {
                int total = pre[ri] - (li <= 0 ? 0 : pre[li - 1]);
                f[i] = (total != 0);
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "011010"\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// "01101110"\n2\n3\n
// @lcpr case=end

 */


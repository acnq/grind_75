/*
 * @lc app=leetcode.cn id=1900 lang=cpp
 * @lcpr version=30204
 *
 * [1900] 最佳运动员的比拼回合
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
    // 极难又极有意义的一道题
    // I. 记忆化搜索 
    // F(n, f, s)：
    // 表示还剩余n个人，两名最佳运动员分别是一排中从左到右的f和s名运动员时, 他们比拼的最早回合数
    // 仿上，G(n, f, s)表示他们比拼的最晚回合数
    // F(n, f, s) = F(n, s, f): 交换两名最佳运动员位置不会有变化
    // F(n, f, s) = F(n, n + 1 - s, n + 1 - f): 整体翻转队列不会有任何变化
    // 如此一来，我们直接设定F(n, f, s)中f < s, f在左侧，s可以在左中右。
    // 设计ST方程：
    // 1. s在左：
    //      f左侧剩下[0, f - 1]名运动员，设为i
    //      f和s中间剩下[0, s - f - 1]名运动员, 设为j
    //      这一轮之后，f和s的位置位于i + 1, i + j + 2, 剩余总数\floor{(n + 1) / 2}
    // 故 F(n, f, s) = min_{i\in[0, f - 1], j \in [0, s - f - 1] F(\floor{(n + 1) / 2}, i + 1, i + j + 2)} + 1
    // 2. s在中，和1完全相同
    // 3. s在右则比较复杂，分三种情况讨论
    //      3.1. f恰好和s比拼，f + s = n + 1, F(n, f, s) = 1
    //      假设与s比拼的是s' = n + 1 - s, 按照f <> s'分类
    //      3.2. f < s'
    //          f左侧剩下[0, f - 1]人, 设为i
    //          f,s'中间剩下[0, s' - f - 1], 设为j
    //          s'输给s
    //          s' 与 s中间的n - 2s', 如果是偶数，剩下(n -  2s') / 2人；
    //                               如果是奇数，剩下(n - 2s' + 1) / 2 人；
    //                               划归为\floor{(n - 2s' + 1) / 2}
    //      故F(n, f, s) = (\min_{i\in[0, f - 1], j \in [0, s' - f - 1] F(\floor{(n + 1) / 2}, i + 1, i + j + \floor{(n - 2s' + 1) / 2} + 2)}) + 1
    //      3.3. f > s', 整体翻转：f->n + 1 - s, s->n + 1 - f, f < s 且 f < s', 划归为3.2.
    // 相应的G改成max即可。
    // 保证f < s的情况下，特殊情况只有f > s' = n + 1 - s, 注意到f在中右，s在右的情况
    // 都有f + s > n + 1, 所以我们只需要在遇到这种情况时，执行变化2：F(n, f, s) = F(n, n + 1 - s, n + 1 - f)即可
public:
    int F[30][30][30], G[30][30][30]; // 按提示：2 <= n <= 28
    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) {
            return {F[n][f][s], G[n][f][s]};
        }
        if (f + s == n + 1) {
            return {1, 1};
        }
        // F(n, f, s) = F(n, n + 1 - s, n + 1 - f)
        if (f + s > n + 1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }

        int early = INT_MAX, late = INT_MIN;
        int n_half = (n + 1) / 2;

        if (s <= n_half) {
            // 在左侧或者中间
            for (int i = 0; i < f; i++) {
                for (int j = 0; j < s - f; j++) {
                    auto [x, y] = dp(n_half, i + 1, i + j + 2);
                    early = min(early, x);
                    late = max(late, y);
                }
            }
        } else {
            // s 在右侧
            // s'
            int sp = n + 1 - s;
            int mid = (n - 2 * sp + 1) / 2;
            for (int i = 0; i < f; i++) {
                for (int j = 0; j < sp- f; j++) {
                    auto [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    early = min(early, x);
                    late = max(late, y);
                }
            }
        }
        return {F[n][f][s] = early + 1, G[n][f][s] = late + 1};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));

        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer); 
            // 保证f在前
        }
        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n1\n5\n
// @lcpr case=end

 */


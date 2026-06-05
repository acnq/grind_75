/*
 * @lc app=leetcode.cn id=3753 lang=cpp
 * @lcpr version=30204
 *
 * [3753] 范围内总波动值 II
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
    // I. 数位DP
    // 和04.3751中的第二种解法一样，这里就省略了
    // II. 自底向上DP
    // 与解法I相同，只是我们使用自底向上的方法
public:
    using ll = long long;

    struct State {
        // 封装了I中每次函数的输入/输出
        int prev, curr, tight, lead;
        // tight 即为 isLimit 表示是否到达x的前缀
        // lead 即为 isLeading 表示是否在前缀0的位上
        ll cnt, sum;
    };

    ll solve(ll num) {
        // 和I的solve意涵相同，实现不同
        if (num < 100) {
            return 0;
        }
        string s = to_string(num);
        int n = s.size();

        vector<State> currStates;
        // 数位10表示存在前导0时的无效状态
        currStates.push_back({10, 10, 1, 1, 1, 0});
        // 相当于dfs(0, -1, -1, true, true)
        // cnt=1: 当前路径数字个数初始化为1，sum=0: 还未有峰谷差生
        for (int pos = 0; pos < n; pos++) {
            int limit = s[pos] - '0';
            ll cnt[2][2][11][11] = {0};
            ll sum[2][2][11][11] = {0};

            for (const auto& st: currStates) {
                int maxDigit = st.tight ? limit: 9;
                for (int digit = 0; digit <= maxDigit; digit++) {
                    int newLead = st.lead && (digit == 0);
                    int newPrev = st.curr;
                    int newCurr = newLead ? 10 : digit;
                    int newTight = st.tight && (digit == maxDigit);

                    ll add = 0;
                    // 已有三位有效数字才计算波动（prev, curr都有效，且不是前导零）
                    if (!newLead && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // 收集合法状态
            vector<State> nextStates;
            for (int tight = 0; tight < 2; tight++) {
                for (int lead = 0; lead < 2; lead++) {
                    for (int prev = 0; prev <= 10; prev++) {
                        for (int curr = 0; curr <= 10; curr++) {
                            ll c = cnt[tight][lead][prev][curr];
                            ll s = sum[tight][lead][prev][curr];
                            // 如果当前状态有效，则进入下一轮计算
                            if (c != 0) {
                                nextStates.push_back({prev, curr, tight, lead, c, s});
                            }
                        }
                    }
                }
            }

            currStates.swap(nextStates);
        }

        // 累加所有合法状态的波动值之和
        ll ans = 0;
        for (const auto& st: currStates) {
            ans += st.sum;
        }
        return ans;
    }


    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 120\n130\n
// @lcpr case=end

// @lcpr case=start
// 198\n202\n
// @lcpr case=end

// @lcpr case=start
// 4848\n4848\n
// @lcpr case=end

 */


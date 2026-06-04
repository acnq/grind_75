/*
 * @lc app=leetcode.cn id=3751 lang=cpp
 * @lcpr version=30204
 *
 * [3751] 范围内总波动值 I
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
    // I. 枚举
    // 直接枚举[num1, num2]的每个数字，计算每个数字的波动值，
    // 累加所有数的波动值即为答案
    // tc: O(num2 lognum2), sc: O(log num2)

    // II. 数位DP
    // 记solve(x): [0, x]内所有数字的波动总值
    // ans = solve(num2) - solve(num1 - 1)
    // 我们用记忆化搜索实现solve(x)的计算，记：
    // pos: 正在处理的数位（从做到右）
    // prev: pos - 2对应的数字, 不存在置为-1
    // curr: pos - 1对应的数字, 不存在置为-1
    // isLimit: 表示是否之前的数位和num对应的前缀相同，
    //          如果true，则说明当前数字不能超过num[pos],
    //          否则0-9均可
    // isLeading: 是否处于前导零状态（还没有出现非0数）
    // DFS返回cnt和sum:
    // cnt: 当前状态出发能构成的合法数字的个数
    // sum: 当前状态出发，这些合法数字后续还会产生的波动值总和
    // 分别用memo_cnt[pos][prev][curr]和memo_sum[pos][prev][curr]
    // 统计，初始化为-1，cur, prev不存在则不存储记忆
    // 更新轨则：
    // 1. 计算可枚举范围：如果数字有上限，isLimit=true,
    //                  枚举[0, num[pos]], 否则[0, 9]
    // 2. 在范围内枚举数字digit, 试填充并讨论：
    //      1.首先更新前导零状态newLead;
    //      2.更新prev和curr
    //      3. 递归调用dfs(pos + 1, cur, digit,)得到subCnt, subSum
    // 3. 计算当前digit带来的波动贡献：
    //      1. 已有三位数字才开始检查是否构成峰谷
    //      2. prev < cur \and cur > digit， 或者 
    //          prev > cur \and cur < digit, 
    //         需要将subCnt累加到sum中（每个前缀都额外多一个波动点）
    // 4. 累加子状态的值，返回结果(cnt, sum)
    // 边界：
    // pos = n: 到达终点，返回(1, 0)
    // 只能构成x本身这个合法数字，而且
    // 入口：
    // dfs(0, -1, -1, true, true);
    // 剪枝处理：num < 100 直接返回0
    // ans = solve(num)[sum]
    // tc: O(D^3 log num2) D: 位数，这里是10
    // sc: O(D^2 log num2) 两个数组
public:
    int totalWaviness(int num1, int num2) {
        // I.
        // auto getWaviness = [](int x) -> int {
        //     string s = to_string(x);
        //     int waviness = 0;

        //     for (size_t i = 1; i < s.size() - 1; i++) {
        //         bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
        //         bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
        //         if (isPeak || isValley) {
        //             waviness++;
        //         }
        //     }

        //     return waviness;
        // };

        // int total = 0;
        // for (int i = num1; i <= num2; i++) {
        //     total += getWaviness(i);
        // }

        // return total;

        // II.
        using ll = long long;
        // 计算[0, num]内的波动总和
        auto solve = [&](ll num) -> ll {
            // 少于三个数字波动值为0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();

            // 记忆化数组
            ll memo_cnt[16][10][10];
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            auto dfs = [&](auto &&self, int pos, int prev, int curr, bool isLimit, bool isLeading) -> pair<ll, ll> {
                // 结束出口
                if (pos == n) {
                    return {1, 0};
                }
                // 没有上限限制且不包含前导零才记忆化
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
                    }
                }

                // 计算当前条件下的方案数和波动值
                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0': 9;
                for (int digit = 0; digit <= up; digit++) {
                    bool newLeading = isLeading && (digit == 0);
                    int newPrev = curr;
                    int newCurr = newLeading ? -1: digit;
                    auto [subCnt, subSum] = self(self, pos + 1, newPrev, newCurr, isLimit && (digit == up), newLeading);
                    // 不包含前导0彩计算波动值
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // 峰谷更新波动
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }
                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(dfs, 0, -1, -1, true, true);
            return totalSum;
        };

        return (int)(solve(num2) - solve(num1 - 1));
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


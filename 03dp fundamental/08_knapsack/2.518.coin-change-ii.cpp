/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30204
 *
 * [518] 零钱兑换 II
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
    // I. dp
    // dp[x]: 金额=x的硬币组合总数
    // dp[0] = 1
    // 对于面额为coin的硬币，如果存在dp[i - coin], 那么在该组合中增加一个面额
    // 为coin的硬币，即可得到一种金额之和等于i的硬币组合
    // 遍历coins, 设每个元素为coin:
    //      遍历i\in[coin, amount], dp[i] += dp[i - coin]
    // ans = dp[amount]
    // i从coin开始保证顺序不会重复
    // tc: O(amount * n); sc: O(amount);
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1), valid(amount + 1);
        dp[0] = 1;
        valid[0] = 1;
        for (int& coin: coins) {
            for (int i = coin; i <= amount; i++)
            {
                valid[i] |= valid[i - coin];
            }
        }

        if (!valid[amount])
        {
            return 0;
        }
        for (int& coin: coins) {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */


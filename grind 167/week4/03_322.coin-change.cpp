/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
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
public:
    // 优化问题：
    // min_x\sum_{i=0^{n-1}}x_i s.t. \sum_{i=0}^{n-1} x_i * c_i = S
    // S：总金额，c_i，i枚硬币的面值；x_i，面值为c_i的硬币数量， x_i \in [0, S/c_i]

    vector<int> count; // 用于存储已经计算过的F(S), S从0到n-1, 所以下面要-1
    int dp(vector<int>& coins, int rem) {
        if(rem < 0) return -1;
        if (rem == 0)
        {
            return 0;
        }
        if (count[rem - 1] != 0)
        {
            return count[rem - 1];
        }
        int min = INT_MAX;
        for (int coin: coins) {
            int res = dp(coins, rem-coin);
            if (res >= 0 && res < min)
            {
                min = res + 1;
            }
        }
        count[rem - 1] = min == INT_MAX ? -1 : min;
        return count[rem - 1];
    }
    int coinChange(vector<int>& coins, int amount) {
        // 1. 记忆化搜索：
        // F(S)：组成金额S所需的最少硬币数量
        // [c_0, ..., c_{n - 1}]: 可选的n枚硬币面额
        // 假设最后一枚硬币的面值是C: F(S) = F(S - C) + 1
        // 枚举c_0, ..., c_{n-1}，选择最小值，则
        // F(S) = \min_{i=0,...,n-1} F(S - c_i) + 1, s.t. S-c_i >= 0
        // F(0) = 0, F(S) = -1; if n = 0
        if (amount < 1)
        {
            return 0;
        }
        count.resize(amount);
        return dp(coins, amount);

        // 2. 动态规划
        // 自底向上
        // F(i) = min_{j=0,...,n-1}F(i - c_j) + 1
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < (int)coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */


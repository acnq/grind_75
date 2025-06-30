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
    // 建模优化问题：min_x \sum_{i=0}^{n-1}x_i s.t. \sum_{i=0}^{n-1} x_i * c_i = S
    // x_i \in [0, S / c_i]
    // I. 记忆化搜索
    // 定义F(S): 组成金额S所需的最少硬币数；[c_0:c_{n-1}]: 可选的n枚硬币面额
    // F(S) = F(S - C) + 1, 枚举最有一个可能得硬币数
    // F(S) = min_{i \in [0, (n-1)]} F(S - c_i) + 1, s.t. S - c_i \leq 0
    // F(0) = 0, F(S) = -1, n = 0;
    // tc: O(Sn) S金额，n面额数；sc: O(S) 
    
    // II. DP
    // F(i) = min_{j \in [0, n-1]}F(i - c_j) + 1
    // tc: O(Sn), tc: O(S)
public:
    // I.
    vector<int> count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0)
        {
            return -1;
        }
        if (rem == 0)
        {
            return 0;
        }
        if (count[rem - 1] != 0)
        {
            return count[rem - 1];
        }
        int min = INT_MAX;
        for (int coin : coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < min)
            {
                min = res + 1;
            }
        }
        count[rem - 1] = min == INT_MAX ? -1 : min;
        return count[rem - 1];
    }
    int coinChange(vector<int>& coins, int amount) {
        // I.
        // if (amount < 1)
        // {
        //     return 0;
        // }
        // count.resize(amount);
        // return dp(coins, amount);

        // II.
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < (int)coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
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


/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30204
 *
 * [188] 买卖股票的最佳时机 IV
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
    // DP
    // 同样需要采用一系列变量来存储“买入”和“卖出”状态
    // buy[i][j]: 第i天恰好j笔交易，且手上有一只股票时的最大利润
    // sell[i][j]: 第i天恰好进行j笔交易，且手上没有股票时的最大利润
    // buy[i][j] = max{buy[i - 1][j], sell[i - 1][j] - prices[i]} (股票是否是第i天买入的)
    // sell[i][j] = max{sell[i - 1][j], buy[i - 1][j - 1] + prices[i]} (是否是第j天卖出的)
    // ans = max_k{sell[n - 1][0:k]}
    // buy[0][0] = -prices[0], 而buy[0][1:k]均不合法，用INT_MIN表示
    // sell[0][0] = 0, sell[0][1:k]也不合法，设为INT_MIN
    // sell[i][0] = 0
    // n天最多进行\floor{n / 2}交易，所以k = min(k, \floor{n / 2})
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i < k; i++)
        {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }
        
        for (int i = 1; i < n; i++)
        {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
        // 可以压缩i维度，不过既然没有报错内存不够，那么就这样吧
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */


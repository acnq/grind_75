// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=30204
 *
 * [714] 买卖股票的最佳时机含手续费
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
    // 感觉和初始问题的区别在于
    // 因为有交易费用的约束，在特殊情况下次数更少的交易将会赚得更多
    // dp[i]第i天获得的最大收益，
    // dp[i][0]: 持股，dp[i][1]: 不持股
    // dp[i][0]: 或者第i - 1天已经持有 <- dp[i - 1][0]; 
    //           或者第i天买入 <- dp[i - 1][1] - prices[i]
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
    // dp[i][1]: 或者第i - 1天已经不持股了<-dp[i - 1][1]，
    //           或者第i - 1天卖出的 <- dp[i - 1][0] + prices[i] - fee
    // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee)
    // 答案：max(f[n - 1][1], f[n - 1][0])
    // bc: dp[0][0]: -prices[0], dp[0][1] = 0

    // 内存不够，要压缩i这个纬度
    // dp[i]之和dp[i - 1]有关，那么只需要两个元素都可以
    
    // II. 贪心
    // 手续费买入时计算
    // buy: 最大化收益时，如果我们手上拥有一支股票，它的最低买入价格
    // buy i= prices[0] + fee
    // 遍历到第i天：
    // prices[i] + fee < buy，与其使用buy的价格购买，不如以prices[i] + fee购入，更新buy
    // prices[i] > buy, 直接卖出，获得prices[i] - buy的收益，但是可能不是最优（未来可以继续上涨）
    //                  为此，设计反悔操作：看做当前手上拥有一支买入价格为prices[i]的股票
    //                  buy 更新为prices[i], 这样如果下一天股价继续上升，收益辩伪prices[i + 1] - prices[i]
    //                  加上prices[i] - buy的收益，而这恰好等于这一天不进行任何操作，下一天卖出的收益
    // else:            prices[i] \in [buy - fee, buy], 价格没有低到可以放弃当前买入，也没有高到可以卖出获益，不做任何操作
    //
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int ans;
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2));
        // dp[0][0] = -prices[0];
        // dp[0][1] = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        // }
        // return dp[n - 1][1];
        // 方法没错，但是内存不够，要压缩
        // int ans;
        // int n = prices.size();
        // int hold = -prices[0], unhold = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     int prev_h = hold, prev_u = unhold;
        //     hold = max(prev_h, prev_u - prices[i]);
        //     unhold = max(prev_u, prev_h + prices[i] - fee);
        // }
        // return unhold;
        // 写的有点久，但是大部分时间都用在验证上，1h解决

        // II.
        int n = prices.size();
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] + fee < buy)
            {
                buy = prices[i] + fee;
            } else if (prices[i] > buy)
            {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */


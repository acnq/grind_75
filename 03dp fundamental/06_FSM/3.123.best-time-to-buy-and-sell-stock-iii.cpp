/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30204
 *
 * [123] 买卖股票的最佳时机 III
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
    // 枚举我们可能的状态
    // 1. 未进行任何操作；2. 只进行一次买入；3. 一次买入卖出：完成一笔交易
    // 4. 完成了第二笔买入； 5. 完成全部两笔交易
    // 状态1利润总为0，我们将后面四种状态获得的最大利润分别记为buy1, sell1, buy2, sell2
    // buy1 = max{buy1', -prices[i]} ('表示i-1天)
    // sell1 = max{sell1', buy1' + prices[i]}
    // buy2 = max{buy2', sell1' - prices[i]}
    // sell2 = max{sell2', buy2' + prices[i]}
    // bc: (i = 0) 时： buy1 = -prices[0], sell1 = 0, buy2 = -prices[0]; sell2=0
    // 最终答案总是sell2
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; i++)
        { // 这里可以把prev保存下来，也可以不用，
            // 因为延迟一步取最大值相当于当天进行一次买入卖出，
            // 收益为0， 并不影响
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


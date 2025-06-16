/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30204
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        // int max_profit = 0;
        // int N = prices.size();
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = i + 1; j < N; j++)
        //     {
        //         int profit = prices[j] - prices[i];
        //         if (profit > max_profit)
        //         {
        //             max_profit = profit;
        //         }
        //     }    
        // }
        
        // return max_profit;
        /* the method above will timeout */ 
        /* 以上方法会超时*/
        int max_profit = 0;
        int N = prices.size();
        int min_price = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            if (prices[i] - min_price > max_profit)
            {
                max_profit = prices[i] - min_price;
            }
        }
        
        return max_profit;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30204
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    // I. DP
    // 想半天想不出来，感觉思路一直卡在多看几步设计买入策略
    // 但是没有想到要在内部存储第二个维度，表示是否在冷冻期内，这样读写头的判断会方便很多
    // 思路：
    // f[i]: 第i天结束之后的“累计最大收益”，并划分三个不同的状态："状态机“
    //  目前持股：f[i][0] (持股的情况下不可能进入冷冻期，因为不能参与多笔交易)
    //  不持股，且在冷冻期：f[i][1]
    //  不持股，不在冷冻期：f[i][2]
    //  规范：第i天结束之后处于冷冻期表示第i + 1天无法买入股票
    // 1. f[i][0]: 目前持有的一只股票可以第i-1天已经持有，<- f[i - 1][0]
    //                              也可以第i天买入，那么i-1天不能持股，也不能在冷冻，<- f[i - 1][2] - prices[i]
    //    综上：f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i])
    // 2. f[i][1]: 当天卖出了股票，故i-1必须持有一支股票，故只有下述情况：
    //      f[i][1] = f[i - 1][0] + prices[i]
    // 3. f[i][2]: 当天什么操作都没有做，i - 1没有持股，根据那天有无处于冷冻期，
    //      处于<- f[i - 1][1], 不处于<-f[i - 1][2]
    //      f[i][2] = max(f[i - 1][1], f[i - 1][2])
    // 答案：max(f[n - 1][0], f[n - 1][1], f[n - 1][2])
    // 其实f[n - 1][0]肯定不需要比较，因为如果最后一天还持有股票则不应纳入计算
    // bc: f[0][0] = -prices[0], f[0][1] = f[0][2] = 0
    // 开始感觉到难度了，DP题单中第一道没有思路的中等题TAT
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }

        int n = prices.size();
        // f[i][0]： 持股的最大收益
        // f[i][1]:  不持股且处于冷冻期的最大收益
        // f[i][2]:  不持股且不在冷冻期的最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


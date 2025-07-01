/*
 * @lc app=leetcode.cn id=983 lang=cpp
 * @lcpr version=30204
 *
 * [983] 最低票价
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
    // I. 记忆化搜索(日期变量)
    // dp(i): 第i天开始到一年结束，需要花费的钱, 这需要从后往前递归
    // 对一年中的任意一天：
    // 如果不是必须出行的一天，贪心的选择不买，dp(i) = dp(i + 1)
    // 如果是必须出行的一天，可以考虑三种选择，如果购买了j天通行证，接下来j-1天就不再需要了
    // 只要考虑i+j天及以后，
    // dp(i) = min{cost(j) + dp(i + j)}, j \in {1, 7, 30}
    // ans = dp(1)

    // II. 记忆化搜索（窗口变量）
    // 方法一会计算很多不用出行的日期，而这些可以直接跳过的
    // dp(i): 第days[i]天到一年结束需要的最小花费
    // 令j_1是满足days[j_1] >= days[i] + 1的最小下标，j_7 = min(j) s.t. days[j_7] >= days[i] + 7
    // j_30 = min(j) s.t. days[j_30] >= days[i] + 30
    // 直接有
    // dp(i) = min(dp(j_1) + costs[0], dp(j_7) + costs[1], dp(j_{30}) + costs[2])
public:
    // I.
    // unordered_set<int> dayset;
    // vector<int> costs;
    // int memo[366] = {0};

    // int dp(int i) {
    //     if (i > 365)
    //     {
    //         return 0;
    //     }
    //     if (memo[i] != -1)
    //     {
    //         return memo[i];
    //     }
    //     if (dayset.count(i))
    //     {
    //         memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
    //     } else
    //     {
    //         memo[i] = dp(i + 1);
    //     }
    //     return memo[i];
    // }

    // II.
    vector<int> days, costs;
    vector<int> memo;
    int durations[3] = {1, 7, 30};

    int dp(int i) {
        if (i >= days.size())
        {
            return 0;
        }
        if (memo[i] != -1)
        {
            return memo[i];
        }
        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++)
        {
            while (j < days.size() && days[j] < days[i] + durations[k])
            {
                j++;
            }
            memo[i] = min(memo[i], dp(j) + costs[k]);
        }
        return memo[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // I.
        // this->costs = costs;
        // for (int d: days) {
        //     dayset.insert(d);
        // }
        // memset(memo, -1, sizeof(memo));
        // return dp(1);

        // II.
        this->days = days;
        this->costs = costs;
        memo.assign(days.size(), -1);
        return dp(0);
    }

    
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,6,7,8,20]\n[2,7,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10,30,31]\n[2,7,15]\n
// @lcpr case=end

 */


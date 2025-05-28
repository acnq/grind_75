/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30204
 *
 * [746] 使用最小花费爬楼梯
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
    // f[i]: 到达下标为i的台阶所需要的最小花费
    // f[i] = min(f[i - 1] + cost[i -1], f[i - 2] + cost[i - 2])
    // f[1] = f[0] = 0;
    // res = f[n + 1];
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1, 0);
        if (n == 0 || n == 1)
        {
            return 0;
        }
        for (int i = 2; i <= n; i++)
        {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */


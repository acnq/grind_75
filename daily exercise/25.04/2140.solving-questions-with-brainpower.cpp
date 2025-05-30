/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 * @lcpr version=30204
 *
 * [2140] 解决智力问题
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
    // dp[i]: 前i道题目可以获得的最高分数
    // 不解决i题：dp[i] = dp[i - 1];
    // 解决i题：dp[i] = points[i] + max(0, max_{j\in[0, i-1], j + brainpower[j] < i} dp[j])
    //          或者前面的题目都没解决，要么上一道题目对应的冷冻期结束
    // 但是这样是O(n^2), 不合题意

    // dp的本质：无后效性
    // dp[i]: 第i道及以后得题目能获得的最高分数
    // 不解决： dp[i] = dp[i + 1];
    // 解决： dp[i] = points[i] + dp[i + brainpower[i] + 1]
    //       只能解决下标>i+brainpower[i]的题目们，当然i>=n => dp[i] = 0
    // i.e. dp = max(dp[i + 1], points[i] + dp[i + brainpower[i] + 1]), for(i=n:1)
    // 考虑dp[i*] = 0, \forall i* >= n;
    // 修改为：
    //  dp = max(dp[i + 1], points[i] + dp[min(n, i + brainpower[i] + 1)]), for(i=n:1)
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1); // dp[i]: 第i道及以后得题目能获得的最高分数
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);

        }
        return dp[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,2],[4,3],[4,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3],[4,4],[5,5]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1751 lang=cpp
 * @lcpr version=30204
 *
 * [1751] 最多可以参加的会议数目 II
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

#include <memory> // ranges
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. DP + 二分
    // 本质就是背包问题
    // dp[i][j]: 前i个会议中参加j个会议的最大价值和，
    // 第i个会议选择不参加，dp[i][j] = dp[i - 1][j]
    // 第i个会议选择参加，[1, start_i)选择j-1个会议参加，然后[startDay_i, endDay_i]
    //   参加第i个会议，假设[1, start_i)有p个会议可以参加，故dp[i][j] = dp[p][j - 1] + value_i;
    // 综上：dp[i][j] = max(dp[i - 1][j], dp[p][j - 1] + value_i)
    // 给定时间t, 通过二分查找找到结束时间早于t的会议数目，从小到大依次枚举(i, j)，最终结果dp[n][k]
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        sort(events.begin(),events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < n; i++) {
            int p = lower_bound(events.begin(), events.end(), events[i][0], [](const vector<int>& e, int value) {
                return e[1] < value;
            }) - events.begin();
            for (int j = 1; j <= k; j++) {
                dp[i + 1][j] = max(dp[i][j], dp[p][j - 1] + events[i][2]);
            }
        }
        return dp[n][k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,4],[3,4,3],[2,3,1]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,4],[3,4,3],[2,3,10]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[2,2,2],[3,3,3],[4,4,4]]\n3\n
// @lcpr case=end

 */


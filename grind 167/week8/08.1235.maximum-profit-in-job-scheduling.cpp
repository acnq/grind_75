/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 * @lcpr version=30204
 *
 * [1235] 规划兼职工作
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
    // 动态规划 + 二分查找
    // dp[i] 表示前i份兼职工作可以获得的最大报酬
    // dp[0] = 0
    // dp[i] = max(dp[i - 1], dp[k] + profit[i - 1]);
    // k: 满足结束时间小于等于i-1份开始时间的兼职工作索引
    // 不选择当前的jobs[i-1]：继承dp[i-1]
    // 选择当前的jobs[i-1]: 当前工作的profit, 前k个工作累计的profit
    //   而这里的前k个工作的结束时间，要确保小于等于当前工作的开始时间 
    // 可以通过二分查找获得
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++)
        {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
            return job1[1] < job2[1]; // 按照结束时间排序
        });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1]; // st 接受jobs[i-1][0]
            }) - jobs.begin();
            // 这里dp[i]表示0:i-1份，右移了一个单位，所以k返回的是第一个结束时间大于当前
            // 开始时间的元素，k-1就是利当前工作最近，且不满足结束时间大于当前工作开始时间
            // 的工作，k-1是满足的条件，dp[i]代表前i-1个工作，dp[k]代表k-1个工作
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,4]\n[5,6,4]\n
// @lcpr case=end

 */


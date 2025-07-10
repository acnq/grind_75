/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 * @lcpr version=30204
 *
 * [3439] 重新安排会议得到最多空余时间 I
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
    // I. 贪心 + 前缀和
    // 贪心：合并就是最优子结构
    // 对k个会议平移，最多可以将k + 1个空余时间段合并。
    // 令合并的第一个空余时间开始时间为left, 最后一个空余时间段结束时间为right
    // 合并的k + 1个空余时间段的总长=总时间间隔(left - right) - k个会议的时间总长
    // 预计算n个会议的时间前缀和sum, 方便计算相邻k个会议的时间总长，枚举最右边的会议i,
    // i >= k - 1, k个相邻会议区间[i - k + 1, i], 计算如下
    // 1. k个会议的总长sum[i + 1] - sum[i - k + 1]
    // 2. 合并第一个空余时间段的开始时间：left_i = {0              if i <= k - 1
    //                                          {endTime[i - k] else 
    // 3. 最后一个空余时间段的结束时间：right_i = {eventTime        if i = n - 1
    //                                         {startTIme[i + 1] else
    // 那么合并后总长 = right_i - left_i - (sum[i + 1] - sum[i - k + 1]), 最终返回所有枚举结果的最大值

    // II. 贪心 + 滑窗
    // 用滑窗计算k个相邻会议的时间总长，t来计算窗口内会议的时间总长，依次将会议i加入窗口
    //  1. i加入窗口，t = t + endTime[i] - startTime[i]
    //  2. 仿照方法I计算left_i, right_i, 合并的空余时间总长为right_i - left_i - t
    //  3. 会议数量=k, i.e. i >= k - 1, 要将会议i - k + 1移除，t = t - (endTime[i - k + 1] - startTime[i - k + 1])
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // I.
        // int n = startTime.size(), res = 0;
        // vector<int> sum(n + 1);
        // for (int i = 0; i < n; i++) {
        //     sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        // }
        // for (int i = k - 1; i < n; i++) {
        //     int right = i == n - 1 ? eventTime : startTime[i + 1];
        //     int left = i == k - 1 ? 0 : endTime[i - k];
        //     res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        // }
        // return res;

        // II.
        int n = startTime.size(), res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, right - left - t);
            if (i >= k - 1) 
            {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n1\n[1,3]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n[0,2,9]\n[1,4,10]\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n[0,1,2,3,4]\n[1,2,3,4,5]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3440 lang=cpp
 * @lcpr version=30204
 *
 * [3440] 重新安排会议得到最多空余时间 II
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
    // I. 贪心
    // 因为最多有一个会议可以移动，枚举当前平移的会议i
    // 两种情况，
    // 1. 如果i可以移动到某个空余段，且这个空余段不是i左右两侧的
    //    那么平移之后得到的新空余段会是i和左右相邻空余时间段只和
    // 2. 如果空余段不是i左右相邻的，那么平移i可以将其左右两侧的相邻空间段合并
    // q[i]: 记录会议i是否适用第一种情况，从左到右遍历会议，同时记录i左侧非相邻空余时间的最大时常t_1
    // t_1 > endtTime[i] - startTime[i] => q[i] = true, 同理可以从右到左更新q[i]
    // 枚举平移的会议i, left_i: 左侧相邻会议的结束时间，right_i：右侧相邻会议的开始时间。
    // 根据q[i]的值判断平移i属于那种情况：1, 新空余段为 right_i - left_i; 
    // 2, 新空余段 right_i - left_i - [endTime[i] - startTime[i]]
    // 返回枚举的最大值即可。

    // II. 贪心优化
    // 其实q[i]并不必须，具体如下
    // 1. 枚举平移的会议，直接讲该会议左右两侧相邻空余段合并，计算得到新的空余段时长
    // 2. 从左到右枚举平移的会议，t1记录当前遍历到的会议左侧非相邻空余时间段的最大时长，
    //    如果当前会议时长<=t1, 那么说明该会议可以平移到对应的空余段，计算平移后得到的新空余段时长
    // 3. 从右到左枚举平移的会议，t2记录当前遍历到的会议右侧非相邻的空余时间段最大时长，同理可以判断是否可平移。
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // I. 
        // int n = startTime.size();
        // vector<bool> q(n);

        // for (int i = 0, t1 = 0, t2 = 0; i < n; i++) 
        // {
        //     if (endTime[i] - startTime[i] <= t1)
        //     {
        //         q[i] = true;
        //     }
        //     t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

        //     if (endTime[n - i - 1] - startTime[n - i  - 1] <= t2)
        //     {
        //         q[n - i - 1] = true;
        //     }
        //     t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
        // }

        // int res = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int left = i == 0 ? 0 : endTime[i - 1];
        //     int right = i == n - 1 ? eventTime : startTime[i + 1];
        //     if (q[i]) 
        //     {
        //         res = max(res, right - left);
        //     } else
        //     {
        //         res = max(res, right - left - (endTime[i] - startTime[i]));
        //     }
        // }
        // return res;

        // II.
        int n = startTime.size(), res = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++)
        {
            int left1 = i == 0 ? 0 : endTime[i - 1];
            int right1 = i == n - 1 ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1)
            {
                res = max(res, right1 - left1);
            } 
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            res = max(res, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
            int right2 = i == 0 ? eventTime : startTime[n - i];
            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) 
            {
                res = max(res, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[1,3]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[0,7,9]\n[1,8,10]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[0,3,7,9]\n[1,4,8,10]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[0,1,2,3,4]\n[1,2,3,4,5]\n
// @lcpr case=end

 */


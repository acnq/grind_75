/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 * @lcpr version=30204
 *
 * [1353] 最多可以参加的会议数目
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
    // 按题意在[startDay_i, endDay_i]中任意一天安排参会即可
    // 由于一天只能参加一场，根据贪心原则，尽可能安排结束时间早的
    // 才能使得剩余时间还可以安排结束时间晚的会议。
    // 我们用最小堆维护会议结束时间，将所有会议按照开始时间先后顺序排序
    // 假设我们枚举到时间点i, 应处理如下：
    //      1.当前所有参会时间<=i的会议全部加入到待选队列，最小堆保留待选会议
    //      2.结束时间早于i的无法参会，讲这些从队列中删除
    //      3. 此时堆顶即是最优解，参加此会议，并且可参会+1
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,2]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1882 lang=cpp
 * @lcpr version=30204
 *
 * [1882] 使用服务器处理任务
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
    // I. 优先队列
    // 我们使用两个优先队列分别存储工作中的服务器以及空闲的服务器
    // busy: 工作中的服务器，用(t, idx)表示每台服务器
    // t: 该服务器结束工作的时间，idx为编号，队首t最小，相同idx最小
    // idle: 空闲服务器，用(w, idx)表示，w为该服务器权重，
    // idx为编号，队首w最小，相同则idx最小
    // 随着时间的增加我们从busy中取出已经完成的服务器
    // 需要安排服务的时候，依次从idle中取出可用的服务器
    // 1. 初始时所有服务器放入idle中，用ts记录时间，为0
    // 2. 遍历每个任务：
    //      2.1. 将ts置为max(ts, i);
    //      2.2. 将busy中满足t<=ts的放入idle中
    //      2.3. 如果此时idle为空，我们要等待服务器完工
    //           将ts置为busy队首的t, 执行2.2
    //      2.4. 给第i个任务安排，从idle队首挑选，并放入busy
    // tc: O((m + n)logm), sc: O(m) 
    // m = |servers|, n = |tasks|
private:
    using PLI = pair<long long, int>;
    using PII = pair<int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        // 工作中的服务器，存储(t, idx)
        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        // 空闲中的服务器，存储(w, idx)
        priority_queue<PII, vector<PII>, greater<PII>> idle;

        for (int i = 0; i < m; i++) {
            idle.emplace(servers[i], i);
        }

        long long ts = 0;
        // 2.2 将优先队列 busy 中满足 t<=ts 依次取出并放入优先队列 idle
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ts = max(ts, static_cast<long long>(i)); // 2.1
            release(); // 2.2
            if (idle.empty()) { // 2.3
                ts = busy.top().first;
                release();
            }
            auto&& [_, idx] = idle.top();
            ans.push_back(idx); // 2.4
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,2]\n[1,2,3,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,3,2]\n[2,1,2,4,5,2,1]\n
// @lcpr case=end

 */


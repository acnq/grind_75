/*
 * @lc app=leetcode.cn id=1665 lang=cpp
 * @lcpr version=30204
 *
 * [1665] 完成所有任务的最少初始能量
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
    // I. 贪心 （差值递减）
    // 差值小的任务产生的额度借给差值大的任务
    // 当任务的启动能量和消耗能量相等，只要到达启动能量即可
    // 我们设启动能量为mini[i], 消耗能量为act[i]
    //我们按照二者的差值从小到大排序，
    // 这样就可以将更多的额度借给差值大的任务 
    // 这样没遍历到一个任务，ans首先累加act[i] (这是完成任务的基础)
    // 如果不够到当前的启动能量mini[i], 则将ans更新为最低能量
    // 这样能最大程度减少浪费
    // tc: O(nlogn), sc: O(n)
    //
    // II. 贪心 （差值递减）
    // I的描述可能不够显然
    // 我们这么思考，在当前能量不变时，
    // 任务的启动能量mini[i]与消耗能量act[i]差值remain越大，剩下的能量越多
    // 于是我们可以先做差值大的任务，以保证剩余能量最少
    // ans 记录所需能量，remain记录目前剩余能量
    // 如果remain > mini[i], 不需要补充能量
    // 不然，要补充task[1] - remain
    // 如果不需要补充能量，剩余能量remain - task[0];
    // 如果需要补充能量，剩余能量task[1] - task[0]
    // 我们记录需要补充的能量即可
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // I.
        // sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b){
        //     return a[1] - a[0] < b[1] - b[0];
        // });
        // int ans = 0;
        // for (auto task: tasks) {
        //     ans = max(ans + task[0], task[1]);
        // }
        // return ans;

        // II.
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] - a[0] > b[1] - b[0]; 
        });
        int ans = 0;
        int remain = 0;
        for (auto task: tasks) {
            ans += remain > task[1] ? 0 : task[1] - remain;
            remain = max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,4],[4,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,4],[10,11],[10,12],[8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30204
 *
 * [739] 每日温度
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
    // I. 暴力
    // 注意温度的范围在[30, 100]之间，我们可以直接维护一个数组next
    // 记录每个温度第一次出现的下标，我们不用预处理获得next, 可以一边遍历温度列表一边更新next
    // 反向遍历温度列表，对于每个元素temprt[i], 在next中找到从temprt[i] + 1到100
    // 中每个温度第一次出现的下标，最小的元素，设为warmerIdx, 
    // 如果不为+infin warmerIdx - i即是它对应的答案, 之后令next[temprt[i]] = i

    // II. 单调栈
    // 用一个栈存储下标，每个下标对应的温度自底向上依次递减，并且保证没有遇到下一次更高温度的下标才入栈
    // 正向遍历温度列表，对于元素temprt[i], 如果栈空，i入栈
    // 如果栈不空，比较栈顶prevIdx对应的温度temprt[prevIdx]和当前temprt[i]
    //  如果temprt[i] > temprt[prevIdx], 则说明找到了对于prevIdx而言更高的温度
    //  移除prevIdx, 将其对应的等待天数设为i - prevIdx, 
    // 重复操作直到栈空或者栈顶元素对应的温度<=当前，然后i入栈
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // I.
        // int n = temperatures.size();
        // vector<int> ans(n), next(101, INT_MAX);
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     int warmerIdx = INT_MAX;
        //     for (int t = temperatures[i] + 1; t <= 100; t++)
        //     {
        //         warmerIdx = min(warmerIdx, next[t]);
        //     }
        //     if (warmerIdx != INT_MAX)
        //     {
        //         ans[i] = warmerIdx - i;
        //     }
        //     next[temperatures[i]] = i;
        // }
        // return ans;

        // II.
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
            {
                int prevIdx = stk.top();
                ans[prevIdx] = i - prevIdx;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */


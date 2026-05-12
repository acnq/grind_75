/*
 * @lc app=leetcode.cn id=3660 lang=cpp
 * @lcpr version=30204
 *
 * [3660] 跳跃游戏 IX
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
    // I. 分治
    // 显然，前跳只能往小了跳，后跳可以往大了跳，那么我们不妨设nums
    // 的最大值为r_max1, 下标i_1, 在其右的元素都可以直接跳到这里
    // i_1之左，我们同理取得区间[0, i_1 - 1]的前缀最大r_max2和其下标i2
    // 然后我们要特别考虑[i_2, i_1 - 1]上的元素，
    // 假设[i_1, n - 1]上最小值为r_min, 我们知道，
    // [i_2, i_1 - 1]上的元素总能跳转到r_max2上，之后
    // 如果r_max2 <= r_min, 则r_max2已经是这些元素的最优解了
    // 如果r_max2 > r_min，则到达r_max2之后，再经过r_min中转，
    //      可以跳到r_max1, 此为最优解
    // [0, i_2 - 1]也是同样的子结构
    // 转移策略
    // 假设当前区间[0, i], 前缀最大值在i', 区间为[i', i]
    // 1. r_max 当前区间目标最大值, 是上一轮的前缀最大值
    // 2. r_min r_max对应区间的最小值，r_min' = min(r_min, min_{i'<=k<=i}(nums[k]))
    // 之后递归即可
    // tc: O(n), sc: O(n)
    // 
    // II. 单调栈
    // nums中的逆序对可以互相抵达，我们把互相可以抵达的元素看做联通块
    // 只要nums[i]小于左侧联通块内的最大值，就可以合并
    // 同理，假设联通块A最大值a_max <= 联通块B最大值b_max, 则AB可以合并
    // 由此我们知道nums上的联通块必然是连续的，而且最大值是单调的
    // 我们用三元组(value, left, right)表示联通块的最大值和边界
    // 维护单调栈，从左到右扫描nums, 遍历nums[i], 不断从栈顶弹出左侧联通块合并
    // 直到无法合并，将新的联通块压入栈顶，最后每个联通块内答案就是该联通块的最值
    // tc = sc: O(n)
public:
    // II.
    struct Item {
        int value;
        int left;
        int right;
    };

    vector<int> maxValue(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // vector<int> ans(n, 0);

        // using Item = pair<int, int>; //[value, idx]
        // vector<Item> prevMax(n);

        // Item prev = {INT_MIN, -1};
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] > prev.first) {
        //         prev = {nums[i], i};
        //     }
        //     prevMax[i] = prev;
        // }

        // auto process = [&](auto& self, int r, int rightMin, int rightMax) -> void{
        //     auto [pMax, pivotIdx] = prevMax[r];
        //     int curMax = pMax <= rightMin ? pMax : rightMax;

        //     int nextRightMin = min(pMax, rightMin);
        //     for (int i = pivotIdx; i <= r; i++) {
        //         ans[i] = curMax;
        //         nextRightMin = min(nextRightMin, nums[i]);
        //     }

        //     if (pivotIdx == 0) {
        //         return;
        //     }
            
        //     self(self, pivotIdx - 1, nextRightMin, curMax);

        //     return;
        // };

        // process(process, n - 1, INT_MAX, 0);

        // return ans;

        // II.
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<Item> stack;

        for (int i = 0; i < n; i++) {
            Item curr = {nums[i], i, i};

            while (!stack.empty() && stack.back().value > nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }

            stack.push_back(curr);
        }

        for (size_t i = 0; i < stack.size(); i++) {
            for (int j = stack[i].left; j <= stack[i].right; j++) {
                ans[j] = stack[i].value;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1]\n
// @lcpr case=end

 */


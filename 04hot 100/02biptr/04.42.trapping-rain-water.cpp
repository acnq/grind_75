/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
    // 对i处能接的雨水的值有如下推导：
    // trap[i] = min(max_{j<i}height[j], max_{k>i}height[k]) - height[i]\
    // 第一项表示水位能到达的最大高度，是i左侧最高处和右侧最高处的较小值，
    // 减去第二项，即此处高度即是可容纳的水量
    // 那么对于每个i, 我们要用O(n)的时间分别去寻找他的左右侧最大值吗？
    // 可以，但是这样会超时，我们需要使用"双指针“(left, right)来标记最值
    // （当然动态规划也可，但是双指针相当于次动态规划的进一步优化）
    // 当height[left] < height[right]时，右移left, 更新leftMax = max(leftMax, height[left])
    // 直到height[left] >= height[right], 左移right, 更新rightMax = max(rightMax, height[left])
    // 这样height[left] < height[right]时， leftMax < rightMax也成立
    // height[left] >= height[right]时，leftMax >= righMax也成立，所以计算trap[i]时只要根据当时left和right的大小情况
    // 选择leftMax/rightMax - height[i]
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        while (left < right)
        {
            if (height[left] < height[right])
            { 
                res += leftMax - height[left];
                left++;
                leftMax = max(leftMax, height[left]);
            } else {
                res += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */


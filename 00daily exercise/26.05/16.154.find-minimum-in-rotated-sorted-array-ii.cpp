/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=30204
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
    // I. 二分查找
    // 我们参考15.153,的题目，区别仅在于这里有重复元素，但是性质不变：
    // 到最小值的位置，就能获得旋转的次数
    // 考虑旋转后数组的最后一个元素x, 最小值右侧元素都<=x
    // 左侧的都>=x, 我们可以同样可以二分查找获得最小值
    // 同样设定low, high, pivot，
    // nums[pivot] < nums[high] 以及 nums[pivot] > nums[high]不变：
    // 1. nums[pivot] < nums[high]:
    //      nums[pivot]在最小值右侧，舍弃右半部分
    // 2. nums[pivot] > nums[high]:
    //      nums[pivot]在最小值左侧，舍弃左半部分
    // 3. nums[pivot] == nums[high]
    //      因为重复元素的存在，nums[pivot]在最小值的左右侧其实无法确定
    //      故我们不能舍弃，但是我们可以知道，无论nums[high]是否是最小值
    //      nums[pivot]也可以做最小值，所以我们至少可以排除右端点high
    // tc: O(logn)平均，最劣状态【所有元素相同】下O(n); sc: O(1)
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            } else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            } else {
                high--;
            }
        }
        return nums[low];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */


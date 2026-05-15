/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30204
 *
 * [153] 寻找旋转排序数组中的最小值
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
    // 因为不包含重复元素，所以升序数组经过旋转之后，
    // 一定是一个单峰单谷的折线
    // 找到最小值的位置，就能获得旋转的次数
    // 考虑旋转后数组的最后一个元素x, 最小值右侧元素都严格<x
    // 左侧的都严格>x, 我们可以直接二分查找获得最小值
    // 假设二分的每一步，左边界low，右边界为high, 中点pivot
    // 比较nums[pivot]和nums[high], 有
    // 1. nums[pivot] < nums[high]:
    //      nums[pivot]在最小值右侧，舍弃右半部分
    // 2. nums[pivot] > nums[high]:
    //      nums[pivot]在最小值左侧，舍弃左半部分
    // 3. 不包含重复元素说明只要区间长度!=1, pivot就不会和high重合
    // 而如果长度==1，则可以结束二分查找
    // tc: O(logn); sc: O(1)
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            } else {
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */


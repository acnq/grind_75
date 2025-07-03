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
    // 显然旋转之后也会分成两个递增的部分，而最小值一定在第二个递增部分的首个
    // 考虑旋转后数组的最后一个元素x, 最小值右侧的元除x本身之外都严格小于x;
    // 而最小值左侧的元一定都严格大于x, 于是我们二分查找
    // 左右分别设为low,high中点设为pivot，比较nums[pivot]与nums[high]
    // nums[pivot] < nums[high]: 最小值在pivot左侧，忽略右半部分
    // nums[pivot] > nums[high]: 最小值在pivot右侧，忽略左半部分
    // 二分的关键是：有一半可以忽略，
    // 这种旋转类的题目总有一半是有序的，所以总可以使用二分
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        { // 没有=，因为=则直接跳出循环得到答案，最小值必然存在
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
            {
                high = pivot; // 不能-1，因为pivot可能就是答案
            } else
            {
                low = pivot + 1; // 必须+1, nums[pivot]都大于nums[high]了必然不是最小
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


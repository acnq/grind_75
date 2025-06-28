// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    // 和我的思路差不多，但是第一次查找的不是第一个小于等于的lower_bound
    // 而是第一个等于target的位置（记为lIdx), 如果找不到，返回-1即可
    // 第二次查找算是第一个大于target的位置-1(记为rIdx)
    // 设定binSearch(nums, target, lower)作为二分查找，lower是bool, 
    // 用于指标查找第一个大于等于或者第一个大于
public:
    int binSearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
            } else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // 感觉用lower/upper_bound可以直接解出来？
        // O.
        // int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // if (l == r)
        // {
        //     return {-1, -1};
        // }
        
        // return {l, r - 1};

        // I.
        int lIdx = binSearch(nums, target, true);
        int rIdx = binSearch(nums, target, false) - 1;
        if (lIdx <= rIdx && rIdx < nums.size() && nums[lIdx] == target && nums[rIdx] == target)
        {
            return vector<int>{lIdx, rIdx};
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30204
 *
 * [35] 搜索插入位置
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
    // I. 二分法
    // 插入条件为 nums[pos - 1] < target <= nums[pos]
    // 实际上就是“在有有序数组中找第一个>=target的下标i.
public:
    int searchInsert(vector<int>& nums, int target) {
        // O. 失败
        // int n = nums.size();
        // int l = 0, r = n - 1, mid = (l + r) / 2;
        // while (l < r)
        // {
        //     if (nums[mid] == target)
        //     {
        //         return mid;
        //     } else if (nums[mid] > target) {
        //         r = mid - 1;
        //         mid = (l + r) / 2;
        //     } else {
        //         l = mid + 1;
        //         mid = (l + r) / 2;
        //     }
        // }
        // return mid;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */


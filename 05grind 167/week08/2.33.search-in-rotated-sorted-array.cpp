/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    // 同样进行二分查找
    // 研究[l, mid]和[mid + 1, r]中哪一部分是有序的，只要判断0和mid的大小就能确定
    //  1. 若[l, mid - 1]有序，且target在[nums[l], nums[mid])
    //      搜索范围缩小至[l, mid - 1], 否则在[mid +1, r]中寻找
    //  2. 若[mid, r]有序，且target在(nums[mid + 1], nums[r]]中，
    //      搜索范围缩小至[mid + 1, r], 否则在[l, mid - 1]中寻找
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n)
        {
            return -1;
        }
        if (n == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            
            if (nums[0] <= nums[mid]) // 一定是0:mid有序
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // 否则一定是mid:N-1有序
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */


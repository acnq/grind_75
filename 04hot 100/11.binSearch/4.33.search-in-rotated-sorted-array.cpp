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
    // I. 二分
    // 其实题目的关键是：二分分割之后肯定有至少一个部分是有序的
    // 如果[l, mid - 1]有序且target\in [nums[l], nums[mid]), 
    //      搜索缩小至[l, mid - 1], 否则[mid + 1, r]中搜索
    // 如果[mid, r]有序且target \in (nums[mid + 1], nums[r]]
    //      搜索范围缩小至[mid + 1, r], 否则在[l, mid - 1]中寻找
    // 那么我们怎么判断哪个是顺序区间呢？
    // 只要比较nums[l]和nums[mid]即可，<则[l:mid]是有序区间，否则另一个一定有序
    // 为何？我们证明nums[l] < nums[mid] => nums[l:mid]有序，使用反证法
    // 如果nums[l:mid]在这种状态下还是无序的，则有k \in (l, mid), nums[l:k]有序（递增）
    // nums[k + 1, mid]递增，而nums[mid:r]一定是递增的，而且每一项都大于nums[mid]
    // 进而都大于nums[k+1:mid], 这时我们就会发现，nums[l:k]无论如何都不可能逆旋转一次
    // 是的nums恢复有序，因为nums[l] < nums[mid]所以nums[l:k]要插入nums[k + 1, mid]才有可能
    // 但是由题意，旋转只有一个支点，一次操作。
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
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
            if (nums[l] <= nums[mid])
            { // nums[l:mid]有序
                if (nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
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


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3634 lang=cpp
 * @lcpr version=30204
 *
 * [3634] 使数组平衡的最少移除数目
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
    // I. 排序+双指针
    // 首先对nums排序，记满足条件的数组最小元素为Min, 最大为max,
    // 那么我们只需要移除<min或者>max的元素，移除二者之间的元素没有意义

    // 我们用双指针解决此问题：左指针left指向排序后的首元素x，右指针right不断右移
    // 直到指向第一个严格大于k * x的元素，或者超过边界，此时左闭右开区间[left,right)对应一个平衡数组
    // 长度为right - left
    // 我们不断用(right - left)更新答案即可
    // tc: O(nlogn), sc: O(logn)
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, right = 0;
        for (int left = 0; left < n; left++) {
            while(right < n && nums[right] <= static_cast<long long>(nums[left]) * k) {
                right++;
            }
            ans = min(ans, n - (right - left));
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=constructTransformedArray
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2, 1, 5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,6,2,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,6]\n2\n
// @lcpr case=end

 */


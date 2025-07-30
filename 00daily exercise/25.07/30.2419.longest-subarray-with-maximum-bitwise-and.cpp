/*
 * @lc app=leetcode.cn id=2419 lang=cpp
 * @lcpr version=30204
 *
 * [2419] 按位与最大的最长子数组
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
    // I. 线性扫描
    // 本题的关键是发现：\forall x, a, a & x <= a,
    // 理由：如果二者相等取等号，否则肯定有至少一位不同，较大的此位为1，
    // 那么这位按位和的结果就是0，导致变小
    // 于是，数组中连续子数组中最大按位与的结果一定是数组最大值max(nums)
    // 所以答案就是的最大非空子数组长度=数组中连续出现max(nums)的最多次数
    // 直接遍历即可
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = nums[0];
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                ans = cnt = 1;
                maxValue = nums[i];
            } else if (nums[i] < maxValue) {
                cnt = 0;
            } else if (nums[i] == maxValue) {
                cnt++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */


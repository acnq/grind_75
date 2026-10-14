/*
 * @lc app=leetcode.cn id=3727 lang=cpp
 * @lcpr version=30204
 *
 * [3727] 最大交替平方和
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

#include <ranges>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 贪心 + 排序
    // 我们要求\sigma_{i=0}^{n-1}(-1)^i * nums[i]^2的最大值
    // 安排绝对值更大的数为正，更小的为负即可
    // 所以我们首先按照绝对值/平方排序，然后取前\floor{n/2}为负即可
    // tc: O(nlogn), sc: O(1)
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (auto& num: nums) {
            num *= num;
        }
        sort(nums.begin(), nums.end());
        return - accumulate(nums.begin(), nums.begin() + n / 2, 0LL) + accumulate(nums.begin() + n / 2, nums.end(), 0LL);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,2,-2,3,-3]\n
// @lcpr case=end

 */


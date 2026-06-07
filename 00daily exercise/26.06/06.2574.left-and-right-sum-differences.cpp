/*
 * @lc app=leetcode.cn id=2574 lang=cpp
 * @lcpr version=30204
 *
 * [2574] 左右元素和的差值
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
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // O. 4min秒杀
        // int n = nums.size(), leftSum = 0, rightSum = 0;
        // for (int num: nums) {
        //     rightSum += num;
        // }
        // vector<int> ans(n, 0);
        // for (int i = 0; i < n; i++) {
        //     rightSum -= nums[i];
        //     ans[i] = abs(rightSum - leftSum);
        //     leftSum += nums[i];
        // }
        // return ans;

        // I. 前缀和（答案写的更标准更官方一点）
        int n = nums.size();
        vector<int> ans(n);

        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }
        int rightSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,4,8,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


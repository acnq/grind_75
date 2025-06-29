/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30204
 *
 * [198] 打家劫舍
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
    // f[i] = max(f[0], ... ... , f[i - 1]) + nums[i]
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> f(n + 1, 0);
        // if (n == 0)
        // {
        //     return 0;
        // }
        // if (n == 1)
        // {
        //     return nums[0];
        // }
        // if (n == 2)
        // {
        //     return max(nums[0], nums[1]);
        // }
        // f[0] = nums[0];
        // f[1] = max(nums[0], nums[1]);
        // for (int i = 2; i < n; i++)
        // {
        //     int maxf = 0;
        //     for (int j = 0; j < i - 1; j++)
        //     {
        //         maxf = max(f[j], maxf);
        //     }
        //     f[i] = maxf + nums[i];
        // }
        // return max(f[n - 1], f[n - 2]);

        // 上述答案能过，但是效率不高
        // 标准答案：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        if (nums.empty())
        {
            return 0;
        }
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30204
 *
 * [416] 分割等和子集
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // I. 动态规划
    // 转换成0-1背包问题
    // 1. n < 2: return false
    // 2. 计算数组元素和sum和最大元素maxNum, sum % 2 == 1，return false
    //      sum % 2 == 0; 令target = sum / 2; 则需要判断是否可以选出数字
    // 使得和为target, 若maxNum > target, 也返回false
    // dp[i][j]: nums[0, i]选择若干元素（可以选择0个），使得和为j
    //  dp[i][0] = true;  dp[0][nums[0]] = true
    // j >= nums[i], 则可选可不选
    //   不选nums[i]： dp[i][j] = dp[i - 1][j]
    //   选nums[i]: dp[i][j] = dp[i - 1][j - nums[i]]
    // j <= nums[i], 不能选择nums[i]: dp[i][j] = dp[i - 1][j]
    //              dp[i - 1][j] | dp[i - 1][j - nums[i]],  j>=nums[i]
    // dp[i][j] =   dp[i - 1][j]                            j<nums[i]
    // 答案dp[n - 1][target]
    bool canPartition(vector<int>& nums) {
        // int n = nums.size();
        // if (n < 2)
        // {
        //     return false;
        // }
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // int maxNum = *max_element(nums.begin(), nums.end());
        // if (sum & 1)
        // {
        //     return false;
        // }
        // int target = sum / 2;
        // if (maxNum > target)
        // {
        //     return false;
        // }
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // for (int i = 0; i < n; i++)
        // {
        //     dp[i][0] = true;
        // }
        // dp[0][nums[0]] = true;
        // for (int i = 1; i < n; i++)
        // {
        //     int num = nums[i];
        //     for (int j = 1; j <=target; j++)
        //     {
        //         if (j >= num)
        //         {
        //             dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
        //         } else {
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //     }
        // }
        // return dp[n - 1][target];
        // II. 削减存储： dp[j] = dp[j] | dp[j - nums[i]]
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = 0;
        int maxNum = 0;
        for (auto& num: nums)
        {
            sum += num;
            maxNum = max(maxNum, num);
        }
        
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }

        vector<int> dp(target + 1, 0);
        dp[0] = true;

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = target; j >= num; j--)
            {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */


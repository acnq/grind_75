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
    // 4.6. 做过一遍了
    // n = nums.size()
    // n < 2 => return false
    // def: nums所有元素和 := sum; nums最大元素 maxNum
    // sum % 2 == 1 => return false; 
    // sum % 2 == 0 => def target := sum / 2,
    // 需要判断是否能有子集的元素和为target, 
    // 若 maxNum > target, 则maxNum外的元素和一定小于target, => return false
    
    // 考虑dp[i][j], i = 0:n-1; j=0:target
    // 表示数组[0, i]下标范围内若干正整数(可以0个)，是否存在方案
    // s.t. 选取的正整数和为j, dp所有元素初始化为0
    // 边界条件：
    // 1. 不选择任何元素，则被选取的正整数和为0；=> \forall i* \in [0, n) => dp[i*][0] = T
    // 2. i==0, 仅有nums[0]可选 => dp[0][nums[0]] = T
    // 转移方程
    // 1. j >= nums[i], 则当前元素可选可不选，
    //      不选 nums[i] => dp[i][j] = dp[i - 1][j]
    //      选择 nums[i] => dp[i][j] = dp[i - 1][j - nums[i]]
    // 2. j < nums[i], 则选的数字和等于j的情况下无法选择nums[i]
    //      只能 dp[i][j] = dp[i - 1][j]
    // 综上
    // dp[i][j] =   { dp[i - 1][j] | dp[i - 1][j - nums[i]],    j >= nums[i]
    //              { dp[i - 1][j]                              j < numns[i]
    // res = dp[n - 1][target]
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
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


/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30204
 *
 * [377] 组合总和 Ⅳ
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
    // I. DP
    // dp[x]: 选取元素之和等于x的方案数，ans = dp[target]
    // dp[0] = 1
    // 假设存在一种和为i的排列，则该排列最后一个元素一定来自nums
    // 假设该排列的最后一个元素是num, num <= i, 
    // 对于元素之和=i - num的每一种排列，最后添加一个元素之和为i的排列
    // dp[i] = \sum_{num} dp[i - num]
    // dp[0] = 1
    // 遍历i\in[1, target], 
    //      遍历nums中每个元素num, num <= i, dp[i] += dp[i - num]
    // ans = dp[target]
    // tc: O(target * n); sc: O(target).
public:
    typedef unsigned long long ull;
    int combinationSum4(vector<int>& nums, int target) {
        vector<ull> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int& num: nums) {
                if (num <= i)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=368 lang=cpp
 * @lcpr version=30204
 *
 * [368] 最大整除子集
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
    // nums升序排序，以便获得子集的最小整数或者最大整数
    // dp[i]: 以nums[i]为最大整数的“整除子集”大小（nums[i]必被选择）
    // 枚举j=0:i-1, 若nums[j] | nums[i], 则nums[i]可以扩充nums[j]
    // 初始化：dp[i] = 1, 包含nums[i]
    // 输出：需要枚举dp[i], 选出最大整除子集大小maxSize, 以及最大子集最大整数maxVal
    // 然后如下倒推获得一个子集：
    //  1. 倒序遍历dp, 找到dp[i] = maxSize, 把对应的nums[i]加入结果集，此时maxVal = nums[i]
    //  2. maxSize--, 继续遍历找i， s.t. dp[i] = maxSize, 且nums[i] | maxVal
    //      此时将nums[i]加入结果，maxVal=nums[i] (此时的i)
    //  3. 重复上述操作，直到maxSize = 0, 此时结果集=目标子集
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // 第一步：构建dp[i], 找出最大子集的个数，和最大整数
        vector<int> dp(len, 1);
        int maxSize = 1;
        int maxVal = dp[0];
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // 无重复元
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            if (dp[i] > maxSize)
            {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        // 第二步：倒推获得最大子集
        vector<int> res;
        if (maxSize == 1)
        {
            res.push_back(nums[0]);
            return res;
        }
        
        for (int i = len - 1; i >= 0 && maxSize > 0; i--)
        {
            if (dp[i] == maxSize && maxVal % nums[i] == 0)
            {
                res.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,8]\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=740 lang=cpp
 * @lcpr version=30204
 *
 * [740] 删除并获得点数
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
    // dp[n] = max(cnt[n] * n + dp[n - 2], dp[n - 1]); if cnt[n] >= 1
    // dp[n] = dp[n - 1]; if cnt[n] = 0;
public:
    int rob(vector<int> &nums) {// 注意用滚动数组做了优化
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = nums[n - 1];
        vector<int> dp(m + 1, 0), cnt(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        if (nums[0] == nums[n - 1])
        {
            return n * nums[0];
        }

        dp[nums[0]] = cnt[nums[0]] * nums[0];
        for (int i = nums[0] + 1; i <= m; i++)
        {
            if (cnt[i] == 0)
            {
                dp[i] = dp[i - 1];
            }
            dp[i] = max(cnt[i] * i + dp[i - 2], dp[i - 1]);
        }
        
        return dp[nums[n - 1]];

        // 官方题解调用了之前打家劫舍的函数
        // int maxVal = 0;
        // for(int val: nums) {
        //     maxVal = max(maxVal, val);
        // }
        // vector<int> sum(maxVal + 1);
        // for(int val: nums) {
        //     sum[val] += val;
        // }
        // return rob(sum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3,3,4]\n
// @lcpr case=end

 */


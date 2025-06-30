/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30204
 *
 * [152] 乘积最大子数组
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
    // I.DP
    // f_max(i): 第i个元素结尾的乘积最大子数组的乘积
    // f_max(i) = max_{i=1}^n {f(i - 1) * a_i, a_i} ?
    // 是错误的，nums = {5, 6, -3, 4, -3}; f_max = {5, 30, -3, 4, -3}
    // 貌似答案是30，但是正确的答案是全体乘积，我们可以看到：当前最优解未必由前一个转移来
    // 于是我们发现，我们需要根据正负性分类讨论
    // f_max(i) = max_{i \in [1, n]} {f_max(i - 1) * a_i, f_min(i - 1) * a_i, a_i}
    // f_min(i) = min_{i \in [1, n]} {f_max(i - 1) * a_i, f_min(i - 1) * a_i, a_i}
    // f_min(i): 第i个元素结尾的乘积最小子数组的乘积
    // sc/tc: O(n)

    // II. 滚动数组
    // 因为第i个状态只和第i-1个有关，我们直接维护f_max和f_min
    // tc: O(n); tc: O(1)
public:
    int maxProduct(vector<int>& nums) {
        // I.
        // vector<long> maxF(nums.begin(), nums.end()), minF(nums.begin(), nums.end());
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     maxF[i] = max(maxF[i - 1] * nums[i], max((long)nums[i], minF[i - 1] * nums[i]));
        //     minF[i] = min(minF[i - 1] * nums[i], min((long)nums[i], maxF[i - 1] * nums[i]));
        //     if (minF[i] < INT_MIN)
        //     {
        //         minF[i] = nums[i];
        //     }
        // }
        // return *max_element(maxF.begin(), maxF.end());

        // II.
        long maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            long mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max((long)nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min((long)nums[i], mx * nums[i]));
            if (minF < INT_MIN)
            {
                minF = nums[i];
            }
            ans = max(maxF, ans); 
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */


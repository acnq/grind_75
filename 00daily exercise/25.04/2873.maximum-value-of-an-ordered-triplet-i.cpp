/*
 * @lc app=leetcode.cn id=2873 lang=cpp
 * @lcpr version=30204
 *
 * [2873] 有序三元组中的最大值 I
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
    // I. 纯枚举，能过
    // II. 贪心
    //  nums[i]取[0, j)内最大值时，目标最大，我们两层循环分别枚举k和j,
    //  用m维护[0, j)最大值时，可O(n^2)解决

    // III. 贪心 + 前后缀
    // 固定j, nums[i], nums[k]分别取[0, j)和[j + 1, n)的最大值，目标最大
    // leftMax[j]/rightMax[j]维护前缀[0, j)最大值和后缀[j + 1, n)最大值
    // 枚举j, 计算(leftMax[j] - nums[j]) * rightMax[j], 可O(n)解决

    // IV. 同上，不过我们这次遍历k
    // imax维护nums[i], dmax维护nums[i] - nums[j]
public:
    long long maximumTripletValue(vector<int>& nums) {
        // long long res = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for(int j = i + 1; j < nums.size(); j++) 
        //     {
        //         for (int k = j + 1; k < nums.size(); k++)
        //         {
        //             res = max(res, (nums[i] - nums[j]) * (long long)nums[k]);
        //         }
        //     }
        // }
        // return res;

        // II.
        // int n = nums.size();
        // long long res = 0;
        // for (int k = 2; k < n; k++)
        // {
        //     int m = nums[0];
        //     for (int j = 1; j < k; j++)
        //     {
        //         res = max(res, (long long)(m - nums[j]) * nums[k]);
        //         m = max(m, nums[j]);
        //     }
            
        // }
        // return res;

        // III.
        // int n = nums.size();
        // vector<int> leftMax(n), rightMax(n);
        // for (int i = 1; i < n; i++)
        // {
        //     leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        //     rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        // }
        // long long res = 0;
        // for (int j = 1; j < n - 1; j++)
        // {
        //     res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        // }
        // return res;

        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,6,1,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,4,19]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */


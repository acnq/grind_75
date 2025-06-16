/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
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
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status left, Status right) {
        int iSum = left.iSum + right.iSum;
        int lSum = max(left.lSum, left.iSum + right.lSum);
        int rSum = max(right.rSum, right.iSum + left.rSum);
        int mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);
        return Status{lSum, rSum, mSum, iSum};
    };
    
    Status get(vector<int>& arr, int left, int right) {
        if (left == right)
        {
            return Status{arr[left], arr[left], arr[left], arr[left]};
        }
        int mid = (left + right) >> 1;
        Status lSub = get(arr, left, mid);
        Status rSub = get(arr, mid + 1, right);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        // int max_sarry = nums[0], max_num = nums[0]; 
        // // 从1开始枚举能避免很多初始化的麻烦
        // for (int i = 1; i < nums.size(); i++)
        // {   // max_num[i] = max(nums[i - 1] + nums[i], nums[i]);
        //     // max_sarry = max_{0<=i<=nums.size()}max_num[i];
        //     max_num = max(max_num + nums[i], nums[i]);
        //     max_sarry = max(max_sarry, max_num);
        // }
        // return max_sarry;

        // 分治法：
        // get(a, l, r)查询a [l, r]区间的最大字段和，m = \floor((l + r) / 2)
        // 分治到l - r = 1为出口
        // 维护信息：
        // 1. lSum: [l, r] l为左端点的最大子段和
        // 2. rSum: [l, r] r为右端点的最大字段和
        // 3. mSum: [l, r] 最大字段和
        // 4. iSum: [l, r] 区间和
        // iSum[l, r] = iSum[l, m] + iSum[m, r]
        // lSum[l, r] = max(lSum[l, m], iSum[l, m] + lSum[m, r])
        // rSum[l, r] = max(rSum[m, r], iSum[m, r] + rSum[l, m])
        // mSum[l, r] = max(mSum[l, m], mSum[m, r], rSum[l, m] + lSum[m, r]) 是否跨越m
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */


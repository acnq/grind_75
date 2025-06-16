/*
 * @lc app=leetcode.cn id=896 lang=cpp
 * @lcpr version=30204
 *
 * [896] 单调数列
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
    bool isIncreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 1 || n == 2)
        // {
        //     return true;
        // }
        // return isDecreasing(nums) || isIncreasing(nums);

        // 官方：一次遍历即可
        // 如果即遇到了nums[i] > nums[i + 1], 又遇到了num[j] < nums[j + 1]
        // 则一定不是单调的，如果始终没有同时遇到两个，则单调
        bool inc = true, dec = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                inc = false;
            }
            if (nums[i] < nums[i + 1])
            {
                dec = false;
            }
        }
        return inc || dec;
        
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

 */


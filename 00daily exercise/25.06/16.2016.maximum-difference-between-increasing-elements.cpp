// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 * @lcpr version=30204
 *
 * [2016] 增量元素之间的最大差值
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
    // 官方给了个O(N)的算法
    // I. 前缀最小值
    // 固定j, 选择0<=i<j,且nums[i]最小的那个i即可
    // 枚举i, 维护nums[0:(j-1)]的“前缀最小值”premin, 这样
    // 若nums[i] > premin, 用nums[i] - premin更新答案
    // 否则，用nums[i]更新前缀最小值 
public:
    int maximumDifference(vector<int>& nums) {
        // int maxDiff = -1, curDiff = -1;
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[j] > nums[i]) {
        //             curDiff = nums[j] - nums[i];
        //             maxDiff = max(maxDiff, curDiff);
        //         }
        //     }
        // }
        // return maxDiff;
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumDifference
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [7,1,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,2,10]\n
// @lcpr case=end

 */


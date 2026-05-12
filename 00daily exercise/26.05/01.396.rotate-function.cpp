/*
 * @lc app=leetcode.cn id=396 lang=cpp
 * @lcpr version=30204
 *
 * [396] 旋转函数
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
    // I. 迭代
    // 记数组nums所有元素之和为numSum, 得到
    // F(0) = 0 * nums[0] + 1 * nums[1] + ... + (n - 1) * nums[n - 1]
    // F(1) = 1 * nums[0] + 2 * nums[1] + ... + 0 * nums[n - 1]
    //      = F(0) + numSum - n * nums[n - 1]
    // F(k) = F(k - 1) + numSum - n * nums[n - k]
    //
    // tc: O(n), sc: O(1)
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [100]\n
// @lcpr case=end

 */


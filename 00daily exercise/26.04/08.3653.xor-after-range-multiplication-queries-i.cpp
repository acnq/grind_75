/*
 * @lc app=leetcode.cn id=3653 lang=cpp
 * @lcpr version=30204
 *
 * [3653] 区间乘法查询后的异或 I
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
    // I. 模拟
    static const int mod = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; l <= r; i += k) {
                nums[i] = 1LL * nums[i] * v % mod;
            }
        }

        int res = 0;
        for (auto x : nums) {
            res ^= x;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n[[0,2,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1,5,4]\n[[1,4,2,3],[0,2,1,2]]\n
// @lcpr case=end

 */


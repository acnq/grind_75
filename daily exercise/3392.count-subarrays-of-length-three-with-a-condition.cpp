/*
 * @lc app=leetcode.cn id=3392 lang=cpp
 * @lcpr version=30204
 *
 * [3392] 统计符合条件长度为 3 的子数组数目
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
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] + nums[i + 2] - nums[i + 1] / 2.0 == 0.0)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */


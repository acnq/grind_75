/*
 * @lc app=leetcode.cn id=3024 lang=cpp
 * @lcpr version=30204
 *
 * [3024] 三角形类型
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
    string triangleType(vector<int>& nums) {
        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else {
            sort(nums.begin(), nums.end());
            if (nums[0] + nums[1] <= nums[2])
            {
                return "none";
            } else {
                if (nums[0] == nums[1] || nums[1] == nums[2])
                {
                    return "isosceles";
                } else {
                    return "scalence";
                }
            }
            
        }

        // 标准答案先排序再判断equilateral, 其实不差
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5]\n
// @lcpr case=end

 */


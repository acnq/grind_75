/*
 * @lc app=leetcode.cn id=217 lang=cpp
 * @lcpr version=30204
 *
 * [217] 存在重复元素
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
    bool containsDuplicate(vector<int>& nums) {
        // sort-based
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
        // unordered_map<int, int> stats;
        // for(int num: nums) {
        //     if (stats.count(num) == 0)
        //     {
        //         stats[num] = 1;
        //     } else {
        //         return true;
        //     }
        // }
        // return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,3,3,4,3,2,4,2]\n
// @lcpr case=end

 */


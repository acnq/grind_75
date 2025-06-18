/*
 * @lc app=leetcode.cn id=2966 lang=cpp
 * @lcpr version=30204
 *
 * [2966] 划分数组并满足最大差限制
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
    // I. 排序+贪心
    // 将nums从小到大排序，然后3个一组，如果nums[i + 2] - nums[i] > k,
    // 则显然不能满足条件，返回空，否则这三个元素就可以放入结果res中
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }
            res.emplace_back(nums.begin() + i, nums.begin() + i + 3);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,8,7,9,3,5,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,2,2,5,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11]\n14\n
// @lcpr case=end

 */


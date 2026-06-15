/*
 * @lc app=leetcode.cn id=3689 lang=cpp
 * @lcpr version=30204
 *
 * [3689] 最大子数组总值 I
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
    // I. 贪心 (脑筋急转弯)
    // 由于可以重复选择同一个子数组，找到价值最大的子数组
    // 选择k次既可
    // 任意子数组的价值最多为max(nums) - min(nums);
    // 所以总的最大价值为k * (max(nums) - min(nums))
    // tc: O(n), sc: O(1)
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m1 = INT_MAX, m2 = INT_MIN;
        for (int x: nums) {
            m1 = min(m1, x);
            m2 = max(m2, x);
        }
        return (long long)(m2 - m1) * k;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,1]\n3\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 * @lcpr version=30204
 *
 * [1984] 学生分数的最小差值
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
    // I. 排序
    // 我们只要排好序之后，连续的比较k个项的差值即可
    // 理由可以直接反证法证明，如果选择k个分数时跳过了某个下标i, 
    // 那么我们将最高分替换为nums[i], 最高分不会变大，最大差值不会变大
    // 如此，我们首先升序排列nums, 随后使用固定k长-窗口在nums上滑动
    // 左边界i, 右边界i+k-1, 记录二者差值并维护最小值即可
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [90]\n1\n
// @lcpr case=end

// @lcpr case=start
// [9,4,1,7]\n2\n
// @lcpr case=end

 */


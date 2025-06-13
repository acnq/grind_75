/*
 * @lc app=leetcode.cn id=2616 lang=cpp
 * @lcpr version=30204
 *
 * [2616] 最小化数对的最大差值
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
    // I. 贪心+二分
    // 我们二分目标mx，检查能否找到p个差值<=mx的数组
    // 我们首先排序，由于相邻元素差值小，可以优先选择相邻元素

    // 注意到计数时一个元素在两个组中只能算一次，所以我们需要动态规划（类似打家劫舍）
    // dp[n]: nums[:(n)]中满足条件的数对个数
    // 如若选择nums[n - 1]和nums[n], 答案=dp[n - 2] + 1
    // 如若不选择nums[n], 答案=dp[n - 1]
    // 二者取较大值
    // 这个较大值暗示我们其实可以贪心，只要nums[i]和nums[i + 1]
    // 构成的数对就立刻选取，如果不选择nums[i], 从剩下的数中选出的对数一定不会超过有nums[i]的

    // tc: O(n log n + n log U) (U = max(nums) - min(nums))
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        auto check = [&](int mx) -> bool {
            int cnt = 0;
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i + 1] - nums[i] <= mx) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };

        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = (left + right) >> 1;
            if(check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,1,2]\n1\n
// @lcpr case=end

 */


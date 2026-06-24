/*
 * @lc app=leetcode.cn id=3737 lang=cpp
 * @lcpr version=30204
 *
 * [3737] 统计主要元素子数组数目 I
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
    // I. 枚举
    // 因为这里nums的长度很小，所以我们可以直接枚举左右端点i,j
    // 维护计数器cnt: nums[j] == target, 则cnt++; 否则cnt--;
    // 这样只要cnt>0, target出现次数就超过子数组一半，
    // target这个子数组的主要元素，res++;
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                cnt += (nums[j] == target ? 1 : -1);
                if (cnt > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

 */


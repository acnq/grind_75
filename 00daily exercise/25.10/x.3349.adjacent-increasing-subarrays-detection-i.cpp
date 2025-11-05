/*
 * @lc app=leetcode.cn id=3349 lang=cpp
 * @lcpr version=30204
 *
 * [3349] 检测相邻递增子数组 I
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
    // I. 一次遍历
    // cnt, precnt记录当前位置严格递增子数组的长度及上个严曾子数组长度
    // 初始化cnt=1,precnt=0, 遍历到nums[i]，若nums[i] > nums[i-1]
    // cnt++, 否则precnt=cnt, cnt=1
    // 满足条件的相邻子数组有两种情况
    // 1. 前一个为precnt, 后一个为cnt, k = min(precnt, cnt)
    // 2. 两个都属于cnt, k = \ceil(cnt / 2)
    // 不断更新k的最大值即可
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,8,9,2,3,4,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,4,4,5,6,7]\n5\n
// @lcpr case=end

 */


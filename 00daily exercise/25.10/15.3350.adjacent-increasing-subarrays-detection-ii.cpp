/*
 * @lc app=leetcode.cn id=3350 lang=cpp
 * @lcpr version=30204
 *
 * [3350] 检测相邻递增子数组 II
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
    // cnt/precnt分别记录当前严格递增子数组的长度，
    // 以及上一个严格递增子数组的长度，分别初始化为1/0
    // 若nums[i] > nums[i - 1], cnt++, 否则precnt=cnt, cnt=1
    // 满足要求的两个相邻子数组有两种情况：
    // 1. 前一个属于precnt, 后一个属于cnt k = min(precnt, cnt)
    // 2. 两个子数组都属于cnt, k=\floor{cnt/2},
    // 根据这两种情况不断更新k即可
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
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
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,8,9,2,3,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,4,4,5,6,7]\n
// @lcpr case=end

 */


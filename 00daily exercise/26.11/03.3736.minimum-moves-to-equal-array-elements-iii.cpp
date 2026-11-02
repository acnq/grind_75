/*
 * @lc app=leetcode.cn id=3736 lang=cpp
 * @lcpr version=30204
 *
 * [3736] 最小操作次数使数组元素相等 III
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
    //  秒杀题：2'45''
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = 0; // max elem in nums;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
        }
        
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += mx - nums[i];
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,5]\n
// @lcpr case=end

 */


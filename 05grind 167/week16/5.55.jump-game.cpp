/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30204
 *
 * [55] 跳跃游戏
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
    // I. 贪心
    // 数组中任意一个位置y, 可以到达等价于是否存在另一个可到达的位置x
    // s.t. x + nums[x] >= y
    // 遍历每个位置，实时维护最远可以到达的距离，对于当前遍历的位置x, 
    // 如果他在最远可以到达的范围内，那么就可以以此为起点到达该位置
    // 遍历过程中，如果最远可到达位置>=数组最后一个位置，就返回true, 
    // 反之，如果遍历结束后最后一个位置仍然不可到达，就返回false。
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
    // I. 反向查找出发位置
    // 我们直接考虑最后一步跳跃前所在的位置
    // 那如果有多个呢？我们“贪心”的选择距离最后一个位置的那个即可
    // tc: O(n^2); sc: O(1)

    // II. 正向查找
    // 贪心的查找每次可以达到的最远距离，但是要提前看1步，不然容易陷入局部最优
    // tc: O(n); sc: O(1)
    int jump(vector<int>& nums) {
        // I.
        // int pos = nums.size() - 1;
        // int steps = 0;
        // while (pos > 0)
        // {
        //     for (int i = 0; i < pos; i++)
        //     {
        //         if (i + nums[i] >= pos)
        //         {
        //             pos = i;
        //             steps++;
        //             break;
        //         }
        //     }
        // }
        // return steps;

        // II.
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end)
                { // end: 上次更新时那个点能到达的最远距离
                    end = maxPos;
                    step++; // 想要走的更远，就得再跳一次。
                }
            }
        }
        return step;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */


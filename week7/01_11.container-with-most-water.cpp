/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30204
 *
 * [11] 盛最多水的容器
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
    // I. 双指针
    // 容纳量 = 两指针指向数字的较小值 * 指针之间的距离
    // 从i,j分别指向数组头尾开始，移动数字较小的指针

    // 正确性证明：
    // 双指针代表了：可以作为容器边界的所有位置的范围
    // 向内移动指针表示，被移动的指针不可能在作为边界了
    // 假设当前左右指针指向x,y; 不失一般性，假设x<=y; 则容量：
    // min(x, y) * t = x * t
    // 如果左指针不变，右指针无论如何移动，容量都不会超过此数
    // 所以他构成了此子问题的上界，要增加这个上界，只能移动左指针
    // 这样的移动“可能的”上界总是增加的，因此一定能返回最大值
    // 另一种思考方法：最开始左右板称为A, B, 如果A短，那么假如最后的结果
    // 含有A,另一块板必须是B,含有的组合都不用再考虑了，所有记录下这个面积之后
    // 直接移动左指针A就可以了

public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans, area);
            if (height[left] <= height[right])
            {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */


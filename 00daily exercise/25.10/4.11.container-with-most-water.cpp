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
    // 左右指针初始指向数组左右两端，
    // 容纳水量 = 两指针中较小值 * 指针间距离
    // 移动指针移动较小值即可，否则容水量只减不增
    // 证明：
    // 1. 双指针代表了什么：可以作为容器边界的所有位置范围
    // 2. 移动指针表示，对应数字的高度不能再作为容器的边界了
    // 3. 为什么：假设左右指针指向的高度数字为x,y, wlog, 假设x <= y
    //      假设二者距离为t，容积 = min(x, y) * t = x * t
    //   如若我们保持左指针位置为x不变，则不论右指针y在哪里，
    //   容器容量都不可能超过xt，假设左移右指针指向的新数字为y'
    //    新距离为t', t' < t(显然)， min(x, y') <= min(x, y)
    //    (y' <= y: min(x, y') <= min(x, y); y' > y: min(x, y') = x = min(x, y))
    //    所以min(x, y') * t' < min(x, y) * t
    //    依次，我们无论如何移动右指针，所得容器容量都小于移动前
    //   为此，要得到一个更大容量，左指针不能再作为容器边界
    //   所以我们丢弃这个位置，将左指针右移，此时新的左指针和原先的右指针才可能作为新边界
    // 如此，问题规模就减小了1，以此类推即可求解
    // tc: O(N), sc: O(1)
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
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


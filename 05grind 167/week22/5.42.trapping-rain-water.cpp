/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
    // I. DP
    // 对于下标i, 下雨后“水能到达的最大高度”等于其两边最大高度的较小值
    // 下标i能接到的雨水量=“水能到达的最大高度” - height[i];
    // DP，在O(n)时间内返回每个位置两边的最大高度
    // 用两个数组leftMax, rightMax, 
    // leftMax[i]表示i及其左边height的最大值
    // leftMax[0] = height[0]; rightMax[n - 1] = height[n - 1]
    // 1 <= i <= n - 1: leftMax[i] = max(leftMax[i - 1], height[i]);
    // 0 <= i <= n - 2: rihgtMax[i] = max(rightMax[i + 1], height[i]);
    // 下标i能接到的雨水 = min(leftMax[i], rightMax[i]) - height[i]

    // II. 单调栈
    // 从左到右遍历数组，遍历到i时，如果栈内至少有两个元素
    // 记栈顶为top, top的下一个为left, height[left] >= height[top](单调小顶栈)
    // 若height[i] > height[top]，则可以得到接水区域
    // 宽度i - left - 1, 高度min(height[left], height[i]) - height[top]
    // top出栈，left变为新的top, 重复直到栈空(如果只剩一个元素则直接出栈)，或者栈顶下标对应的height >= height[i]
    // 计算下标i处的雨水量，将i入栈，继续遍历后面的下编
    // 如果栈内元素只有一个，直接出栈，将i入栈
    // 遍历结束，不论栈内还有没有元素，都可以直接返回结果

    // III. 双指针
    // 我们用两个指针l,r和两个变量lM, rM代替I中的leftMax[i]和rightMax[i]数组
    // 初始化：l=0, r= n-1, lM = rM = 0, l右移r左移，
    // l != r时：
    //      用height[l]和h[r]更新lM(left Max)和rM(rightMax)
    //      若height[l] < height[r], 有lM < rM(可证1), l处能接的雨水= lM - height[l]
    //          将此加到能接的雨水总量，l++;
    //      若height[l] >= height[r], 有lM > rM(可证2), r处能接的雨水= rM - height[r],
    //          将此加到能接的雨水总量，r--;
    //  l,r相遇时，即能获得雨水总量
    // 考虑可证1：l只会在height[l] < height[r]才会右移，所以lM总会<rM, 同理可证2


public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // if (n == 0)
        // {
        //     return 0;
        // }
        // vector<int> leftMax(n);
        // leftMax[0] = height[0];
        // for (int i = 1; i < n; i++)
        // {
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }
        // vector<int> rightMax(n);
        // rightMax[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }
        
        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans += min(leftMax[i], rightMax[i]) - height[i];
        // }
        
        // return ans;

        // II.
        // int ans = 0;
        // stack<int> stk;
        // int n = height.size();
        // for (int i = 0; i < n; i++)
        // {
        //     while (!stk.empty() && height[i] > height[stk.top()])
        //     {
        //         int top = stk.top();
        //         stk.pop();
        //         if (stk.empty())
        //         {
        //             break;
        //         }
        //         int left = stk.top();
        //         int Width = i - left - 1;
        //         int Height = min(height[left], height[i]) - height[top];
        //         ans += Width * Height;
        //     }
        //     stk.push(i);
        // }
        // return ans;

        // III.
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int lM = 0, rM = 0;
        while (l < r)
        {
            lM = max(lM, height[l]);
            rM = max(rM, height[r]);
            if (height[l] < height[r])
            {
                ans += lM - height[l];
                l++;
            } else {
                ans += rM - height[r];
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
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
    // 无论枚举高还是宽，都会有O(N^2), 会超时
    // I. 单调栈
    // 1. 枚举高h = heights[i];
    // 2. 进行左右两边的扩展，扩展的柱子高度均不小于h
    //    i.e., 找到左右两侧最近的高度小于h的柱子，这就是i能扩展到最远的范围
    // 那么如何求出一根柱子左侧且最近的小于其高度的柱子呢？还要枚举么？
    // 我们思考j_0 < j_1 < i, 如果heights[j_0] >= heights[j_1], 那么对i来说
    // 要找到最近的小于其高度的柱子一定不会是j_0, 因为j_1已经把它挡住了
    // 于是我们从左向右遍历的时候，我们直接维护一个最小栈：其中从小到大存放j,
    // 且对于自底向上的j_0, j_1, ..., j_s; height[j_0] < height[j_1] < ... < height[j_s]
    // 我们可以直接过滤掉不满足<关系的相邻j值，后面那个一定会挡住前者，前者不可能作为答案，直接过滤即可
    // 假设我们枚举到i，栈中有j_0:j_s, 如果i左侧最近的小于其高度的柱子为j_i, 得有
    // height[j_0] < height[j_1] < ... < height[j_i] < height[i] <= height[j_{i+1}] < ... < height[j_s]
    // 我们需要用二分查找找到i对应的j_i么？这会O(N logN), 我们直接用O(1)来找到，如何实现呢？
    // 注意到枚举到i+1时，原来的i也变成了j, 会被放入数据结构，而根据最小栈的定义
    // 所以高度大于等于height[i]的j都回直接从数据结构中移除，而这些恰好是j_{i+1}, ......, j_s
    // 还要考虑一种特殊情况，移除了所有栈中的j值之后怎么办？i左侧所有柱子都大于height[i]
    // 我们设定一个哨兵柱子j=-1, height[-1] = -\infin
    // 这真的是O(N)么？直接计算会比较复杂，但是注意到每个位置最多入栈一次，出栈一次，复杂度就是O(N)

    // II. 单调栈+常数优化
    // 我们能否不在左右边界分别遍历，只一次遍历？
    // 可以，i入栈的时候能确定它的左边界，对应的，出栈的时候自然就确定它的右边界
    // 因为i出栈时，遍历的位置i_0有heights[i_0] <= height[i], 而且i_0和i之间也没有其他高度<=height[i]的柱子
    // 那么i_0就是i的右边界。
    // 但是正确的右边界不是应该是<, 这里<=真的可以么？
    // 真的可以，因为最终答案对应的句型中，有若干柱子的高度都等于矩形的高度，最右侧的柱子自然就求出了正确的右边界
    // 而左边界的算法没有改动，最终答案自然就是从最右侧与矩形高度相同的组织求得的，没有影响。
    // 右边界的哨兵同理。
public:
    int largestRectangleArea(vector<int>& heights) {
        // I.
        // int n = heights.size();
        // vector<int> left(n), right(n);

        // stack<int> mono_stk;
        // for (int i = 0; i < n; i++)
        // {
        //     while (!mono_stk.empty() && heights[mono_stk.top()] >= heights[i])
        //     {
        //         mono_stk.pop();
        //     }
        //     left[i] = (mono_stk.empty() ? -1 : mono_stk.top());
        //     mono_stk.push(i);
        // }
        // mono_stk = stack<int>();
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     while (!mono_stk.empty() && heights[mono_stk.top()] >= heights[i])
        //     {
        //         mono_stk.pop();
        //     }
        //     right[i] = (mono_stk.empty() ? n : mono_stk.top());
        //     mono_stk.push(i);
        // }
        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        // }
        // return ans;

        // II.
        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stk;
        for (int i = 0; i < n; i++)
        {
            while (!mono_stk.empty() && heights[mono_stk.top()] >= heights[i])
            {
                right[mono_stk.top()] = i;
                mono_stk.pop();
            }
            left[i] = (mono_stk.empty() ? -1 : mono_stk.top());
            mono_stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */


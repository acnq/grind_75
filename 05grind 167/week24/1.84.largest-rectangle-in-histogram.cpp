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
public:
    // O. 暴力枚举
    // 枚举高，然后从这个高度开始向两侧延伸，直到遇到高度小于h的柱子
    // 这样就确定了w的左右边界w, 进而确定面积w*h, 
    // 但这样有O(N^2), 会超时
    int NaiveLargestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int mid = 0; mid < n; mid++)
        {
            // 枚举高
            int height = heights[mid];
            int left = mid, right = mid;
            // 确定左右边界
            while (left - 1 >= 0 && heights[left - 1] >= height)
            {
                left--;
            }
            while (right + 1 < n && heights[right + 1] >= height)
            {
                right++;
            }
            // 计算面积
            ans = max(ans, (right - left + 1) * height);
        }
        return ans;
    }

    // I. 单调栈
    // 寻找“一根柱子左侧且最近的小于其高度的柱子”的过程可以优化，如下：
    // 显然的引理：已知j0 < j1, h[j0] > h[j1], \forall i, j1<i, j0一定不是i
    // "左侧最近且小于i高度的柱子", 因为j1“挡住”了j0
    // 不妨保存一个数据结构，存放j0, j1, js, 如果有h[j0] < h[j1] < ...... < h[js]
    // 如果出现两个相邻的j*, j*+1违犯<关系，后者就会挡住前者，前面的一切都不需要考虑
    // 如果枚举到i, 且数据结构中有h[j0] < h[j_1] < ... < h[j_i] < h[i] <= h[j_{i+1}] < ... < h[j_s]
    // 那么如何从i中找到j_i, 可以用二分查找，但其实并不需要，
    // 枚举到i+1, i也变成了j, i会被放入j, 所有高度>=h[i]的j都不会作为i+1的答案，直接移除即可
    // 移除的部分就是j_{i+1}, ..., j_s, 这就是单调栈
    // algo:
    //  1. 存放j值， j严格递增，对应高度也严格递增
    //  2. 枚举到h[i]时，不断移除h[j] >= h[i]的j值，移除完毕之后，栈顶的j值就一定满足h[j] < h[i]
    //      此时，j就是i"左侧且最近的小于其高度的柱子"
    //      (特殊情况：如果移出了所以j, i左侧所有高度都大于h[i], 因此需要加入哨兵j=-1, h[j]=INT_MIN)
    //  3. i入栈顶
    // 注意右侧也要相同的做一遍. 哨兵j = N

    // II. 单调栈+常数优化
    // 右侧也要相同的做一遍，吗？
    // 当i出栈的时候，记录遍历到的位置为i_0
    //  此时： 1. h[i_0] <= h[i], 且2. i_0, i之间没有其他高度<= h[i]的柱子
    // (2.证明：如果有i_* h[i_*] <= h[i], 在遇到i_*时，i应该被弹出
    // 所以i_0就是i的右边界
    // 等等，上面我们求的是"一根柱子左/右侧且最近的小于其高度的柱子"
    // 这下我们求的是"一根柱子右侧且最近的小于*等于*其高度的柱子", 这有影响么？
    // 这下我们确实没有办法求出正确的右边界，但对最终答案没有任何影响，为何？
    // 因为我们只是把相等的若干柱子中取了最长的那个而已，最右侧的那根柱子是可以求出正确的右边界的
    // 相当于移动了一下右边界, 而左边界不变，所以和上面方法相比，只是把标号移动了而已
    // 思考例子[6,7,6]; I. 中l[0] = -1; r[0] = 3; l[1] = 0, r[0] = 2; l[2] = -1; r[2] = 3
    //                 II.中l[0] = -1; r[0] = 2; l[1] = 0, r[0] = 2; l[2] = -1; r[2] = 3
    //  0号II中的左边界有问题，但是不妨碍2号是正确的。

    int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // vector<int> left(n), right(n);

        // stack<int> mono_stack;
        // for (int i = 0; i < n; i++)
        // {
        //     while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
        //     {
        //         mono_stack.pop();
        //     }
        //     left[i] = (mono_stack.empty() ? -1: mono_stack.top());
        //     mono_stack.push(i);
        // }
        
        // mono_stack = stack<int>();
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
        //     {
        //         mono_stack.pop();
        //     }
        //     right[i] = (mono_stack.empty() ? n : mono_stack.top());
        //     mono_stack.push(i);
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        // }
        // return ans;

        int n = heights.size();
        vector<int> left(n), right(n, n);
        stack<int> mono_stack;
        for (int i = 0; i < n; i++)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
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


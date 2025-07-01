/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30204
 *
 * [75] 颜色分类
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
    // I. 单指针
    // 第一次遍历中，将所有0交换到数组头部，第二次遍历中，将所有1交换到0之后
    // 我们使用指针ptr表示头部（已经完成交换的部分）

    // II. 双指针
    // 我们用两个指针p_0交换0，p_1交换1，
    // 1. 找到1，就和nums[p_1]交换，p_1后移
    // 2. 找到0，就将其与nums[p_0]交换，p_0，但是这样我们会把一个1交换出去
    //  p_0 < p_1, 1已经连续的放在头部，此时一定会把1交换出去，为此，我们需要
    //             再将nums[i]与nums[p_1]交换，
    // 无论是否p_0 < p_1, 二指针都要后移一位

    // III. 双向双指针
    // p0交换0，p2交换2，我们只要用p2把2交换到数组尾部
    // nums[i]与nums[p2]交换之后，新的nums[i]可能仍然是2，为此，
    // 我们需要不断的将其与nums[p2]交换，直到新的nums[i]不为2
    // 如果nums[i]为0，对应和头交换，为1, 则不做任何操作。
public:
    void sortColors(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // int ptr = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] == 0)
        //     {
        //         swap(nums[i], nums[ptr]);
        //         ptr++;
        //     }
        // }
        // for (int i = ptr; i < n; i++)
        // {
        //     if (nums[i] == 1)
        //     {
        //         swap(nums[i], nums[ptr]);
        //         ptr++;
        //     }
        // }

        // II.
        // int n = nums.size();
        // int p0 = 0, p1 = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] == 1)
        //     {
        //         swap(nums[i], nums[p1]);
        //         p1++;
        //     } else if (nums[i] == 0)
        //     {
        //         swap(nums[i], nums[p0]);
        //         if (p0 < p1)
        //         {
        //             swap(nums[i], nums[p1]);
        //         }
        //         p0++;
        //         p1++;
        //     }
        // }

        // III.
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; i++)
        {
            while (i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                p2--;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */


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
public:
    void sortColors(vector<int>& nums) {
        // I. 单指针
        // 第一次遍历中，0交换到头部，第二次遍历，1交换到0之后
        // 这样2一定在尾部，完成排序

        // ptr表示头部范围，存储整数，0 - 'ptr-1'属于头部
        // ptr初始值为0，第一次遍历，找到0与头部交换
        // 头部向后扩充一个位置，遍历结束后，所有0都被交换到头部
        // 第二次就从头部开始，找到1就和头部交换，头部向后扩充
        // int n = nums.size();
        // int ptr = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] == 0)
        //     {
        //         swap(nums[i], nums[ptr]);
        //         ++ptr;
        //     }
        // }

        // for (int i = ptr; i < n; i++)
        // {
        //     if (nums[i] == 1)
        //     {
        //         swap(nums[i], nums[ptr]);
        //         ++ptr;
        //     }
        // }

        // II 双指针
        // p_0 交换0， p_1交换1，
        // 遇到1则与nums[p_1]交换，p_1后移，和方法I相同
        // 遇到0则与nums[p_0]交换，p_0后移
        // 注意p_0 < p_1时，会把1交换出去，导致错误
        // 故此时nums[i]还要在和nums[p_1]交换，
        // 遇到0时无论p_0 < p_1是否成立，都将二者后移一位
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
        // III. 双指针双向
        // 用p_2交换2，反向移动，如果i遍历超过p_2,则可以直接停止
        // 注意nums[i]与nums[p2]交换后，新的nums[i]可能仍然是2或0，
        // 但此时若交换结束，开始遍历nums[i + 1]，会得到错误答案
        // 因此，遇到2，应当不断与nums[p_2]交换，直到nums[i]非2，
        // 此时如若nums[i]=0,对应第一种情况，nums[i]=1,就不进行任何操作
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


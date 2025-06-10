// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        // 与其让0换到最后（非0元的原顺序会被破坏，恢复很麻烦）
        // 不如让非0元换到前面
        // 保持一个指针指向i第一个0，j指向第一个非0
        // 每次交换(i, j), 之后后移二者，j处理完则终止
        // int n = nums.size();
        // int i = 0, j = 0;
        // while (j < n)
        // {
        //     while (i < n && nums[i] != 0)
        //     {
        //         i++;
        //     }
        //     while (j < n && nums[j] == 0)
        //     {
        //         j++;
        //     }
        //     if (j >= n || i >= n)
        //     {
        //         return;
        //     }
        //     if (j > i)
        //     {
        //         swap(nums[i], nums[j]);
        //         i++;
        //         j++;
        //     } else {
        //         j = i + 1;
        //     }
        // }
        // return;
        // 官方答案：
        // 这里我们不强求i总是指向0，相反，我们让i指向“已交换完元素的下一个元素“
        // j指向第一个非0元素，，j不是0，就和i交换一下（哪怕自己和自己也交换）
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        return;
        // 但感觉官方题解要自己和自己交换，[1,1,1,......, 1, 0]的数组要交换太多，浪费
        // 可能反而是我的更好的一点？
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end


// @lcpr case=start
// [1, 0]\n
// @lcpr case=end
 */


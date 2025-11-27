// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1437 lang=cpp
 * @lcpr version=30204
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
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
    // I. 遍历
    // 原题等价于任意两个相邻的1都至少k个元素，我们只需要从左到右
    // 记录上一个1出现的位置，如果我们找到了新的1，判断于上个1之间至少相隔k个元素
    // 不满足，则返回false，否则继续遍历，遍历完成之后返回True.
    // tc: O(N), sc: O(1)
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // O. 我的实现
        // int n = nums.size();
        // int i = 0, interval = 0;
        // if (k == 0) {
        //     return true;
        // }
        // while (i < n && nums[i] == 0) {
        //     i++;
        // }
        // while (i < n) {
        //     if (i < n - 1 && nums[i] == 1 && nums[i + 1] == 1) {
        //         return false;
        //     }
        //     if (nums[i] == 1) {
        //         i++;
        //         if (interval != 0 && interval < k) {
        //             return false;
        //         }
        //         interval = 0;
        //     }
        //     while (i < n && nums[i] == 0) {
        //         i++;
        //         interval++;
        //     }
        // }

        // return true;
        // I.
        int n = nums.size();
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (prev != -1 && i - prev - 1 < k) {
                    return false;
                }
                prev = i;
            }
        }
        return true;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=kLengthApart
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,0,0,0,1,0,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,1,0,0,1,0]\n2\n
// @lcpr case=end

 */


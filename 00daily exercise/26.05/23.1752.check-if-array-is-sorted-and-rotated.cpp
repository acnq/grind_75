// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 * @lcpr version=30204
 *
 * [1752] 检查数组是否经排序和轮转得到
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
    // 首先检测是否已经非递减排序了，如果是直接返回true
    // 否则，找到第一个i, s.t. nums[i] < nums[i - 1]
    //      检测nums[0:i-1]和nums[i:n-1]是否满足
    // 如果都满足，再检测nums[i:n-1]是否都满足<=nums[0]
    //      i.e. nums[n - 1] <= nums[0]
    // tc: O(n), sc: O(1)
public:
    bool checkTend(vector<int>& nums) {
        // 判断一个数组是否是非递减
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        // 数组 A 在轮转 x 个位置后得到长度相同的数组 B ，
        // 使得对于每一个有效的下标 i，
        // 满足 B[i] == A[(i+x) % A.length]
        // O. 18min 秒杀
        // int n = nums.size();
        // vector<int> B(n, 0);
        // for (int x = 0; x < nums.size(); x++) {
        //     for (int i = 0; i < nums.size(); i++) {
        //         B[i] = nums[(i + x) % nums.size()];
        //     }
        //     if (checkTend(B)) {
        //         return true;
        //     }
        // }
        // return false;

        // I.
        int n = nums.size(), x = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                x = i;
                break;
            }
        }
        if (x == 0) {
            return true;
        }
        for (int i = x + 1; i < n; i++) {
            if (nums[i] < nums[i - 1]){
                return false;
            }
        }
        return nums[0] >= nums[n - 1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=check
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */


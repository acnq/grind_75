/*
 * @lc app=leetcode.cn id=3354 lang=cpp
 * @lcpr version=30204
 *
 * [3354] 使数组元素等于零
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 模拟
    // 枚举nums每个0元素作为初始位置，
    // 分别向两个方向模拟，只有所有元素变为0或者移动到范围外结束
    // tc: O(n^2m), n = nums.size(), m: nums中最大值
    // sc: O(n)
    // II. 前缀和
    // 是一个1d打砖块游戏，每个初始位置，有一个小球左右弹跳
    // 遇到正数则反弹，相应正数--
    // 如果能消除所有正数，假设初始向右，初始位置两边元素或者应该相等
    // 或者右边比左边大一，向左类似，为此我们计算前缀和即可。
    // tc: O(n), sc: O(1)
public:
    bool isValid(const vector<int>& nums, int nonZeros, int start, int dir) {
        // 模拟
        int n = nums.size();
        vector<int> temp(nums);
        int cur = start;

        while (nonZeros > 0 && cur >= 0 && cur < n) {
            if (temp[cur] > 0) {
                temp[cur]--;
                dir *= -1;
                if (temp[cur] == 0) {
                    nonZeros--;
                }
            }
            cur += dir;
        }
        return nonZeros == 0;
    }
    int countValidSelections(vector<int>& nums) {
        // I.
        // int count = 0;
        // int nonZeros = 0;
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     if (nums[i] > 0) {
        //         nonZeros++;
        //     }
        // }

        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == 0) {
        //         if (isValid(nums, nonZeros, i, -1)) {
        //             count++;
        //         }
        //         if (isValid(nums, nonZeros, i, 1)) {
        //             count++;
        //         }
        //     }
        // }

        // return count;

        // II.
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,0,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,0,4,1,0]\n
// @lcpr case=end

 */


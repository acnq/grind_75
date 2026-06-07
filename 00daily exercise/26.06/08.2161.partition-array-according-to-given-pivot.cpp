/*
 * @lc app=leetcode.cn id=2161 lang=cpp
 * @lcpr version=30204
 *
 * [2161] 根据给定数字划分数组
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
    // 遍历nums, 用left/right指向答案数组的最左端和最右端
    // nums遍历时，记当前遍历到的数为x, x<pivot在放入左指针
    // 之后左指针右移，x > pivot, 放入右指针位置，之后右指针左移
    // 细节1： 对于=pivot的值，
    // 我们通过在初始化答案数组时将一切元素赋值为pivot解决
    // 细节2： 大于pivot的值，为了保持相对顺序，需要将他们在答案数组中翻转

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[left] = nums[i];
                left++;
            } else if (nums[i] > pivot) {
                ans[right] = nums[i];
                right--;
            }
        }
        reverse(ans.begin() + right + 1, ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,12,5,10,14,3,10]\n10\n
// @lcpr case=end

// @lcpr case=start
// [-3,4,3,2]\n2\n
// @lcpr case=end

 */


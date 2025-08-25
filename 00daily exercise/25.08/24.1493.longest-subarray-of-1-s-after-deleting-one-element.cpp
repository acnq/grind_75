/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 * @lcpr version=30204
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
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
    // I. 递推
    // 删掉元素之后，最长的且只包含1的非空子数组有两种情况
    // 1. 子数组本身就是连续的，
    // 2. 子数组本不连续，左右两个组合成一个最长的
    // 枚举i, 
    // 维护“以i-1结尾的最长连续全1子数组”和“以i+1为开头的最长连续全1子数组”的长度
    // 枚举i即可可以直接得到答案，为0则对应上文中的1.
    // 记原数组为a
    // 记pre(i)为“以i位结尾的最长连续全1子数组”，则：
    // pre(i) = { 0              a_i = 0
    //          { pre(i - 1) + 1 a_i = 1
    // 记suf(i)为“以i位开头的最长连续全1子数组”，则：
    // suf(i) = { 0              a_i = 0
    //          { suf(i + 1) + 1 a_i = 1
    // tc: O(n), sc: O(n)
    // II. 递推优化
    // 记p0(i): 以i位结尾的最长连续全1子数组，与I.中的pre(i)相同，有
    // p0(i) = { 0,              a_i = 0
    //         { p0(i - 1) + 1   a_i = 1
    // 记p1(i): 以第i位结尾，并且可以在某个位置删除一个0的最长连续全1子数组
    // p1(i) = { p0(i - 1)       a_i = 0 遇到0就把他删除
    //         { p1(i - 1) + 1   a_i = 1 
    // 最后答案即为p1(i)中的最大值，遇到数组中元素全为1的情况，就需要将答案-1
    // 因为我们不得不删除一个1
    // tc: O(n), sc: O(1)
    // 因为p0, p1仅仅和前一项有关，所以直接使用变量即可。
public:
    int longestSubarray(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // vector<int> pre(n), suf(n);
        // pre[0] = nums[0];
        // for (int i = 1; i < n; i++) {
        //     pre[i] = nums[i] ? pre[i - 1] + 1:0;
        // }
        // suf[n - 1] = nums[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     suf[i] = nums[i] ? suf[i + 1] + 1: 0;
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     int preSum = i == 0 ? 0 : pre[i - 1];
        //     int sufSum = i == n - 1 ? 0 : suf[i + 1];
        //     ans = max(ans, preSum + sufSum);
        // }

        // return ans;

        // II.
        int ans = 0;
        int p0 = 0, p1 = 0;
        for (int num: nums) {
            if (num == 0) {
                p1 = p0;
                p0 = 0;
            } else {
                p0++;
                p1++;
            }
            ans = max(ans, p1);
        }
        if (ans == nums.size()) {
            ans--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */


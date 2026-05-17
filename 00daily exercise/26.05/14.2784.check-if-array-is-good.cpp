// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2784 lang=cpp
 * @lcpr version=30204
 *
 * [2784] 检查数组是否是好的
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
    bool isGood(vector<int>& nums) {
        // O. 我的
        // int max_elem = 0;
        // for (int num: nums) {
        //     max_elem = max(num, max_elem);
        // }
        // if (nums.size() != max_elem + 1) {
        //     return false;
        // } else {
        //     unordered_map<int, int> cnt;
        //     for (int num: nums) {
        //         if (cnt.count(num) == 0) {
        //             cnt[num] = 1;
        //         } else {
        //             if (num != max_elem) {
        //                 return false;
        //             } else if (cnt[num] != 1) {
        //                 return false;
        //             }
        //         }
        //     }
        //     for (int i = 0; i < max_elem; i++) {
        //         if (cnt.count(i) == 0) {
        //             return false;
        //         }
        //     }
        // }
        // return true;

        // I.排序： tc: O(nlogn), sc: O(logn) 
        // sort(nums.begin(), nums.end());
        // int n = nums.size() - 1;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] != i + 1) {
        //         return false;
        //     }
        // }
        // return nums[n] == n;

        // II. 统计频数
        int n = nums.size();
        vector<int> count(n, 0);
        for (int a: nums) {
            if (a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=isGood
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2, 1, 3]\n
// @lcpr case=end

// @lcpr case=start
// [1, 3, 3, 2]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1]\n
// @lcpr case=end

// @lcpr case=start
// [3, 4, 4, 1, 2, 1]\n
// @lcpr case=end


// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end
 */


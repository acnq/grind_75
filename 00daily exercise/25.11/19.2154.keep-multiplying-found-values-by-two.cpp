/*
 * @lc app=leetcode.cn id=2154 lang=cpp
 * @lcpr version=30204
 *
 * [2154] 将找到的值乘以 2
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

#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I.排序
    // 如果对nums排序之后，original数值都会比更新前更大
    // 所以我们只需一次从左到右遍历即可。
    // tc: O(nlogn), sc: O(logn)
    // II. 哈希表
    // 类似我的写法
    // tc: O(n), sc: O(n)
public:
    int findFinalValue(vector<int>& nums, int original) {
        // O. 我的写法
        // set<int> st(nums.begin(), nums.end());
        // while (st.find(original) != st.end()) {
        //     original *= 2;
        // }
        // return original;
        // I. 
        // sort(nums.begin(), nums.end());
        // for (int num: nums) {
        //     if (original == num) {
        //         original *= 2;
        //     }
        // }
        // return original;
        // II.
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }
        return original;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,1,12]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9]\n4\n
// @lcpr case=end

 */


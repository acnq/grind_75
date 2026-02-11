/*
 * @lc app=leetcode.cn id=3719 lang=cpp
 * @lcpr version=30204
 *
 * [3719] 最长平衡子数组 I
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
    // I. 暴力
    // 使用两个哈希表维护区间内奇偶数元素出现的次数即可。
    // 每次确定区间左端点时新建哈希表，并在扩展右端点的同时更新结果
    // tc: O(n^2), sc: O(n)
public:
    int longestBalanced(vector<int>& nums) {
        size_t len = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            auto odd = unordered_map<int, int>();
            auto even = unordered_map<int, int>();

            for (size_t j = i; j < nums.size(); j++) {
                auto& c = (nums[j] & 1) ? odd : even; // 判断应该选哪个map
                c[nums[j]]++;

                if (odd.size() == even.size()) {
                    len = std::max(len, j - i + 1);
                }
            }
        }
        return int(len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2099 lang=cpp
 * @lcpr version=30204
 *
 * [2099] 找到和最大的长度为 K 的子序列
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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // 取最大的k个即可, 但是不能改变顺序
        // 看了眼提示：辅助数组vals: 第i个元素：(i, nums[i])
        int n = nums.size();
        vector<int> ans;
        vector<pair<int, int>> vals;

        for (int i = 0; i < n; i++)
        {
            vals.emplace_back(i, nums[i]);
        }
        // 按照数组降序排列
        sort(vals.begin(), vals.end(), [&](auto x1, auto x2) {
            return x1.second > x2.second;
        });

        // 取前k个并按照下标i升序排序
        sort(vals.begin(), vals.begin() + k); // 内置排序就是依照first升序
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(vals[i].second);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,3,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,4,3,3]\n2\n
// @lcpr case=end

 */


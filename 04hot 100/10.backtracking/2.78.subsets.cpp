/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
    // I. 迭代
    // 每种子集选择对应一种二进制串，
    // 我们可以枚举mask \in [0, 2^n - 1], 依次构造子集
    // tc: O(n * 2^n); sc: O(n)

    // II.递归
    // dfs(cur, n): 当前位置cur, 原序列总长度n
    // [0, cur-1]位置确定，[cur, n-1]不确定，从此之中考虑选取a[cur]或者不选，
    // 然后求解dfs(cur + 1， n)
public:
    vector<int> t;
    vector<vector<int>> ans;

    // II.
    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums); // 取nums[cur]
        t.pop_back();
        dfs(cur + 1, nums); // 不取
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // for (int mask = 0; mask < (1 << n); mask++) {
        //     t.clear();
        //     for (int i = 0; i < n; i++) {
        //         if (mask & (1 << i)) {
        //             t.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(t);
        // }    
        // return ans;

        // II.
        dfs(0, nums);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


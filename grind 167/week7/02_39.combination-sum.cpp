/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
    // 回溯法
    // 递归函数 dfs(target, combine, idx):
    // 数组第idx位，还剩target组合，已经组成的列表保存在combine
    // target <= 0 或者candidate被用完则终止
    // 不用idxth个，执行dfs(target, combine, idx + 1)
    // 用idxth个，执行dfs(target - candidates[idx], combine, idx)
    // (因为能重复使用数字，所有下标为idx)
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, 
        vector<int>& combine, int idx) {
        if (idx == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        // 不选择
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择
        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */


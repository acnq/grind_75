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
    // I. 迭代法
    // 用N位二进制串表示子集，a_i=0/1， 0表示不在，1表示在

    // II. 递归法
    // dfs(cur, n)表示当前位置cur, 原序列总长度n
    // 原序列的每个位置答案序列中有在或者不在两种状态，
    // 进入dfs(cur, n) 之前，[0, cur-1]位置确定，
    // 只需要[cur, n - 1]的状态，dfs(cur, n)只需要确定cur的状态
    // 然后求解子问题dfs(cur + 1, n)
public:
    vector<int> t;
    vector<vector<int>> ans;

    // II 中的递归函数
    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size())
        {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]); // 需要cur
        dfs(cur + 1, nums);
        t.pop_back(); // 回溯
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // int n = nums.size();
        // for (int mask = 0; mask < (1 << n); mask++)
        // {
        //     t.clear();
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (mask & (1 << i)) // 取mask的第i位
        //         {
        //             t.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(t);
        // }
        // return ans;

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


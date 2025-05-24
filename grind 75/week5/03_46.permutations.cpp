/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    // 同样使用回溯法
    // 定义递归函数backtrack(first, output)表示从左往右填到第first个位置时，当前排列为Output
    // 函数分为两个情况
    // first = n: 填完了n个位置，找到可行解，Output放入答案，递归结束
    // first < n: 用vis标记数组来标记已经填过的数，
    //      没有标记过，尝试填入，并将其标记，调用backtrack(first + 1, output)
    //  回溯的时候撤销这个位置填的数以及标记
    // vis可以用nums的分划来表示，[0, first - 1]表示已经填过的数的集合vis
    // [first, n - 1]待填的数的集合，填完以后将第i个数和第first个数交换，
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        // 填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; i++)
        {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


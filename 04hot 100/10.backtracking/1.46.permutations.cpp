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
    // I. 回溯
    // 递归函数backtrack(first, output), 
    // 表示从左往右已经填到了第first个位置, 当前排列为output,
    // 递归分为两种情况：
    // 1. first = n: 填完n个位置，找到可行解，Output放入答案数组
    // 2. first < n: 考虑要填入的数，因为不能重复，我们设置数组vis标记已填入的
    //               从没有被标记的数中填入，尝试下一个位置（调用backtrack(first + 1, output)
    //               回溯回来的时候要撤销这个位置填的数字以及标记（恢复现场）并尝试其他
    // 那么标记数组可以去掉么？
    // 可以的，只需要将nums划分为左右两个部分，左边表示已填的，右边表示待填的，回溯的同时动态维护这个划分即可
    // 具体，如果我们从[first, n - 1]选了全局下标为i的数字，填完之后将第i个数和第first个交换
    // 这时[0, first]部分又都是已填的，[first + 1, n - 1]都是待填的，回溯的时候需要交换回来
    // tc: O(n * n!); sc: O(n)
public:

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        if (first == len)
        { // 所有都填完
            res.emplace_back(output);
            return;
        }

        for (int i = first; i < len; i++) {
            // 动态维护
            swap(output[i], output[first]);
            // 递归填写下一个
            backtrack(res, output, first + 1, len);
            // 回溯恢复现场
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


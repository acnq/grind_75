/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 * @lcpr version=30204
 *
 * [2033] 获取单值网格的最小操作数
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
    // I. 找中位数
    // 任意两个元素之差必须是x的倍数，否则无法使他们相等
    // 遍历网格，所有元素取出放入一堆数组nums, 检查
    // (grid[i][j] - grid[0][0]) mod x 是否=0，
    // 如果存在不满足的直接返回-1
    // 然后按照nums排序，nums[i]变为目标值t的操作次数为
    // |nums[i] - t| / x, 问题等价于最小化\sum_i|nums[i] - t|
    // t取排序后数组中位数得到绝对值之和的最小值
    // 令choose = nums[\floor{mn / 2}], 之后遍历nums,
    // 每个元素num到choose的操作次数|num - choose| / x 累加到答案中即可
    // tc: O(mn log(mn)), sc: O(mn)
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] - grid[0][0]) % x != 0) {
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int choose = nums[nums.size() / 2];
        int ans = 0;
        for (int num: nums) {
            ans += abs(num - choose) / x;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4],[6,8]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,5],[2,3]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 * @lcpr version=30204
 *
 * [3195] 包含所有 1 的最小矩形面积 I
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
    // I. 一次遍历
    // 我们要找到1出现的上下左右边界，依次计算面积
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_i = n, max_i = 0;
        int min_j = m, max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0]]\n
// @lcpr case=end

 */


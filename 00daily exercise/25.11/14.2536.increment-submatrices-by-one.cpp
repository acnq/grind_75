/*
 * @lc app=leetcode.cn id=2536 lang=cpp
 * @lcpr version=30204
 *
 * [2536] 子矩阵元素加 1
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
    // I. 二位差分 + 前缀和
    // 一次操作对差分数组的影响其实只是对如下四个角的影响：
    // diff[row1][col1] += 1; diff[row2 + 1][col1] -= 1
    // diff[row1][col2 + 1] -= 1; diff[row2 + 1][col2 + 1] += 1
    // 其中
    // mat[i][j] = diff[i][j] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]
    // sc = tc = O(n^2)
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector diff(n + 1, vector<int>(n + 1));

        for (const auto& query: queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }

        vector mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,1,2,2],[0,0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0,1,1]]\n
// @lcpr case=end

 */


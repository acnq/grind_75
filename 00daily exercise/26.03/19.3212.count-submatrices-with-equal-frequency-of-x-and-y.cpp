/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 * @lcpr version=30204
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
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
    // I. 二维前缀和
    // grid[0][0]需要被包含,所以只需要知道右下角元素就可以确定一个子矩阵
    // X, Y频数相等,我们只要X计数+1,Y计数-1,.计数为0
    // 则子矩阵的总计数为0,就可以得到X,Y频数相等的条件
    // 还要判断是否包含至少一个X,我们可以在前缀和矩阵中开辟一个维度判断
    // grid[i][j] = X, 则此(i,j为右下角的)子矩阵包含X
    // grid[i][j] != X, 递归判断(i-1,j)和(i, j-1)是否包含X,有一则有
    // 
    // tc = sc: O(mn)
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<array<int, 2>>> sum(n + 1, vector<array<int, 2>>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                    sum[i + 1][j + 1][1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                } else {
                    sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                }
                ans += (!sum[i + 1][j + 1][0] && sum[i + 1][j + 1][1]) ? 1: 0;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["X","Y","."],["Y",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [["X","X"],["X","Y"]]\n
// @lcpr case=end

// @lcpr case=start
// [[".","."],[".","."]]\n
// @lcpr case=end

 */


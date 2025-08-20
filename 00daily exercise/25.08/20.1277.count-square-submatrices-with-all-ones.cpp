/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 * @lcpr version=30204
 *
 * [1277] 统计全为 1 的正方形子矩阵
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
    // f[i][j] = min(f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]) + 1
    // f[i][j] = { matrix[i][j]         if i = 0 || j = 0
    //           { 0                    if matrix[i][j] = 0
    //           { min(f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]) + 1, else
    // 感觉类似的做过
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    f[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 0) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j -1]}) + 1;
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,1],[1,1,1,1],[0,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */


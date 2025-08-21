/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 * @lcpr version=30204
 *
 * [1504] 统计全 1 子矩形
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
    // I. 枚举
    // row[i][j]: (i, j)向左延伸到的连续1的个数，可以得到：
    // row[i][j] = { 0                  mat[i][j] = 0
    //             { row[i][j - 1] + 1  mat[i][j] = 1
    // 然后统计(i, j)为右下角满足条件的子矩形，我们可以枚举子矩形的高
    // 从下向上枚举row[i], 两行都为1则满足条件
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; --k) {
                    cur = min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,1,1,1],[1,1,1,0]]\n
// @lcpr case=end

 */


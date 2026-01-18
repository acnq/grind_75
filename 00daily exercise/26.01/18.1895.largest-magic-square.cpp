/*
 * @lc app=leetcode.cn id=1895 lang=cpp
 * @lcpr version=30204
 *
 * [1895] 最大的幻方
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
    // I. 枚举正方形+前缀和优化
    // 假设我们按照从小到大的顺序枚举正方形变成edge, 
    // 再枚举grid中所有边长为edge的正方形
    // 一次满足他们是否为幻方，那么这样做的时间复杂度如何？
    // l = min(m, n), edge \in [1, l], 边长为edge的正方形有
    // (m - edge + 1)(n - edge + 1) = O(mn)个，每个正方形
    // 我们又要计算每行、列、对角线的和，共有edge行，edge列，2条对角线
    // 计算需要的tc：((2 * edge + 2) * edge) = O(l^2), 总tc: O(l^3mn)
    // 为此，我们预处理矩阵grid每行每列的前缀和，这样求行和和列和为O(1)
    // 求所有行列的时间为O(l), 总tc降为O(l^2mn)
    // 另外，我们只需要在[2, l]的范围内遍历edge即可，因为边长为1的正方形必是幻方
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 行的前缀和
        vector<vector<int>> rowsum(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // 列的前缀和
        vector<vector<int>> colsum(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // 从大到小枚举edge：第一个返回的一定是最大的
        for (int edge = min(m, n); edge >= 2; edge--) {
            // 枚举正方形左上角位置(i, j)
            for (int i = 0; i + edge <= m; i++) {
                for (int j = 0; j + edge <= n; j++) {
                    // 计算行列对角线的值，以第一行为样本
                    int stdsum = rowsum[i][j + edge - 1] - (j ? rowsum[i][j - 1] : 0);
                    bool check = true;
                    // 枚举每一行并用前缀和求和
                    // 跳过第一行
                    for (int ii = i + 1; ii < i + edge; ii++) {
                        if (rowsum[ii][j + edge - 1] - (j ? rowsum[ii][j - 1] : 0) != stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }
                        // 枚举列前缀和求和
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (colsum[i + edge - 1][jj] - (i ? colsum[i - 1][jj] : 0) != stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }
                    // d1/d2表示两条对角线，d for diagonal
                    int d1 = 0, d2 = 0;
                    // 直接遍历
                    for (int k = 0; k < edge; k++) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }
                    if (d1 == stdsum && d2 == stdsum) {
                        return edge;
                    }
                }
            }
        }
        return 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,3,1],[9,3,3,1],[1,3,3,8]]\n
// @lcpr case=end

 */


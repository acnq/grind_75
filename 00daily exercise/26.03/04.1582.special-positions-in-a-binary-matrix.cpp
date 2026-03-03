/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 * @lcpr version=30204
 *
 * [1582] 二进制矩阵中的特殊位置
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
    // I. 模拟
    // 特殊位置(i, j) := mat[i][j] = 1, 且mat[i][k] = mat[l][j] = 0, \forall k != j, l != j
    // 我们注意到矩阵只能包含0/1, 我们可以预处理每一行和列的和来快速得到每一行和列中1的个数
    // tc: O(m * n), sc: O(m + n)

    // II. 列标记
    // 定义第j列的列标记为：该列中所有1所在行中的1的数量和，
    // 则(i, j)特殊当且仅当j列标记值为1
    // 特殊位置的数量就是最后标记值为1的列的数量
    // 我们用原始矩阵第一行作为我们标记列的额外空间
    // tc: O(m * n), sc: O(1)
public:
    int numSpecial(vector<vector<int>>& mat) {
        // I.
        // int m = mat.size(), n = mat[0].size();
        // vector<int> rowSum(m);
        // vector<int> colSum(n);

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         rowSum[i] += mat[i][j];
        //         colSum[j] += mat[i][j];
        //     }
        // }

        // int res = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
        //             res++;
        //         }
        //     }
        // }

        // return res;

        // II.
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int cnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cnt1++;
                }
            }
            if (i == 0) {
                cnt1--; // 自己这行的1不能算上
            }
            if (cnt1 > 0) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1) {
                        mat[0][j] += cnt1;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mat[0][i] == 1) {
                sum++;
            }
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0],[0,0,1],[1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */


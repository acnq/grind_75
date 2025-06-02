// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30204
 *
 * [221] 最大正方形
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
    // I.
    // 看题解说暴力能做，不管别的先暴力再说
    // 其实是因为想动态规划半天想不出来，发现总是会退化到某种暴力算法上
    // 好像是骗人的，还是超时
    // II. DP 
    // dp(i, j): (i,j)为右下角，只包含1的正方形的边长最大值
    // dp(i, j) = 0 (若mat[i][j] = 0)
    // dp(i, j) = min(dp(i - 1, j), dp(i - 1, j - 1), dp(i, j - 1)) + 1 (若mat[i][j] = 1)
    // dp(0, j) = dp(i, 0) = 1
    // 关键点是两个：
    // 1. 要枚举边长，而不是面积
    // 2. 不能只想到dp(i - 1, j - 1)
public:
    bool isAll1(int starti, int startj, int d, vector<vector<char>> matrix){
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (starti + i >= matrix.size() || startj + j >= matrix[0].size() || matrix[starti + i][startj + j] == '0')
                {
                    return false;
                }
            }
        }
        return true;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        // int n = matrix.size(), m = matrix[0].size();
        // int maxMatEdge = min(n, m);
        // int maxd = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     { // 首先枚举顶点，如果不是1，就直接跳过
        //         if (matrix[i][j] == '1')
        //         {
        //             // 枚举边长
        //             int d = 1;
        //             while (d <= maxMatEdge && isAll1(i, j, d + 1, matrix))
        //             {
        //                 d++;
        //             }
        //             maxd = max(d, maxd);
        //         }
        //     }
        // }
        // return maxd * maxd;
        // 上述暴力法太过暴力，还是会超时
        // int maxSide = 0;
        // int rows = matrix.size(), columns = matrix[0].size();
        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < columns; j++)
        //     {
        //         if (matrix[i][j] == '1')
        //         {
        //             maxSide = max(maxSide, 1);
        //             // 计算最大边长
        //             int currentSide = min(rows - i, columns - j);
        //             for (int k = 0; k < currentSide; k++)
        //             {
        //                 // 判断新增的“一行一列”是否均为1
        //                 bool flag = true;
        //                 if (matrix[i + k][j + k] == '0')
        //                 {
        //                     break;
        //                 }
        //                 for (int m = 0; m < k; m++)
        //                 {
        //                     if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0')
        //                     {
        //                         flag = false;
        //                         break;
        //                     }
        //                 }
        //                 if (flag)
        //                 {
        //                     maxSide = max(maxSide, k + 1);
        //                 } else {
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        // int maxSquare = maxSide * maxSide;
        // return maxSquare;
        // 也会超时
        int maxSide = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","0"],["1","0"]]\n
// @lcpr case=end


// @lcpr case=start
// [["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]\n
// @lcpr case=end

 */


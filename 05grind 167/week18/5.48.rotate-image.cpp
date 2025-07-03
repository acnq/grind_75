// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
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
    // 使用螺旋算法，额外开辟一个O(N)的数组
    // I. 额外数组
    // Thrm: 矩阵中的第i行第j个元素，旋转后出现在倒数第j列第i个元素
    // matrix[r][c] -> matrix'[c][n - r - 1]
    // 这样额外矩阵可以解决， SC = TC: O(N^2)
    
    // II. 原地旋转
    // tmp = matrix[r][c]
    // matrix[r][c] = matrix[n - c - 1][r]
    // matrix[n - c - 1][r] = matrix[n - r - 1][n - c - 1]
    // matrix[n - r - 1][n - c - 1] = matrix[c][n - r - 1]
    // matrix[c][n - r - 1] = tmp
    // 和我的写法一样， 但是官方这里用的是 r < n / 2; c < (n + 1) / 2
    // 实际上是写成了分块矩阵

    // III. 翻转代替旋转
    // 所谓旋转就是水平轴翻转 + 主对角线翻转
    // 轴翻转: matrix[r][c] -> matrix[n - r - 1][c]
    // 主对角翻转：matrix[r][c] -> matrix[c][r]
    // 联立即得I中的等式

public:
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int lim = n / 2;
        // vector<int> tmp(n, 0);

        // // for(int i = 0; i < n - 1; i++) {
        // //     tmp[i] = matrix[0][i];
        // //     matrix[0][i] = matrix[n - i - 1][0];
        // //     matrix[n - i - 1][0] = matrix[n - 1][n - i - 1];
        // //     matrix[n - 1][n - i - 1] = matrix[i][n - 1];
        // //     matrix[i][n - 1] = tmp[i];
        // // }

        // for(int l = 0; l < lim; l++) {
        //     for(int i = l; i < n - 1 - l; i++) {
        //         tmp[i] = matrix[l][i]; // 你这一步根本不需要数组，用个变量就可以了
        //         matrix[l][i] = matrix[n - i - 1][l];
        //         matrix[n - i - 1][l] = matrix[n - 1 - l][n - i - 1];
        //         matrix[n - 1 - l][n - i - 1] = matrix[i][n - 1 - l];
        //         matrix[i][n - 1 - l] = tmp[i];
        //     }
        // }

        // return;
        // 大约40min, 边界条件运算有点太复杂了。。。
        // I.
        // int n = matrix.size();
        // auto matrix_new = matrix; // 值拷贝
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         matrix_new[j][n - i - 1] = matrix[i][j];
        //     }
        // }
        // matrix = matrix_new;
        // return;
        // III.
        int n = matrix.size();
        // 水平翻转
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        } 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */


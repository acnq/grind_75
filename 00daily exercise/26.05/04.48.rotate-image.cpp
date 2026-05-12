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
    // I. 逐元素轮换
    // 注意到第i行的第j个元素，在旋转后，到倒数第i列的第j行
    // matrix_new[col][n - row - 1] = matrix[row][col]
    // 为了防止覆盖，我们有
    // temp = matrix[col][n - row - 1]
    // matrix[col][n - row - 1] = matrix[row][col]
    // 重复四次，我们有
    // temp                             = matrix[row][col]
    // matrix[row][col]                 = matrix[n - col - 1][row]
    // matrix[n - col - 1][row]         = matrix[n - row - 1][n - col - 1]
    // matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1]
    // matrix[col][n - row - 1]         = temp
    // n 为偶数，枚举n^2 / 4 个位置
    // n 为奇数，枚举(n^2 - 1) / 4 个位置
    // tc； O(N^2), sc： O(1)
    // 
    // II. 翻转
    // matrix[row][col] =(水平翻转)=> matrix[n - row - 1][col]
    //                  =(主对角线翻转)=> matrix[col][n - row - 1]
public:
    void rotate(vector<vector<int>>& matrix) {
        // I. 
        // int n = matrix.size();
        // for (int i = 0; i < n / 2; i++) {
        //     for (int j = 0; j < (n + 1) / 2; j++) {
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[n - j - 1][i];
        //         matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        //         matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        //         matrix[j][n - i - 1] = temp;
        //     }
        // }

        // II.
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
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


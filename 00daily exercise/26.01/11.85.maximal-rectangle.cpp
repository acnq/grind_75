/*
 * @lc app=leetcode.cn id=85 lang=cpp
 * @lcpr version=30204
 *
 * [85] 最大矩形
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
    // I. 柱状图优化
    // 计算出矩阵每个元素左边连续1的数量：
    //  left[i][j]: 矩阵i行j列元素左侧连续1的数量
    // 考察以matrix[i][j]为右下角的矩形时，我们枚举满足0<=k<=i的所有k
    // 矩阵最大宽度就是：min(left[i][j], left[i-1][j], ......, left[k][j])
    // tc: O(mn) + O(mn) * O(m) = O(m^2n); sc: O(mn)
    // II. 单调栈
    // 我们引用84的单调栈方案计算柱状图的最大面积
    // 可以参考：'02grind 75\week8\10_84.largest-rectangle-in-histogram.cpp'和
    //          '04hot 100\12.stack\5.84.largest-rectangle-in-histogram.cpp'
    // 这里直接copy了T84的代码
    // tc = sc: O(mn)
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // I.
        // int m = matrix.size();
        // if (m == 0) {
        //     return 0;
        // }
        // int n = matrix[0].size();
        // vector<vector<int>> left(m, vector<int>(n, 0));

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == '1') {
        //             left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
        //         }
        //     }
        // }

        // int ret = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == '0') {
        //             continue;
        //         }
        //         int width = left[i][j];
        //         int area = width;
        //         for (int k = i - 1; k >= 0; k--) {
        //             width = min(width, left[k][j]);
        //             area = max(area, (i - k + 1) * width);
        //         }
        //         ret = max(ret, area);
        //     }
        // }
        // return ret;
        // II.
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) {
            // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1"]]\n
// @lcpr case=end

 */


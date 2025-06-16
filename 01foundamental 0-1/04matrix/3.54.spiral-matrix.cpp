// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    // 剥最外层，
    // I. 模拟：
    // 通过方向变量控制转弯，遇到边界或者遇到之前访问过的则转弯
    // II. 层级模拟
    // 和我自己的思路很想，不同的是，我们第一步总是剥完一行，
    // 第二第四步总是剥长度为n - 1的一列，第三步总是剥长度n - 2的一列
    // 这样就一行或者一列就不用特殊考虑了
    // -----
    // |   |
    // |---|
public:
    // I
    static constexpr int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size();
        // int lim = min(m, n);
        // vector<int> ans;
        // if(m == 1) {
        //     return matrix[0];
        // }
        // if(n == 1) {
        //     for(int i = 0; i < m; i ++) {
        //         ans.push_back(matrix[i][0]);
        //     }
        //     return ans;
        // }

        // // 最外层
        // for(int l = 0; lim - 2 * l - 1 >= 0; l++) {
        //     if(l == n - 1 - l && l == m - 1 - l) {
        //         // 处理只有一个元素的特殊情况
        //         ans.push_back(matrix[l][l]); 
        //     } else if(l == n - l - 1) {
        //         // 只有一列，仿n == 1:
        //         for(int i = l; i < m - l; i++) {
        //             ans.push_back(matrix[i][l]);
        //         }
        //     } else if (l == m - l - 1) {
        //         // 只有一行，仿m == 1
        //         for(int j = l; j < n - l; j++) {
        //             ans.push_back(matrix[l][j]);
        //         }
        //     } else {
        //         for(int j = l; j < n - 1 - l; j++) {
        //             ans.push_back(matrix[l][j]);
        //         }
        //         for(int i = l; i < m - 1 - l; i++) {
        //             ans.push_back(matrix[i][n - 1 - l]);
        //         }
        //         for(int j = n - 1 - l; j > l; j--) {
        //             ans.push_back(matrix[m - 1 - l][j]);
        //         }
        //         for(int i = m - 1 - l; i > l; i--) {
        //             ans.push_back(matrix[i][l]);
        //         }
        //     }
        // }
        // return ans;
        // // 写了55分钟，感觉边界控制太难了

        // int rows = matrix.size(), cols = matrix[0].size();
        // vector<vector<bool>> vised(rows, vector<bool>(cols));
        // int ttl = rows * cols;
        // vector<int> order(ttl);

        // int r = 0, c = 0;
        // int dIdx = 0;
        // for(int i = 0; i < ttl; i++) {
        //     order[i] = matrix[r][c];
        //     vised[r][c] = true;
        //     int nxtR = r + d[dIdx][0], nxtC = c + d[dIdx][1];
        //     if(nxtR < 0 || nxtR >= rows || nxtC < 0 || nxtC >= cols || vised[nxtR][nxtC]) {
        //         dIdx = (dIdx + 1) % 4;
        //     }
        //     r += d[dIdx][0];
        //     c += d[dIdx][1];
        // }
        // return order;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> order;
        int left = 0, right = n - 1, top = 0, bottom = m - 1; 
        // 先定位四个角
        while(left <= right && top <= bottom) {
            // 这样判断边界就简单了，而且while比for直观
            for(int col = left; col <= right; col++) {
                order.push_back(matrix[top][col]);
            }
            for(int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if(left < right && top < bottom) {
                for(int col = right - 1; col > left; col--) {
                    order.push_back(matrix[bottom][col]);
                }
                for(int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[6,9,7]]\n
// @lcpr case=end


// @lcpr case=start
// [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end


 */


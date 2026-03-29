/*
 * @lc app=leetcode.cn id=3546 lang=cpp
 * @lcpr version=30204
 *
 * [3546] 等和矩阵分割 I
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
    // I. 二维前缀和 + 枚举边界元素
    // 假设我们得到二位前缀和矩阵为sum[m][n], 我们通过以下方式判断
    // 1. 竖直分割线:
    //  枚举前缀和矩阵边界上的元素sum[m][i]
    // (以grid[0][0]为左上角, 以grid[m - 1][i - 1]为右下角的元素和)
    // 如果这个值等于总和的一半,则说明分割线存在
    // 2. 水平分割线:
    //  同理可得, 枚举元素sum[i][n]
    //
    // tc = sc = O(mn)
    // II. 旋转矩阵 + 枚举上半矩阵和
    // 注意2其实可以让矩阵旋转90°即可
    // tc = sc = O(mn)
public:
    // II. 旋转90°
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        // I.
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<long long>> sum(m + 1, vector<long long>(n + 1, 0));
        // long long total = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
        //         total += grid[i][j];
        //     }
        // }
        // for (int i = 0; i < m - 1; i++) {
        //     if (total == sum[i + 1][n] * 2) {
        //         return true;
        //     }
        // }

        // for (int i = 0; i < n - 1; i++) {
        //     if (total == sum[m][i + 1] * 2) {
        //         return true;
        //     }
        // }

        // return false;

        // II
        long long total = 0;
        long long sum;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        for (int k = 0; k < 2; k++) {
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,4]]\n
// @lcpr case=end

 */


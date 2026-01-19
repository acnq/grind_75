/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 * @lcpr version=30204
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
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
    // O. 二维前缀和
    // 假设二维数组A的大小为m * n, 行范围[1, m], 列范围[1, n] (从1开始编号)
    // A的前缀和数组P, 满足如下，对于每个元素P[i][j]:
    //  i > 0 && j > 0: P[i][j]: A中(1, 1)为左上角，(i, j)为右下角的矩形元素之和
    //  i = 0 || j = 0: P[i][j] = 0
    // sum = A[x1:x2][y1:y2] (A以(x1, y1)为左上角(x2, y2)为右下角的矩形元素之和可以用P快速求出)
    //     = P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1]
    // 求P的过程可以使用类似的方法
    // P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + A[i][j]
    // (移项之后就是考虑A(i, j)这个1*1的矩形区域A[i:i][j:j])
    // (A[i][j] = P[i][j] - P[i - 1][j] - P[i][j - 1] + P[i - 1][j - 1])
    // 所以计算P[i][j]用时O(1), 计算P用时O(MN)
    // 
    // I. 二分查找
    // 计算mat的前缀和数组P, 枚举mat中的正方形，计算每个正方形的元素和
    // 假设mat大小为m * n, 正方形左上角可以使mat中的任意位置，边长不会超过min(m, n)
    // 三重循环枚举所有正方形，用时O(MN * min(M, N)), 借助P在O(1)内计算正方形元素和
    // 总用时也是O(MN * min(M, N))，容易超时，
    // 考虑到mat所有元素非负，若存在一个边长为c且元素不超过阈值的正方形
    // 那么边长为1,2, ......, c - 1且元素和不超过阈值的正方形也是存在的
    // (在边长为c的那个正方形中取即可)，这样我们可以二分查找，找出最大的边长c
    // 上界为min(m, n), 下界为1，二分找到c', 枚举mat中所有边长为c'的正方形即可
    // tc: O(MN*log(min(M, N))), sc: O(MN)
    // 
    // II. 枚举优化
    // 如果边长为c的正方形元素已经超过阈值，那么我们就没有必要枚举更大了
    // 如果我们前两重枚举到(i, j)前已经找到了边长为c'的正方形，
    //     那么在枚举(i, j)为左上角的正方形时，忽略所有边长<=c'的正方形，从c'+1开始枚举
    // tc: O(min(M, N) + MN) = O(MN), sc: O(MN)
public:
    // I. && II.
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // I.
        // int m = mat.size(), n = mat[0].size();
        // vector<vector<int>> P(m + 1, vector<int>(n + 1));
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        //     }
        // }

        // int l = 1, r = min(m, n), ans = 0;
        // while (l <= r) {
        //     int mid = (l + r) / 2;
        //     bool find = false;
        //     for (int i = 1; i <= m - mid + 1; i++) {
        //         for (int j  = 1; j <= n - mid + 1; j++) {
        //             if (getRect(P, i, j, i + mid - 1, j + mid - 1) <= threshold) {
        //                 find = true;
        //             }
        //         }
        //     }
        //     if (find) {
        //         ans = mid;
        //         l = mid + 1;
        //     } else {
        //         r = mid - 1;
        //     }
        // }
        // return ans;

        // II. 
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int r = min(m, n), ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int c = ans + 1; c <= r; c++) {
                    if (i + c - 1 <= m && j + c - 1 <= n && getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]\n1\n
// @lcpr case=end

 */


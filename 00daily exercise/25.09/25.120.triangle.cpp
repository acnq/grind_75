/*
 * @lc app=leetcode.cn id=120 lang=cpp
 * @lcpr version=30204
 *
 * [120] 三角形最小路径和
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
    // I. DP
    // f[i][j]: 走到位置(i, j)最小路径和(第i行第j列，均从0开始编号)
    // 根据规则，走到位置(i, j)，上一步只能在(i - 1, j - 1)或者(i - 1, j)
    // f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + c[i][j]
    // c[i][j]: (i, j)位置对应的元素值
    // f[i][0] = f[i - 1][0] + c[i][0] (最左侧)
    // f[i][i] = f[i - 1][i - 1] + c[i][i] (最右侧)
    // f[0][0] = c[0][0] 边界条件 
    // tc = sc: O(n^2)
    // II. DP + 空间优化
    // 因为f[i][j]只和f[i - 1][:]有关，所以我们不必要存储无关状态
    // 我们构建两个一维数组即可
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // I.
        // int n = triangle.size();
        // vector<vector<int>> f(n, vector<int>(n));
        // f[0][0] = triangle[0][0];
        // for (int i = 1; i < n; i++) {
        //     f[i][0] = f[i - 1][0] + triangle[i][0];
        //     for (int j = 1; j < i; j++) {
        //         f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
        //     }
        //     f[i][i] = f[i- 1][i - 1] + triangle[i][i];
        // }
        // return *min_element(f[n - 1].begin(), f[n - 1].end());

        // II.
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            int cur = i % 2;
            int prev = 1 - cur;
            f[cur][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                f[cur][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            }
            f[cur][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2],[3,4],[6,5,7],[4,1,8,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[-10]]\n
// @lcpr case=end

 */


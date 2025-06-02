// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    // I. 
    // dp[n][m] = { dp[n - 1][m] + tri[n][m]; m == 0 (行首)
    //            { min(dp[n - 1][m], dp[n - 1][m - 1]) + tri[n][m], else
    //            { dp[n - 1][m - 1] + tri[n][m]; m == n - 1 (行尾)
    // res = min_m(dp[n][m]);
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size(), m = triangle[n - 1].size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // dp[0][0] = triangle[0][0];
        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 0; j <= i; j++)
        //     {
        //         if (j == 0)
        //         {
        //             dp[i][j] = dp[i - 1][j] + triangle[i][j];
        //         } else if (j == i)
        //         {
        //             dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        //         } else 
        //         {
        //             dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        //         }
        //     }
        // }
        // int res = INT_MAX;
        // for (int i = 0; i < m; i++)
        // {
        //     res = min(dp[n - 1][i], res);
        // }
        // return res;
        // 空复O(n^2)

        // II. 滚动数组优化1.
        // int n = triangle.size();
        // vector<vector<int>> f(2, vector<int>(n));
        // f[0][0] = triangle[0][0];
        // for (int i = 1; i < n; i++)
        // {
        //     int curr = i % 2;
        //     int prev = 1 - curr;
        //     f[curr][0] = f[prev][0] + triangle[i][0];
        //     for (int j = 1; j < i; j++)
        //     {
        //         f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
        //     }
        //     f[curr][i] = f[prev][i - 1] + triangle[i][i];
        // }
        // return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
        // 空复O(2n)

        // III. 滚动数组优化2.
        // 从i:0递减枚举j, 此时计算(i, j), f[j + 1]到f[i]已经是i行的值，需要计算的是f[0:j]
        // thus, f[j] = min(f[j - 1], f[j]) + c[i][j]
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--)
            {
                f[j] = min(f[j - 1], f[j])  + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
        // 空复O(n)
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


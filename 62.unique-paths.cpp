/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30204
 *
 * [62] 不同路径
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
    // I. dp
    // f(i, j) 从左上角走到(i, j)的路径数量i \in [0, m), j \in [0, n)
    // f(i, j) = f(i - 1, j) + f(i, j - 1)
    // f(0, 0) = 1, 返回答案为f(m - 1, n - 1)
    // f(0, j) = f(i, 0) = 1, \forall i, j;

    // II. 滚动数组
    // f(i, j)仅仅和第i行和第i-1行的状态有关，用滚动数组改进
    
    // III. 组合数学
    // 需要m - 1次向下移动，n - 1次向右移动，路径总数
    // 就是$C_{m + n - 2}^{m - 1} = \frac{(m + n - 2)(m + n - 3) ......n}{(m - 1)!}$

public:
    int uniquePaths(int m, int n) {
        // I.
        // vector<vector<int>> f(m, vector<int>(n));
        // for (int i = 0; i < m; i++)
        // {
        //     f[i][0] = 1;
        // }
        // for (int j = 0; j < n; j++)
        // {
        //     f[0][j] = 1;
        // }
        // for (int i = 1; i < m; i++)
        // {
        //     for (int j = 1; j < n; j++)
        //     {
        //         f[i][j] = f[i - 1][j] + f[i][j - 1];
        //     }
        // }
        // return f[m - 1][n - 1];

        // II. 
        // vector<int> f(n, 1);
        // for (int i = 1; i < m; i++)
        // {
        //     for (int j = 1; j < n; j++)
        //     {
        //         f[j] += f[j - 1];
        //     }
        // }
        // return f[n - 1];

        // III.
        long long ans = 1;
        for (int x = n, y = 1; y < m; x++, y++)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */


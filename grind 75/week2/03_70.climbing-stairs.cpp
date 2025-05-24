/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
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
public:
    // auxiliary function used for fast multi
    vector<vector<long long>> multiply_2x2(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        // make sure a and b is 2x2 before calling
        vector<vector<long long>> c(2, vector<long long>(2));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
            
        }
        return c;
    }
    vector<vector<long long>> quickPower_2x2(vector<vector<long long>>& a, int n) {
        vector<vector<long long>> ret = {{1, 0}, {1, 1}};
        while (n)
        {
            if (n & 1)
            {
                multiply_2x2(a, ret);
            }
            a = multiply_2x2(a, a);
            n >>= 1;
        }
        return ret;
    }

    int climbStairs(int n) {
        // stair[n] = stair[n - 1] + stair[n - 2]
        // 以下方法好像超出时间限制了。。。
        // if (n == 1)
        // {
        //     return 1;
        // } else if (n == 2)
        // {
        //     return 2;
        // } else {
        //     return climbStairs(n - 1) + climbStairs(n - 2);
        // }
        // 滚动数组方案：
        // int p = 1, q = 2, r = 3;
        // if (n == 1)
        // {
        //     return 1;
        // } else if(n == 2) {
        //     return 2;
        // } else if (n == 3)
        // {
        //     return 3;
        // } else {
        //     for (int i = 4; i <= n; i++)
        //     {
        //         // p = q + r; // 这种方法的错误在于p增长的太快了， p必须每次步进一步
        //         // q = r + p; // 即使 return p也不行，增长太快
        //         // r = p + q;
        //         p = q;
        //         q = r;
        //         r = p + q;
        //     }
        //     return r;
        // }
        // 矩阵快速幂
        // [f(n + 1)] = [f(n) + f(n - 1)] = [1 1][f(n)    ] = [1 1]^n[f(1)]
        // [f(n)    ] = [f(n)           ] = [1 0][f(n - 1)] = [1 0]  [f(0)]
        // vector<vector<long long>> ret = {{1, 1}, {1, 0}};
        // vector<vector<long long>> res = quickPower_2x2(ret, n);
        // return res[0][0];
        // 数学：
        // f(n) = f(n - 1) + f(n - 2): x^2 = x + 1 => 特征根 x_1 = (1 + \sqrt(5)) / 2; x_2 = (1 - sqrt(5)) / 2
        // f(n) = c_1 * x_1^n + c_2 * x_2^n, 带入 f(1) = 1, f(2) = 2 (f(0) = 1)
        // c_1 = (sqrt(5) + 5) / 10, c_2 = (5 - sqrt(5)) / 10
        // 化简：f(n) = 1/sqrt(5) * (((1 + sqrt(5)) / 2) ^ (n + 1) -  ((1 - sqrt(5)) / 2) ^ (n + 1))
        double sqrt5 = sqrt(5);
        double fn = 1 / sqrt5 * (pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1)); 
        return (int) round(fn);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */


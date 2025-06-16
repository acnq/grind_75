// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=790 lang=cpp
 * @lcpr version=30204
 *
 * [790] 多米诺和托米诺平铺
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

const long long mod = 1e9 + 7;
class Solution {
    // I. DP
    // i列前面的都成功密铺，第i列后面的都没有（i从1开始计数）
    // 第i列的正方形考虑四种状态：
    // 0状态： 一个正方形都没有被覆盖
    // 1状态：只有上方的被覆盖
    // 2状态：只有下方的
    // 3状态：上下都被覆盖

    // dp[i][s]表示平铺到第i列时，各个状态s对应的平铺数量
    // 考虑第i-1列和第i列的关系
    // dp[i][0] = dp[i - 1][3]
    // dp[i][1] = dp[i - 1][0](铺L[需左转]) 或 dp[i - 1][2] (上方横铺I(一))
    // dp[i][2] = dp[i - 1][0](铺L) 或 dp[i - 1][1] (下方横铺I)
    // dp[i][3] = dp[i - 1][0](横铺两个I【二】) 或 dp[i - 1][1](反铺L) 
    // 或 dp[i - 1][2](上反铺L) 或 dp[i - 1][3] (竖铺I)

    // init: dp[0][0] = dp[0][1] = dp[0][2] = 0, dp[0][3] = 1
    // 对应方程：
    // dp[i][0] = dp[i - 1][3]
    // dp[i][1] = dp[i - 1][0] + dp[i - 1][2]
    // dp[i][2] = dp[i - 1][0] + dp[i - 1][1]
    // dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]

    // dp[n][3] 即答案

    // II. 快速幂
    // 用列向量x表示 dp[i][0:3], 
    // 初始时，x = [0 0 0 1]^T， 状态转移矩阵为
    // A = [0 0 0 1]
    //     [1 0 1 0]
    //     [1 1 0 0]
    //     [1 1 1 1]
    // n 次转移之后，列向量变为A^n x; A^n 可以快速幂计算，
    // 返回 A^n x的第3个元素即可。
public: 
    vector<vector<long long>> mulMatrix(const vector<vector<long long>>& m1, const vector<vector<long long>>& m2) {
        int n1 = m1.size(), n2 = m2.size(), n3 = m2[0].size();
        vector<vector<long long>> res(n1, vector<long long>(n3));
        for (int i = 0; i < n1; i++)
        {
            
            for (int k = 0; k < n3; k++)
            {
                for (int j = 0; j < n2; j++)
                {
                    res[i][k] = (res[i][k] + m1[i][j] * m2[j][k]) % mod;
                }
            }
        }
        return res;
    
    }
    int numTilings(int n) {
        // I. 
        // vector<vector<long long>> dp(n + 1, vector<long long>(4));
        // dp[0][3] = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     dp[i][0] = dp[i - 1][3];
        //     dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        //     dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        //     dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        //     dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod; 
        // }
        // return dp[n][3];

        // II.
        vector<vector<long long>> mat = {
            {0, 0, 0, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {1, 1, 1, 1}
        };
        vector<vector<long long>> matn = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        while (n)
        {
            if (n & 1)
            {
                matn = mulMatrix(matn, mat);
            }
            mat = mulMatrix(mat, mat);
            n >>= 1;   
        }
        return matn[3][3];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


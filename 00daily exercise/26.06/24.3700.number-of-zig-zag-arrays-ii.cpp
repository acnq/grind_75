/*
 * @lc app=leetcode.cn id=3700 lang=cpp
 * @lcpr version=30204
 *
 * [3700] 锯齿形数组的总数 II
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
    // I. DP + 快速幂
    // 和T3699相比，我们发现l,r的取值范围变小了，而数组长度则数量级变大
    // 其他没有变化，我们回顾状态转移方程
    // dp0[i][j] = \sum_{k=0}^{j-1}dp1[i-1][k]
    // dp1[i][j] = \sum_{k=j+1}^{r-l}dp0[i-1][k]
    // dp0[i] = dp1[i - 1] * B
    // dp1[i] = dp0[i - 1] * A
    // 令m = r - l + 1, 我们把两个数组合并成一个2m的数组，i.e.
    // D = [dp0[i] dp1[i]], D[i][j] = dp0[i][j], D[k + i][j] = dp1[i][j]
    // 我们设定状态转移方程：
    // [dp0[i] dp1[i]] = [dp0[i - 1] dp1[i - 1]][O A]
    //                                          [B O]
    // O: m * m 的0矩阵
    // A: m * m 的严格上三角矩阵，dp0转移至dp1, 旧元素k必须严格小于新j
    // B: m * m 的严格下三角矩阵，dp1转移至dp0, 旧元素k必须严格大于新j
    // 于是有D[n - 1] = D[0] * U^{n - 1}
    // D[0]全1， 矩阵U则快速幂计算

private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size();
        int m = b[0].size();
        Matrix res(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix powMul(Matrix base, long long exp, Matrix res) {
        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        Matrix u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        Matrix dp(1, vector<long long>(size, 1));

        dp = powMul(std::move(u), n - 1, std::move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n4\n5\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n3\n
// @lcpr case=end

 */


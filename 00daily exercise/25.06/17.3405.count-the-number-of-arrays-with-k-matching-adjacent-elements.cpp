/*
 * @lc app=leetcode.cn id=3405 lang=cpp
 * @lcpr version=30204
 *
 * [3405] 统计恰好有 K 个相等相邻元素的数组数目
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

const int MOD = 1e9 + 7;
const int MX = 1e5;
long long fact[MX];
long long inv_fact[MX];

class Solution {
    // I. 组合数学
    // 长度为n的数组有(n - 1)对相邻元素，需要k对相同，则剩下(n - 1 - k)对不同
    // 将这些不同元素看做隔板，分割为(n - k)段子数组，每段都需要有相同的元素
    // 1. 在(n - 1)中插入(n - 1 - k)个隔板，有C_{n - 1}^{n - 1 - k} = C_{n - 1}^k种方案
    // 2. 第一段所有元素都有一样，且无限制，有m种选择
    // 3. 第二段以及后面每一段都要和前一段不同，共有(m - 1)^{n - k - 1}种
    // 最终答案是 m * C_{n-1}^k * (m - 1)^{n - 1 - k}
    // 计算需要快速幂，以及线性求逆公式
    // i^{-1} = {1;                            i = 1 (mod p)
    //          { -\floor{p/i}(p mod i)^{-1};  else
public:
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }

    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n0\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 * @lcpr version=30204
 *
 * [50] Pow(x, n)
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
    // 这是快速幂算法的教学题，看答案叭
    
    // I. 快速幂 + 递归
    // 计算 x^{n}, 先计算y = x^{\floor{n / 2}}
    // 如若n为偶数，x^n = y ^ 2, 否则 x^n = y^2 * x;
    // n = 0 => x^0 = 1;
    // tc: O(logn), sc: O(logn)
    // 当时感觉最难的应该是n<0的情况，现在看来直接1/就可以了

    // II. 快速幂 + 迭代
    // 其实要额外乘x的地方就对应幂指数的二进制表示的1的位置
    //  
public:
    // I.
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        double ans = (N % 2 == 0 ? y * y : y * y * x);
        return ans;
    }

    // II.
    double quickMul2(double x, long long N) {
        double ans = 1.0;
        // 初始值为x;
        double x_contrib = x;
        // 对N进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x_contrib;
            }
            x_contrib *= x_contrib; // 平方
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        // I.
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, N);

        // II.
        // long long N = n;
        // return N >= 0 ? quickMul2(x, N) : 1.0 / quickMul2(x, -N);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */


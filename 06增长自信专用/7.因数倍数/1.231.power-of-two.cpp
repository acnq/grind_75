/*
 * @lc app=leetcode.cn id=231 lang=cpp
 * @lcpr version=30204
 *
 * [231] 2 的幂
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
    // I. 二进制
    // n & (n - 1): 直接移除n的最低1位， n为2的幂=> n & (n - 1)==0;
    // n & (-n): 获取n的最低1位，n为2的幂=>n & (-n) = n;

    // II. 因数
    // 32位有符号整数最大的2的幂为2^30, 判断n是否为其因数即可。
public:
    static constexpr int BIG = 1 << 30;
    bool isPowerOfTwo(int n) {
        // O. 我的解答（模拟）
        // int tmp = n;
        // if (n <= 0) {
        //     return false;
        // }
        // while(n > 0) {
        //     if(n != 1 && n % 2 == 1) {
        //         return false;
        //     }
        //     n = n / 2;
        // }
        // return true;

        // I.i
        // return n > 0 && (n & -n) == n;
        // I.ii
        // return n > 0 && (n & (n - 1)) == 0;

        // II.
        return n > 0 && BIG % n == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */


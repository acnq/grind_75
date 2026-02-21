// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=762 lang=cpp
 * @lcpr version=30204
 *
 * [762] 二进制表示中质数个计算置位
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

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 我的方法
    // tc: O((right - left) sqrt(log(right))) 1的个数为O(log(right)), sc：O(1)
    // II. 质数优化
    // 注意到 right <= 10^6 < 2^20, 所以二进制中1的个数不超过19
    // 也即2,3,5,7,11,13,17,19
    // 设置mask = 665772 = 10100010100010101100_2
    // 从低到高第i位为1表示i位质数，为0表示i非质数
    // x的二进制1位为c, 则2^c与mask按位与不为0则说明c为质数
public:
    // I.
    bool isPrime(int n) {
        if (n == 1) return false;
        int limit = (int) sqrt(n);
        for (int i = 2; i <= limit; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool isPrimeSetBits(int n) {
        int setbitscnt = 0;
        while (n > 0) {
            if (n % 2) {
                setbitscnt++;
            }
            n /= 2;
        }
        return isPrime(setbitscnt);
    }

    // II.
    int popcount(int n) {
        int setbitscnt = 0;
        while (n > 0) {
            if (n % 2) {
                setbitscnt++;
            }
            n /= 2;
        }
        return setbitscnt;
    }
    
    int countPrimeSetBits(int left, int right) {
        // I.
        // int res = 0;
        // for (int i = left; i <= right; i++) {
        //     if (isPrimeSetBits(i)) {
        //         res++;
        //     }
        // }
        // return res;

        // II.
        int ans = 0;
        for (int x = left; x <= right; x++) {
            cout << popcount(x) << endl;
            if ((1 << popcount(x)) & 665772) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n10\n
// @lcpr case=end

// @lcpr case=start
// 10\n15\n
// @lcpr case=end

 */


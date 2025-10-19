/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 * @lcpr version=30204
 *
 * [1625] 执行操作后字典序最小的字符串
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

#include <numeric> // gcd
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 枚举：
    // 如果b是偶数，那么无论如何轮转，只能给s奇数位的元素累加
    // b是奇数才能给各个元素累加。由此可知二操作是独立的，
    // 我们首先枚举轮转的次数，再枚举累加的次数
    // 1. 枚举轮转的次数，令t为轮转结果，由于轮转会有循环，
    //      最多轮转n = s.len次，我们使用数组vis
    //      来记录每个位置是否被轮转过，遇到轮转过的结束枚举
    // 2. 对每个t, 枚举t的奇数位累加操作次数j, 和偶数位次数k
    //      注意累加最多9次，否则会产生循环，特别地，如果b为偶数
    //      k=0，否则有上限9
    // II.
    // 枚举轮转的过程中，x * b (mod n) 可以表达为 xb - yn = z
    // 由裴蜀定理，z为gcd(b, n)的倍数，枚举范围变为[0, n)中gcd(b, n)的倍数
    // III.
    // 由于组内累加次数相同，我们只要考虑t[0], t[1]即可，
    // 首先找到使得t[1]最小的流转次数，然后对奇数位累加，如果b为奇数，
    // 找到t[0]最小的轮转次数，对偶数位累加
    // tc: O(n^2d^2): n = s.len(),d:累加上线=10， III下降为O(n^2d);
    // sc: O(n)
public:
    string findLexSmallestString(string s, int a, int b) {
        // // I.
        // int n = s.size();
        // vector<int> vis(n);
        // string res = s;
        // // 延长s, 方便截取轮转后的字符串t
        // s = s + s;
        // for (int i = 0; vis[i] == 0; i = (i + b) % n) {
        //     vis[i] = 1;
        //     for (int j = 0; j < 10; j++) {
        //         int k_limit = b % 2 == 0 ? 0 : 9;
        //         for (int k = 0; k <= k_limit; k++) {
        //             // 累加前重新截取t
        //             string t = s.substr(i, n);
        //             for (int p = 1; p < n; p += 2) {
        //                 t[p] = '0' + (t[p] - '0' + j * a) % 10;
        //             }
        //             for (int p = 0; p < n; p += 2) {
        //                 t[p] = '0' + (t[p] - '0' + k * a) % 10;
        //             }
        //             res = min(res, t);
        //         }
        //     }
        // }
        // return res;
        // // II.
        // int n = s.size();
        // string res = s;
        // int g = gcd(b, n);
        // // 延长s, 方便截取轮转后的字符串t
        // s = s + s;
        // for (int i = 0; i < n; i += g) {
        //     for (int j = 0; j < 10; j++) {
        //         int k_limit = b % 2 == 0 ? 0 : 9;
        //         for (int k = 0; k <= k_limit; k++) {
        //             // 累加前重新截取t
        //             string t = s.substr(i, n);
        //             for (int p = 1; p < n; p += 2) {
        //                 t[p] = '0' + (t[p] - '0' + j * a) % 10;
        //             }
        //             for (int p = 0; p < n; p += 2) {
        //                 t[p] = '0' + (t[p] - '0' + k * a) % 10;
        //             }
        //             res = min(res, t);
        //         }
        //     }
        // }
        // return res;
        // III.
        int n = s.size();
        string res = s;
        int g = gcd(b, n);
        // 延长s, 方便截取轮转后的字符串t
        s = s + s;

        auto add = [&](string& t, int start) {
            int minVal = 10, times = 0;
            for (int i = 0; i < 10; i++) {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal) {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < n; i+= 2) {
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
            }
        };

        for (int i = 0; i < n; i += g) {
            string t = s.substr(i, n);
            add(t, 1);
            if (b % 2) {
                add(t, 0);
            }
            res = min(res, t);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "5525"\n9\n2\n
// @lcpr case=end

// @lcpr case=start
// "74"\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// "0011"\n4\n2\n
// @lcpr case=end

 */


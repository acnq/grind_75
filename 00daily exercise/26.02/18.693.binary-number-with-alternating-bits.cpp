// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=693 lang=cpp
 * @lcpr version=30204
 *
 * [693] 交替位二进制数
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
    // O. 我的： 5min
    // I. 模拟, 官方写法，省略中间的容器
    // tc: O(logn), sc: O(1)
    // II. 位运算
    // n 右移一位再和n异或, 得到a，当且仅当n为交替二进制，a二进制表示全1
    // a 和 a + 1按位与，当且仅当a二进制表示全1，结果为0
    // tc = sc = O(1)
public:
    vector<int> to_bit(int n) {
        vector<int> res;
        while (n > 0) {
            if (n % 2) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            n /= 2;
        }
        return res;
    }

    bool hasAlternatingBits(int n) {
        // O.
        // vector<int> binrepr = to_bit(n);
        // int sz = binrepr.size();
        // for (int i = 0; i < sz - 1; i++) {
        //     if (binrepr[i] == binrepr[i + 1]) {
        //         return false;
        //     }
        // }
        // return true;

        // I.
        // int prev = 2;
        // while (n != 0) {
        //     int cur = n % 2;
        //     if (cur == prev) {
        //         return false;
        //     }
        //     prev = cur;
        //     n /= 2;
        // }
        // return true;
        
        // II
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 11\n
// @lcpr case=end

 */


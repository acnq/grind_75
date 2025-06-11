// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=190 lang=cpp
 * @lcpr version=30204
 *
 * [190] 颠倒二进制位
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

#include <cstdint> // 需要uint32_t
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 不借助字符串
    // 枚举一位的同时将结果添加到rev里面 tc: O(log n); sc: O(1)
    // II. 位运算分治
    // 最底层：取出所有偶数位和奇数位，奇数到偶数，偶数到奇数
    // 第二层取四分位，第三层取二分为，最高层就是分成左右凉拌，左到右，右到左
    // 用位操作实现。
    
public:
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M4 = 0x0f0f0f0f;
    const uint32_t M8 = 0x00ff00ff;

    uint32_t reverseBits(uint32_t n) {
        // string str = "";
        // while(n > 0) {
        //     str += n % 2 ? '1' : '0';
        //     n /= 2;
        // }
        // int len = str.size();
        // // cout << str.size() <<endl;
        // if(len < 32) {
        //     // str += '0' * (32 - str.size());
        //     for(int i = 0; str.size() < 32; i++) {
        //         str += '0';
        //     }
        // }
        // cout << str << endl;
        // // reverse(str.begin(), str.end());
        // // cout << str << endl;
        // uint32_t res = 0;
        // for(int i = 0; i < 32; i++) {
        //     if(i > len - 1) {
        //         res *= 2;
        //     } else {
        //         res *= 2;
        //         res += (str[i] == '1' ? 1 : 0); // 这一步一直没查出来
        //     }
        // }
        // return res;
        // // 因为debug比较困难做了34min

        // I.
        // uint32_t rev = 0;
        // for(int i = 0; i < 32 && n > 0; i++) {
        //     rev |= (n & 1) << (31 - i);
        //     n >>= 1;
        // }
        // return rev;

        // II.
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};
// @lc code=end



/*
// 00000010100101000001111010011100
// @lcpr case=start
//43261596\n
// @lcpr case=end

// 11111111111111111111111111111101
// @lcpr case=start
// 4294967293\n
// @lcpr case=end

 */


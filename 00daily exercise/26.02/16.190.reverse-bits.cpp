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

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
    // O. 我的方案： 13min完成
    // I. 逐位颠倒
    // 从低向高枚举n的每一位，倒序添加到翻转结果中
    // tc: O(logn), sc: O(1)
    // II. 位运算分治
    // 翻转二进制串，等价于均分为左右两部分，每部分进行翻转，然后左右拼合
    // 递归最底层，交换所有奇偶位：
    //  1. 取出所有奇数位和偶数位
    //  2. 奇数位移到偶数位上，偶数位移到奇数位上
    // 类似的，对于倒数第二层，两位一组，按照组号取出所有奇数组和偶数组
    // 然后将二者对调，以此类推, 注意32位只需要分治4层即可
    // tc = sc = O(1)
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    // O.
    vector<int> to_bin32(int n) {
        vector<int> res(32, 0);
        int idx = 31;
        while (n > 0) {
            char digit = 0;
            if (n % 2 == 1) {
                digit = 1;
            }
            res[idx] = digit;
            n = n / 2;
            idx--;
        }
        return res;
    }
    int to_int32(vector<int> repr32){
        int res = 0;
        for (int i = 0; i < 31; i++) {
            res += repr32[i] * pow(2, 31 - i);
        }
        return res;
    }
    int reverseBits(int n) {
        // O.
        // vector<int> repr(32, 0);
        // repr = to_bin32(n);
        // reverse(repr.begin(), repr.end());
        // int res = to_int32(repr);
        // return res;

        // I.
        // uint32_t rev = 0;
        // for (int i = 0; i < 32 && n > 0; i++) {
        //     rev |= (n & 1) << (31 - i);
        //     n >>= 1;
        // }
        // return rev;

        // II.
        uint32_t m = n;
        m = m >> 1 & M1 | (m & M1) << 1;
        m = m >> 2 & M2 | (m & M2) << 2;
        m = m >> 4 & M4 | (m & M4) << 4;
        m = m >> 8 & M8 | (m & M8) << 8;
        int res = (int)(m >> 16 | m << 16);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 43261596\n
// @lcpr case=end

// @lcpr case=start
// 2147483644\n
// @lcpr case=end

 */


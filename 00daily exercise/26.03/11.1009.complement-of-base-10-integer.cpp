/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 * @lcpr version=30204
 *
 * [1009] 十进制整数的反码
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
    // I. 位运算
    // 这个如果用朴素的字符串转化的方式搞得话可以,但是懒得写了
    // 直接看位运算怎么写的,学习一下
    // 因为计算机存储N位(32/64)整型的时候总是包含前导零,所以首先要找到最高位1
    // 然后再取反,如果n的最高位(二进制)是第i位,必然有2^i <= n < 2^(i+1)
    // 我们遍历[0,30]可以得到i
    // 然后我们遍历n的0:i位取反,首先构造掩码mask=2^(i+1)-1,
    // 这个(i+1)位的二进制数每位都为1,n与他异或即得答案
    // 注意i=30需要特判,2^(i+1)会溢出
public:
    int bitwiseComplement(int n) {
        int highbit = 0;
        for (int i = 0; i <= 30; i++) {
            if (n >= (1 << i)) {
                highbit = i;
            } else {
                break;
            }
        }
        int mask = (highbit == 30 ? 0x7fffffff: (1 << (highbit + 1)) - 1);
        return n ^ mask;
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
// 10\n
// @lcpr case=end

 */


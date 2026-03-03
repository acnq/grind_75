/*
 * @lc app=leetcode.cn id=1545 lang=cpp
 * @lcpr version=30204
 *
 * [1545] 找出第 N 个二进制字符串中的第 K 位
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
    // I. 递归
    // 显然，S_n是在S_{n-1}的基础上产生的，令len_n = S_n,则
    // S_n的前len_{n-1}个字符与S_{n-1}相同，n>1, len_n = len_{n-1}*2 + 1
    // len_1 = 1, => len_n = 2^n - 1
    // 因为S_1 = "0", 所以k=1, 返回'0'即可
    // n > 1, |S_n| = 2^n - 1, 可分为三部分
    // 前 2^{n-1} - 1 是S_{n-1}, 中间为‘1’，右边2^{n-1}-1是S_{n-1}翻转之后的结果
    // 所以k = 2^{n-1}, 返回'1'
    // k != 2^{n-1}, 考虑两种情况：
    //  k < 2^{n-1}, 在S_{n-1}中寻找第k个
    //  k > 2^{n-1}, 在前半部分寻找2^n - k个字符，反转之后即为所求
public:
    char invert(char bit) {
        return (char) ('0' + '1' - bit);
    }
    char findKthBit(int n, int k) {
        if (k == 1) {
            return '0';
        }
        int mid = 1 << (n - 1);
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            k = 2 * mid - k;
            return invert(findKthBit(n - 1, k));
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n11\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n
// @lcpr case=end

 */


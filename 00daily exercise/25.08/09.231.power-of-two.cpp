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
    // n & (n - 1): 将n的二进制最低1位移除。
    // n & (-n): 获取n二进制表示的最低位1

    // II. 是否是2^30幂的约数
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while(n > 1) {
            if (n % 2 == 1) {
                return false;
            }
            n = n / 2;
        }
        return true;
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


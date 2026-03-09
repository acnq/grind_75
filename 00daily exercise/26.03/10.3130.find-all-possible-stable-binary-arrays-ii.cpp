/*
 * @lc app=leetcode.cn id=3130 lang=cpp
 * @lcpr version=30204
 *
 * [3130] 找出所有稳定的二进制数组 II
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
    // I. 记忆化搜索
    // 用上一题的算法来做是可以不超时的,上一题时间复杂度已经够了
    // 这里我们用记忆化搜索的方法在写一下
    // dp(zero, one, lastBit): 包含zero个0, one个1, 末尾为lastBit的稳定数组个数
    // dp(zero, one, 0) = dp(zero - 1, one, 0) + dp(zero - 1, one, 1) - dp(zero - 1 - limit, one, 1)
    // dp(zero, one, 1) = dp(zero, one - 1, 0) + dp(zeor, one - 1, 1) - dp(zero, one - 1 - limit, 0)
    // zero = 0 && (lastBit = 1 || one > limit), 返回0, 否则zero = 0, 返回1,
    // zero = 1同理
    //  tc = sc = O(zero * one) 
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> memo(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        function<int(int, int, int)> dp = [&](int zero, int one, int lastBit) -> int {
            if (zero == 0) {
                return (lastBit == 0 || one > limit) ? 0 : 1;
            } else if (one == 0) {
                return (lastBit == 1 || zero > limit) ? 0 : 1;
            }

            if (memo[zero][one][lastBit] == -1) {
                int res = 0;
                if (lastBit == 0) {
                    res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % mod;
                    if (zero > limit) {
                        res = (res - dp(zero - limit - 1, one, 1) + mod) % mod; 
                    }
                } else {
                    res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % mod;
                    if (one > limit) {
                        res = (res - dp(zero, one - limit - 1, 0) + mod) % mod;
                    }
                }
                memo[zero][one][lastBit] = res % mod;
            }

            return memo[zero][one][lastBit];
        };

        return (dp(zero, one, 0) + dp(zero, one, 1)) % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 * @lcpr version=30204
 *
 * [2466] 统计构造好字符串的方案数
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
    // 没有官方题解，这里用灵茶山的答案
    // f[i]: 长为i的字符串方案数，f[0] = 1
    // i >= zero: 可以在长为i - zero的字符串末尾添加zero个0， f[i] = f[i - zero]
    // i >= one: 可以在长为i - one的字符串末尾添加one个1，f[i] = f[i - one]
    // f[i] = f[i - zero] + f[i - one]
    // ans = \sum_{i=low}^{high} f[i]

    // I. 记忆化搜索
    
    // II. 递推
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // I.
        // const int MOD = 1e9 + 7;
        // vector<int> memo(high + 1, -1); // -1表示未被计算
        // auto dfs = [&](auto&& dfs, int i) -> int {
        //     if (i < 0)
        //     {
        //         return 0;
        //     }
        //     if (i == 0)
        //     {
        //         return 1;
        //     }
        //     int& res = memo[i];
        //     if (res != -1)
        //     {
        //         return res; // 之前计算过
        //     }
        //     return res = (dfs(dfs, i - zero) + dfs(dfs, i - one)) % MOD;
        // };
        // int ans = 0;
        // for (int i = low; i <= high; i++)
        // {
        //     ans = (ans + dfs(dfs, i)) % MOD;
        // }
        // return ans;

        // II.
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> f(high + 1);
        f[0] = 1;
        for (int i = 0; i <= high; i++)
        {
            if (i >= zero)
            {
                f[i] = f[i - zero];
            }
            if (i >= one)
            {
                f[i] = (f[i] + f[i - one]) % MOD;
            }
            if (i >= low)
            {
                ans = (ans + f[i]) % MOD;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n3\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n1\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30204
 *
 * [279] 完全平方数
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
    // I. DP
    // f[i]表示最少需要多少个书的平方来表示整数i
    // 枚举组合为i的数j, j \in [1, \sqrt{i}]
    // f[i] = 1 + \min_{j \in [1, \sqrt{i}]} f[i - j^2]
    // f[0] = 0
    // tc: O(n\sqrt{n}); sc: O(n)
    // II. 数学
    // 我们不加证明的给出“四平方和定理”（其证明可参考百科，比较复杂）
    // 任意一个正整数最多可以被分解为四个完全平方数之和，
    // 仅当 n = 4^k * (8m + 7)时， n能表示为4个，否则可以被分解为最多3个
    // 如果n != 4^k * (8m + 7)时，答案只能为1,2,3；
    // 答案=1 => n为平方数，这很好判断
    // 答案=2 => 枚举a\in[1, \sqrt{n}], 判断n - a^2是否平方即可
    // 答案=3 => 其余情况
    // tc: O(\sqrt{n}), tc: O(1)
public:
    // II.
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }
    bool checkAnswer4(int x) {
        while (x % 4 == 0)
        {
            x /= 4;
        }
        return x % 8 == 7;
    }
    int numSquares(int n) {
        // I.
        // vector<int> f(n + 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     int minn = INT_MAX;
        //     for (int j = 1; j * j <= i; j++)
        //     {
        //         minn = min(minn, f[i - j * j]);
        //     }
        //     f[i] = minn + 1;
        // }
        // return f[n];

        // II.
        if (isPerfectSquare(n))
        {
            return 1;
        }
        if (checkAnswer4(n))
        {
            return 4;
        }
        for (int i = 1; i * i <= n; i++)
        {
            int j = n - i * i;
            if (isPerfectSquare(j))
            {
                return 2;
            }
        }
        return 3;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */


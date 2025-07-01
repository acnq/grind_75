/*
 * @lc app=leetcode.cn id=91 lang=cpp
 * @lcpr version=30204
 *
 * [91] 解码方法
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
    // f_i: s[1:i]的解码方案，考虑最后一次解码使用了s的哪些字符
    // 如果只使用了一个字符s[i], 只要s[i] != 0, 就可以被解码乘A-I中某个
    // f_i = f_{i - 1}, s[i] != 0
    // 如果使用了两个字符s[i-1]和s[i], 与第一种类似，s[i-1]!=0, 且二者组成的数字<=26
    // f_i = f_{i - 2}, s[i - 1] != 0 && 10s[i - 1] + s[i] <= 26
    // f_0 = 1

    // II. 滚动数组
public:
    int numDecodings(string s) {
        // I.
        // int n = s.size();
        // vector<int> f(n + 1);
        // f[0] = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (s[i - 1] != '0')
        //     {
        //         f[i] += f[i - 1];
        //     }
        //     if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
        //     {
        //         f[i] += f[i - 2];
        //     }
        // }
        // return f[n];

        // II.
        int n = s.size();
        int a = 0, b = 1, c;
        // a = f[i - 2], b = f[i- 1], c = f[i]
        for (int i = 1; i <= n; i++)
        {
            c = 0;
            if (s[i - 1] != '0')
            {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "12"\n
// @lcpr case=end

// @lcpr case=start
// "226"\n
// @lcpr case=end

// @lcpr case=start
// "06"\n
// @lcpr case=end

 */


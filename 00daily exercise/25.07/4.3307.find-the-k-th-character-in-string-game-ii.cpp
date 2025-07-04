/*
 * @lc app=leetcode.cn id=3307 lang=cpp
 * @lcpr version=30204
 *
 * [3307] 找出第 K 个字符 II
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
    // I. 迭代
    // 设 k = 2^t + a, a = 0 => 当前k处于第t-1次操作中；
    // a != 0, 则当前的k处于第t次操作中；
    // 然后根据所给的Operations数组判断是否对答案累加，若opertaions[t] = 1, 则累加，否则不

    // II. 数字
    // 如果从原始字符串的下一位开始计算，到达第k位等同于向后移动k-1个字符
    // 将k-1写成二进制的形式，当第t位为1时，正好对应2^{t-1}位，等同于第t-1次操作所得效果
    // 只需要之一k-1所表示的二进制数中1的所在位置，1所在位置对应的operations的值为1时对答案累加即可。
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // I.
        // int ans = 0;
        // int t;
        // while (k != 1)
        // {
        //     t = log2(k);
        //     if (((long long)1 << t) == k)
        //     {
        //         t--;
        //     }
        //     k = k - ((long long)1 << t);
        //     if (operations[t])
        //     {
        //         ans++;
        //     }
        // }
        // return 'a' + (ans % 26);

        // II.
        int ans = 0;
        k--;
        for (int i = log2(k); i >= 0; i--)
        {
            if (k >> i & 1)
            {
                ans += operations[i];
            }
        }
        return 'a' + (ans % 26);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[0,1,0,1]\n
// @lcpr case=end

 */


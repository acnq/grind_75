/*
 * @lc app=leetcode.cn id=3304 lang=cpp
 * @lcpr version=30204
 *
 * [3304] 找出第 K 个字符 I
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
    // I. 迭代
    // 每一次操作，字符串长度会倍增，并且在原始字符串的基础中，每一位进行了加一取模操作
    // 目标求解第k个位置的字符，那么关键是找到上一步操作之前该字符是哪一位（设为k')得来的？
    // 设k = 2^t + a, a = 0, 则k处于第t - 1次操作中，k' = k - 2^{t-1}
    // 设 a != 0, 则当前的k处于第t次操作中，k' = k - 2^5 = a
    // 这样迭代，最后使k'=1, 位于第0步操作
    // 因为每一次迭代就是a+1取模，因此我们只需要统计一共进行了几次迭代即可
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1)
        {
            t = log2(k);
            if ((1 << t) == k)
            {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */


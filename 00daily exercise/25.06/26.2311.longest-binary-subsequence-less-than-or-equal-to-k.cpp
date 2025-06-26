/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 * @lcpr version=30204
 *
 * [2311] 小于等于 K 的最长二进制子序列
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
    // I. 贪心
    // 从贪心的角度来说，我们尽可能选择0，然后按照<=k的要求添加1
    // 把所有0都加入是可以的，这会导致最高位的1贡献加倍，如果>k, 把这个1去掉长度不变，
    // 但二进制的值不会变大
    // 所以我们首先全部选择0，然后尽可能从后往前添1，
    // 注意因为k的限制，我们提前算出1可能得最高位
public:
    int longestSubsequence(string s, int k) {
        int sm = 0; // 子序列对应的数值
        int cnt = 0; // 子序列长度
        int bits = 32 - __builtin_clz(k); // 减去k的前导0，得到k的有效位数
        for (int i = 0; i < s.size(); i++) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++; // 0来者不拒
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1001010"\n5\n
// @lcpr case=end

// @lcpr case=start
// "00101001"\n1\n
// @lcpr case=end

 */


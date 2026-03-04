/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 * @lcpr version=30204
 *
 * [1758] 生成交替二进制字符串的最少操作数
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
    // I. 模拟
    // 有两种合法的交替字符串，分别是0开头和1开头
    // 分别变成这两种字符串所需要的操作数之和为s的长度（显然）
    // 所以我们计算其中一种，然后推出另一种，取二者较小即可
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != ('0' + i % 2)) {
                cnt++;
            }
        }
        return min(cnt, (int)s.size() - cnt);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0100"\n
// @lcpr case=end

// @lcpr case=start
// "10"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

 */


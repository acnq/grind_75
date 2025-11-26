/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 * @lcpr version=30204
 *
 * [1513] 仅含 1 的子串数
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
    // I. 遍历
    // 如果有一个长度为k的字符串元素均为1，则包含的所有1-子串数量
    // 为 k(k + 1) / 2;
    // 寻找所有均1的子字符串即可，
public:
    static constexpr int P = int(1E9) + 7;

    int numSub(string s) {
        int p = 0;
        long long ans = 0;
        while (p < s.size()) {
            if (s[p] == '0') {
                p++;
                continue;
            }
            int cnt = 0;
            while (p < s.size() && s[p] == '1') {
                cnt++;
                p++;
            }
            ans = ans + (1LL + (long long)cnt) * cnt / 2;
            ans = ans % P;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0110111"\n
// @lcpr case=end

// @lcpr case=start
// "101"\n
// @lcpr case=end

// @lcpr case=start
// "111111"\n
// @lcpr case=end

// @lcpr case=start
// "000"\n
// @lcpr case=end

 */


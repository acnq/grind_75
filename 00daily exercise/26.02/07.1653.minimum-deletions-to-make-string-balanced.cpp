/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 * @lcpr version=30204
 *
 * [1653] 使字符串平衡的最少删除次数
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
    // I. 枚举
    // 我们在原字符串相邻的两个字符之间划一条间隔，删除左侧所有b和右侧所有a即可
    // leftb := 左侧b的数目; righta := 右侧a数目，ans = leftb + righta
    // 我们枚举这个间隔，同时更新leftb和righta的数目即可。
    // tc: O(n), sc: O(1)
public:
    int minimumDeletions(string s) {
        int leftb = 0, righta = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                righta++;
            }
        }
        int res = righta;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a') {
                righta--;
            } else {
                leftb++;
            }
            res = min(res, leftb + righta);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aababbab"\n
// @lcpr case=end

// @lcpr case=start
// "bbaaaaabb"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=796 lang=cpp
 * @lcpr version=30204
 *
 * [796] 旋转字符串
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
    // 一时想不到，敢举不是简单题，至少中等题
    // I. 模拟
    // 简单来说，s旋转i位，s[(i + j) mod n] 会对应goal[j], 我们固定i,
    // 枚举j即可
    // tc: O(n^2), sc: O(1)
    // II. 搜索子串
    // 注意到，s + s包含了s所有可以通过旋转操作得到的字符串，只需要
    // 判断goal是否是s + s的子串即可
    // tc = sc = O(n)
public:
    bool rotateString(string s, string goal) {
        // I.
        // int m = s.size(), n = goal.size();
        // if (m != n) {
        //     return false;
        // }

        // for (int i = 0; i < n; i++) {
        //     bool flag = true;
        //     for (int j = 0; j < n; j++) {
        //         if (s[(i + j) % n] != goal[j]) {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag) {
        //         return true;
        //     }
        // }
        // return false;

        // II.
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"cdeab"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"abced"\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2839 lang=cpp
 * @lcpr version=30204
 *
 * [2839] 判断通过操作能否让字符串相等 I
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
public:
    bool canBeEqual(string s1, string s2) {
        // 11min
        // if (s1 == s2) { // 不要漏了这个
        //     return true;
        // }
        // string s11 = s1;
        // swap(s11[0], s11[2]);
        // if (s11 == s2) {
        //     return true;
        // }
        // string s12 = s1;
        // swap(s12[1], s12[3]);
        // if (s12 == s2) {
        //     return true;
        // }

        // string s13 = s1;
        // swap(s13[1], s13[3]);
        // swap(s13[0], s13[2]);
        // if (s13 == s2) {
        //     return true;
        // }

        // return false;

        // 标答写法
        if (s1 == s2) {
            return true;
        } else if (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] && s1[3] == s2[1]) {
            return true;
        } else if (s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] && s1[3] == s2[1]) {
            return true;
        } else if (s1[1] == s2[1] && s1[3] == s2[3] && s1[0] == s2[2] && s1[2] == s2[0]) {
            return true;
        }
        return false;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=canBeEqual
// paramTypes= ["string","string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "abcd"\n"cdab"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"dacb"\n
// @lcpr case=end

 */


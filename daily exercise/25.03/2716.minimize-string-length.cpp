// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2716 lang=cpp
 * @lcpr version=30204
 *
 * [2716] 最小化字符串长度
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

#include <cstdio>
// @lcpr-template-end
// @lc code=start
class Solution {
    // 第一道要看题解的简单题
    // 关键是这个定理：
    // "对于 s 中的任意字母 c，都可以通过任意次操作只留下唯一的一个 c"
public:
    int minimizedStringLength(string s) {
        // unordered_set<char> statis;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     statis.insert(s[i]);
        // }
        // return statis.size();
        // 标准答案写法：
        int stits = 0;
        for(char c: s) {
            stits |= 1 << (c - 'a');
        }
        return __builtin_popcount(stits); 
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimizedStringLength
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "aaabc"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

// @lcpr case=start
// "dddaaa"\n
// @lcpr case=end

 */


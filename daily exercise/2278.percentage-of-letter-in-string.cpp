/*
 * @lc app=leetcode.cn id=2278 lang=cpp
 * @lcpr version=30204
 *
 * [2278] 字母在字符串中的百分比
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
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for(char c: s) {
            if (c == letter)
            {
                cnt++;
            }
            
        }
        return (cnt * 1.0 / s.size()) * 100;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "foobar"\n"o"\n
// @lcpr case=end

// @lcpr case=start
// "jjjj"\n"k"\n
// @lcpr case=end

 */


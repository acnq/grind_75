/*
 * @lc app=leetcode.cn id=389 lang=cpp
 * @lcpr version=30204
 *
 * [389] 找不同
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
    char findTheDifference(string s, string t) {
        unordered_map<char, int> stats;
        for(char sch: s) {
            stats[sch]++;
        }
        for(char tch: t) {
            stats[tch]--;
            if (stats[tch] < 0)
            {
                return tch;
            }
        }
        return ' ';
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */


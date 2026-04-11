/*
 * @lc app=leetcode.cn id=657 lang=cpp
 * @lcpr version=30204
 *
 * [657] 机器人能否返回原点
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
    bool judgeCircle(string moves) {
        // 秒杀题：2min
        int up = 0, left = 0;
        for (char move: moves) {
            if (move == 'U') {
                up += 1;
            } else if (move == 'D') {
                up -= 1;
            } else if (move == 'L') {
                left += 1;
            } else {
                left -= 1;
            }
        }
        if (up == 0 && left == 0) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "UD"\n
// @lcpr case=end

// @lcpr case=start
// "LL"\n
// @lcpr case=end

 */


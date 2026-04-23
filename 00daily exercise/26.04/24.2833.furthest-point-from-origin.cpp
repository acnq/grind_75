/*
 * @lc app=leetcode.cn id=2833 lang=cpp
 * @lcpr version=30204
 *
 * [2833] 距离原点最远的点
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
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int ans = 0, opt = 0;
        for (int i = 0; i < n; i++) {
            if (moves[i] == 'L') {
                ans--;
            } else if (moves[i] == 'R') {
                ans++;
            } else {
                opt++;
            }
        }
        return abs(ans) + opt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "L_RL__R"\n
// @lcpr case=end

// @lcpr case=start
// "_R__LL_"\n
// @lcpr case=end

// @lcpr case=start
// "_______"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1344 lang=cpp
 * @lcpr version=30204
 *
 * [1344] 时钟指针的夹角
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
    // I. 数学
    // 我们直接计算分针和时针角度的差即可
    // 分针：1min对应 360°/60 = 6°: min_ang = min * 6°
    // 时针：1h对应 360°/12 = 30°, 注意它也随着分针移动
    // h_ang = (h mod 12 + min / 60) * 30° 
    // 首先计算差： diff = abs(h_ang - min_ang)
    // 然后返回最小角度 min(diff, 360 - diff)
public:
    double angleClock(int hour, int minutes) {
        int oneMinAngle = 6;
        int oneHourAngle = 30;

        double minutesAngle = oneMinAngle * minutes;
        double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

        double diff = abs(hourAngle - minutesAngle);
        return min(diff, 360 - diff);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n30\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n15\n
// @lcpr case=end

// @lcpr case=start
// 4\n50\n
// @lcpr case=end

// @lcpr case=start
// 12\n0\n
// @lcpr case=end

 */


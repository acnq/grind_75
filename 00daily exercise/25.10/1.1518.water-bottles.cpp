/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 * @lcpr version=30204
 *
 * [1518] 换水问题
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
    // I. 模拟：
    // 记一开始b瓶水，e个空瓶换一瓶水
    // 首先一定可以喝到b瓶水，剩下b个空瓶，接下来拿瓶子换水
    // 每e个换一瓶水，继续喝完得到空瓶，以此类推得到答案。
    // tc: O(b/e), sc: O(1)
    // II. 数学
    // 每次换一瓶意味着多一个空瓶，净损失e-1个瓶子，假设能换n次, 
    // 能换的条件为：
    // b - n(e - 1) >= e
    // 最小的n满足：
    // b - n(e - 1) < e
    // n_{min} = \celing((b - e)/(e - 1) + 1)
    // sc = tc = O(1)
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 我的回答：
        // int res = numBottles;
        // while (numBottles >= numExchange) {
        //     int getExchange = numBottles / numExchange;
        //     int remainExchange = numBottles % numExchange;
        //     res +=  getExchange;
        //     numBottles = getExchange + remainExchange;
        // }
        // return res;
        // I.
        // int bottle = numBottles, ans = numBottles;
        // while (bottle >= numExchange) {
        //     bottle -= numExchange;
        //     ans++;
        //     bottle++;
        // }
        // return ans;
        // II.
        return numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles: numBottles;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n3\n
// @lcpr case=end

// @lcpr case=start
// 15\n4\n
// @lcpr case=end

 */


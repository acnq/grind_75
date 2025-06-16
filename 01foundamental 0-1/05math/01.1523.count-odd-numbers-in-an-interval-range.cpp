/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 * @lcpr version=30204
 *
 * [1523] 在区间范围内统计奇数数目
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
    // I. 前缀和
    // def pre(x) := [0, x]中奇数的个数
    // 显然 pre(x) = \floor{(x + 1) / 2}
    // ans = pre(high) - pre(low - 1)

    // II. 分类讨论
    // [e1, e2] -> ans = (e2 - e1) / 2
    // [o1, o2] -> ans = (o2 - o1) / 2 + 1
    // [o1, e2] -> ans = (e2 - o1) / 2 + 1
    // [e1, o2] -> ans = (o2 - e1) / 2 + 1
    // o: odd, e: even,
    // 注意得从/2考虑，不然就像我这样想半天想不出
public:
    // I.
    int pre(int x) {
        return (x + 1) >> 1;
    }

    int countOdds(int low, int high) {
        // int cnt = 0;
        // for(int i = low; i <= high; i++) {
        //     if(i % 2 == 1) {
        //         cnt++;
        //     }
        // }
        // return cnt;

        // I
        // return pre(high) - pre(low - 1);
        
        // II.
        if (low % 2 || high % 2) {
            return (high - low) / 2 + 1;
        }
        return (high - low) / 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 8\n10\n
// @lcpr case=end

 */


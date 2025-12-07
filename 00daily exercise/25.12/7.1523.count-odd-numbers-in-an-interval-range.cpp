// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    // pre(x) := [0, x]中奇数个数
    // pre(x) = \ceil((x + 1) / 2)
    // 答案：= pre(high) - pre(low - 1)
public:
    // I.
    int pre(int x) {
        return (x + 1) >> 1;
    }
    
    int countOdds(int low, int high) {
        // 我的答案
        // if ((high - low + 1) % 2 == 0) {
        //     return (high - low + 1) / 2;
        // } else {
        //     int ret = (high - low) / 2;
        //     if ((high % 2) == 0) {
        //         return ret;
        //     } else {
        //         return ret + 1;
        //     }
        // }
        // I.
        return pre(high) - pre(low - 1);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countOdds
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 8\n10\n
// @lcpr case=end

 */


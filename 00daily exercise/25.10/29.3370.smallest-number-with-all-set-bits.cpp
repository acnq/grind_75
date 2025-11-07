/*
 * @lc app=leetcode.cn id=3370 lang=cpp
 * @lcpr version=30204
 *
 * [3370] 仅含置位位的最小整数
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
    // I. 找规律
    // 1, 3, 7, 15, 均为前一个数 * 2 + 1;
    // tc: O(logn); sc: O(1)
public:
    int smallestNumber(int n) {
        // 我的解答. 
        // int dig = 0;
        // while (n > 0) {
        //     n /= 2;
        //     dig++;
        // }
        // return (2 << dig - 1) - 1;
        // I. 找规律
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 * @lcpr version=30204
 *
 * [1716] 计算力扣银行的钱
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
    int totalMoney(int n) {
        int wn = n / 7; // week number
        int wr = n % 7; // week remainder
        
        int mn = 28 * wn + (wn + 1) * wn * 7 / 2;
        int mr = (1 + wr) * wr / 2 + wn * wr;
        return mn + mr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 20\n
// @lcpr case=end

 */


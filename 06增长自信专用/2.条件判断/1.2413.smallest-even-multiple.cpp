/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 * @lcpr version=30204
 *
 * [2413] 最小偶倍数
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
    int smallestEvenMultiple(int n) {
        if(n % 2 == 0) {
            return n;
        } else {
            return 2 * n;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

 */


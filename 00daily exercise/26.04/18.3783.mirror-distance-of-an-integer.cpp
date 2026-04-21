/*
 * @lc app=leetcode.cn id=3783 lang=cpp
 * @lcpr version=30204
 *
 * [3783] 整数的镜像距离
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
    int reverse(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n)); // 差点忘了abs
    }
};
// @lc code=end



/*
// @lcpr case=start
// 25\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

 */


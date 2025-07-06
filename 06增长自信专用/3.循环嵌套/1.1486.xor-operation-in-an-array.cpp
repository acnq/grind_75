/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 * @lcpr version=30204
 *
 * [1486] 数组异或操作
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
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            int tmp = start + 2 * i;
            res ^= tmp;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n0\n
// @lcpr case=end

// @lcpr case=start
// 4\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n7\n
// @lcpr case=end

// @lcpr case=start
// 10\n5\n
// @lcpr case=end

 */


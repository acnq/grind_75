/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 * @lcpr version=30204
 *
 * [1732] 找到最高海拔
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
    int largestAltitude(vector<int>& gain) {
        // 1 min秒杀
        int cur = 0, res = 0;
        for (int diff: gain) {
            cur += diff;
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-5,1,5,0,-7]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-3,-2,-1,4,3,2]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2087 lang=cpp
 * @lcpr version=30204
 *
 * [2087] 网格图中机器人回家的最小代价
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 贪心
    // 1. 相邻两步如果分别为横向和纵向移动，那么交换这两步，路径总代价不变
    // (显然)
    // 2. 如果包含相反的操作，那么代价一定不优于抵消后的路径
    // (显然)
    // 综上，我们只要贪心的构造一条只包含上/下和左/右的路径
    // 计算总代价和即可。
    // tc: O(m + n), sc: O(1)
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int res = 0; // 总代价
        // 移动到home的方向并计算代价
        if (r2 >= r1) {
            res += accumulate(rowCosts.begin() + r1 + 1, rowCosts.begin() + r2 + 1, 0);
        } else {
            res += accumulate(rowCosts.begin() + r2, rowCosts.begin() + r1, 0);
        }
        if (c2 >= c1) {
            res += accumulate(colCosts.begin() + c1 + 1, colCosts.begin() + c2 + 1, 0);
        } else {
            res += accumulate(colCosts.begin() + c2, colCosts.begin() + c1, 0);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 0]\n[2, 3]\n[5, 4, 3]\n[8, 2, 6, 7]\n
// @lcpr case=end

// @lcpr case=start
// [0, 0]\n[0, 0]\n[5]\n[26]\n
// @lcpr case=end

 */


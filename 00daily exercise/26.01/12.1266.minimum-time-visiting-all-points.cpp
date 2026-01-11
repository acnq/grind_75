/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 * @lcpr version=30204
 *
 * [1266] 访问所有点的最小时间
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
    // I. 切比雪夫距离
    // x = (x0, y0), y = (x1, y1), dx = |x0 - x1|, dy = |y0 - y1|
    // dx < dy: 对角线移动dx次，竖直移动dy - dx次，共dx + (dy - dx) = dy次
    // dx = dy: 对角线移动dx次
    // dx > dy: 对角线移动dy次，水平移动dx - dy次，共dy + (dx - dy) = dx次
    // 综上，从x到y移动的最少次数为max(dx, dy), 我们称为这是二者的切比雪夫距离
    // 我们按照数组顺序访问这些节点，计算切比雪夫距离，所有距离之和就是答案
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x0 = points[0][0], y0 = points[0][1];
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            int xc = points[i][0], yc = points[i][1];
            ans += max(abs(xc - x0), abs(yc - y0)); // c for current
            x0 = xc;
            y0 = yc;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[3,4],[-1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[-2,2]]\n
// @lcpr case=end

 */


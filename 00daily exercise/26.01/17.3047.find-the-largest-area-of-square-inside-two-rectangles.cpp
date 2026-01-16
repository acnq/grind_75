/*
 * @lc app=leetcode.cn id=3047 lang=cpp
 * @lcpr version=30204
 *
 * [3047] 求交集区域内的最大正方形面积
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
    // I. 遍历+计算几何
    // 注意到，我们要求考虑的范围是矩形两两交叠区域，而不是所有矩形交叠的区域
    // 考虑二重遍历即可，由于矩形交叠区域只能是矩形，故交叠区域
    // 最大正方形等于长宽中的较小值，遍历时不断更新全局最优解，
    // 最后求解的平方
    // 如何计算重叠区域的长宽？以宽为例，将两矩形投影到x轴上，
    // 得到两条线段，二者交集的长度因为右端点较小-左端点较大
    // 为负数说明不重叠，我们直接将初始最大边长设为0，这样不想交区域不会更新
    // tc: O(n^2)
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = min(topRight[i][0], topRight[j][0]) - 
                        max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) - 
                        max(bottomLeft[i][1], bottomLeft[j][1]);
                maxSide = max(maxSide, min(w, h));
            }
        }
        return 1LL * maxSide * maxSide;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[2,2],[3,1]]\n[[3,3],[4,4],[6,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[1,2]]\n[[3,3],[4,4],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[3,3],[3,1]]\n[[2,2],[4,4],[4,2]]\n
// @lcpr case=end

 */


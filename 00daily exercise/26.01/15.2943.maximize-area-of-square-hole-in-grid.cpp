/*
 * @lc app=leetcode.cn id=2943 lang=cpp
 * @lcpr version=30204
 *
 * [2943] 最大化网格图中正方形空洞的面积
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
    // I. 排序：
    // 正方形空洞边长取决于移除的横/纵向连续线段的数目
    // 1. 对hBars, vBars从小排序
    // 2. 分别遍历排序后的hBars, vBars, 统计横向最大连续线段树木hmax和纵向vmax
    // 3. 最大正方形边长为side = min(hmax, vmax) + 1, 返回side^2
    // tc: O(hlogh + vlog) h = |hBars|, v = |vBars|, sc: (logh + logv)
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hmax = 1, vmax = 1;
        int hcur = 1, vcur = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }// 统计连续组
            hmax = max(hmax, hcur);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = max(vmax, vcur);
        }
        int side = min(hmax, vmax) + 1;
        return side * side;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n1\n[2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n[2]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n[2,3]\n[2,4]\n
// @lcpr case=end

 */


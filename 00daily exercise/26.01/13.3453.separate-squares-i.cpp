/*
 * @lc app=leetcode.cn id=3453 lang=cpp
 * @lcpr version=30204
 *
 * [3453] 分割正方形 I
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
    // I. 二分
    // totalArea = \sum_{i=0}^{n-1}l_i^2
    // 若满足答案，y以下的面积area_y * 2 = totalArea
    // area_y随着y单调递增，我们二分查找最小的y, s.t. area_y * 2 >= totalArea
    // 给定正方形(x_i, y_i, l_i), y_i < y, 
    // 此正方形在y以下的面积为：area = l_i * \min(y - y_i, l_i)
    // ∴ area_y = \sum_{i=0}^{n-1}l_i * \max(0, \min(y - y_i, l_i))
    // 终止条件hi - lo <= 10^{-5}
    // tc: O(n\log(LU)), U = \max(y_i + l_i), L = 10^5, sc: O(1)
    // II. 扫描线法/扫面线法
    // 若要area = totalArea / 2;
    // 扫面线概念参考：https://oi-wiki.org/geometry/scanning/
    // 设当前扫描线y=y', 此时扫描线以下的面积为area; 
    // 向上移动下一个需要经过的正方形上/下边界的扫描线为y = y", 
    // 此时被正方形覆盖的底边长之和为width, 此时扫面线y = y"以下覆盖的面积和为
    // area + width * (y" - y')
    // area < total / 2 && area + width(y" - y') >= total / 2
    // 则目标一定在[y', y"]之间
    // 由于两个扫面线之间的被覆盖区域中所有矩形宽度不变，扫面线在区间内移动△时
    // 被覆盖的面积变化即为\Delta * width, 此时增加的面积为totalArea / 2 - area即可
    // 解出y = y' + (totalArea / 2 - area) / width = y' + (totalArea - 2 * area) / (2 * width)
    // 一次遍历每个正方形的上下边界扫面线，找到目标值返回即可
    // tc: O(nlogn)（排序），sc: O(n)
public:
    double separateSquares(vector<vector<int>>& squares) {
        // I.
        // double max_y = 0, total_area = 0;
        // for (auto& sq: squares) {
        //     int y = sq[1], l = sq[2];
        //     total_area += (double) l * l;
        //     max_y = max(max_y, (double)(y + l));
        // }
        // auto check = [&](double limit_y) -> bool {
        //     double area = 0;
        //     for (auto& sq: squares) {
        //         int y = sq[1], l = sq[2];
        //         if (y < limit_y) {
        //             area += l * min(limit_y - y, (double)l);
        //         }
        //     }
        //     return area >= total_area / 2;
        // };

        // double lo = 0, hi = max_y;
        // double eps = 1e-5;
        // while(abs(hi - lo) > eps) {
        //     double mid = (hi + lo) / 2;
        //     if (check(mid)) {
        //         hi = mid;
        //     } else {
        //         lo = mid;
        //     }
        // }
        // return hi;

        // II.
        long long total_area = 0;
        vector<tuple<int, int, int>> events;
        for (const auto& sq: squares) {
            int y = sq[1], l = sq[2];
            total_area += (long long) l * l;
            events.emplace_back(y, l, 1); // 矩形下侧边, 用1标记
            events.emplace_back(y + l, l, -1); // 矩形上侧边，用-1标记
        }
        // 按照y排序
        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            return get<0>(a) < get<0>(b);
        });

        double covered_width = 0; // 当前扫面线下所有底边之和
        double cur_area = 0; // 当前累计面积
        double prev_height = 0; // 前一个扫面线的高度
        for (const auto& [y, l, delta]: events) {
            int diff = y - prev_height;
            // 两条扫面线之间新增的面积
            double area = covered_width * diff;
            // 如若加上这部分面积超过总面积的一半
            if (2LL * (cur_area + area) >= total_area) {
                return prev_height + (total_area - 2.0 * cur_area) / (2.0 * covered_width);
            }
            // 更新宽度：开始事件加宽度，结束事件减宽度
            covered_width += delta * l;
            cur_area += area;
            prev_height = y;
        }
        return 0.0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,2],[1,1,1]]\n
// @lcpr case=end

 */


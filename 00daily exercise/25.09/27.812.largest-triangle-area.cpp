/*
 * @lc app=leetcode.cn id=812 lang=cpp
 * @lcpr version=30204
 *
 * [812] 最大三角形面积
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
    // I. 枚举
    // 通过三阶行列式直接根据枚举到的三个三角形顶点计算其面积
    // S = 1/2 * |x_1 y_2 + x_2 y_3 + x_3 y_1 - x_1 y_3 - x_2 y_1 - x_3 y_2|
    // = 1/2 |x_1 y_1 1|
    //       |x_2 y_2 1|
    //       |x_3 y_3 1|
    // tc: O(n^3), sc: O(1)
    // II. 凸包
    // 使用Andrew算法求出所有店对应的凸包
    // 如若三角形的某一点不在凸包上，则以其余两点的边为底
    // 总可以找到凸包上的一点，使得此点到该边的高更大，
    // 故面积最大的三角形的三点必然共享一个凸包
    // 在凸包convexHull上枚举三角形，秩序枚举i,j
    // 此后，三角形面积与k的关系是凸的，因此三角形只在k为极点时面积最大
    // 固定i, 该极点随j递增，所以搜索极点需要从上次的极点位置开始搜索
    // tc: O(n^2), sc: O(1)
public:
    // I.
    // double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    //     return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    // }

    // II.
    int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
    vector<vector<int>> getConvexHull(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) {
            return points;
        }
        /* 按照x大小进行排序，如果x相同，则按照y的大小进行排序 */
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> hull;
        /* 凸包下半部分 */
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        int m = hull.size();
        /* 凸包上半部分 */
        for (int i = n - 2; i >= 0; i--) {
            while(hull.size() > m && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        /* hull[0] 同时参与凸包的上半部分检测，需要去重hull[0] */
        hull.pop_back();
        return hull;
    }
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        // I.
        // int n = points.size();
        // double ret = 0.0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             ret = max(ret, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
        //         }
        //     }
        // }
        // return ret;

        // II.
        auto convexHull = getConvexHull(points);
        int n = convexHull.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = i + 2; j + 1 < n; j++) {
                while (k + 1 < n) {
                    double curArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                    double nextArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k + 1][0], convexHull[k + 1][1]);
                    if (curArea >= nextArea) {
                        break;
                    }
                    k++;
                }
                double area = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                ret = max(ret, area);

            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[0,1],[1,0],[0,2],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0],[0,0],[0,1]]\n
// @lcpr case=end

 */


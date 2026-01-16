/*
 * @lc app=leetcode.cn id=3454 lang=cpp
 * @lcpr version=30204
 *
 * [3454] 分割正方形 II
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

#include <set>
// @lcpr-template-end
// @lc code=start

class SegmentTree {
private:
    vector<int> count;      // 这个节点对应的区间被多少正方形覆盖
    vector<int> covered;    // 当前节点真实的被覆盖的长度
    vector<int> xs;         // 堆式线段树，叶子结点表示半开区间：[xs[i], xs[i + 1])
    int n;

    /**
     * 当前线段树节点上，更新区间覆盖计数，并维护被覆盖的总长度
     * 
     * @param qleft: 需要更新x区间的左边界（真实坐标）
     * @param qright: 需要更新x区间的右边界（真实坐标，半开）
     * @param qval: +1表示进入1个正方形，-1表示离开1个正方形
     * 
     * @param left: 当前节点负责的区间下标的左端
     * @param right: 当前结点负责的区间下标的右端
     * @param pos:   当前节点在线段树中的位置
     * 实际表示：[xs[left], xs[right + 1])区间
     */

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        // left, right: 当前负责区间，pos: 结点在线段数组中的位置
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            // 当前节点和更新区间完全不相交，直接返回
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            // 当前区间被[qleft, qright) 完全覆盖：
            // 修改覆盖计数，不需要递归
            count[pos] += qval;
        } else { // 部分覆盖： 递归更新左右
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2);
        }

        if (count[pos] > 0) {
            // 只要当前区间被至少一个正方形完全覆盖；
            // 整个区间都算做‘被覆盖’
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            // 当前区间没有被完整覆盖
            // 覆盖长度取决于子节点 
            if (left == right) {
                // 叶子结点，对应最小区间[xs[i], xs[i + 1])
                covered[pos] = 0;
            } else {
                // 非叶结点，覆盖长度为左右子区间之和
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;  // 区间数量=结点数量-1
        count.resize(4 * n , 0);
        covered.resize(4 * n, 0); // 堆式存储，设计为4n即可
    }
    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() {
        return covered[0];
    }
};

class Solution {
    // I. 扫面线+线段树
    // 和上一题一样，给每个矩形的上下边标记，下面的边标记1，上面-1
    // 每遇到水平边，让这条边的权值(被覆盖的矩形的数量)加上这条边的标记，
    // 矩形的宽度就是整个数轴上权值>0的区间总长度
    //
    // 具体而言，我们将正方形的所有横坐标从小到大排序后离散化以维护每条底边
    // 也就是整个数轴上覆盖次数>0的点，由于扫面线从下往上移动，会更新一个区间内点的权值
    // 使用线段树管理区间中完全覆盖区间的次数和区间已经覆盖的长度
    // 求得整个覆盖区域为totalArea
    // 仿照上一题，我们进行二次扫描，y = y', 下方面积为area
    // 假设向上移动到下一个矩形的上/下边界扫描线为y = y"，底边长为width
    // y = y"：area" = area + width(y" - y')
    // area < totalArea / 2 && area" > totalArea / 2
    // y* \in [y', y"]
    // y* = y' + (totalArea - 2 * area) / (2 * width)
    // 实际计算中，我们避免二次扫描，可在第一次扫描中记录每个高度区间对应的覆盖面积和宽度
    // 随后二分查找y'
    // tc: O(nlogn), sc: O(n)
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto& sq: squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }
        // 按y坐标排序事件
        sort(events.begin(), events.end());
        // 离散化坐标
        vector<int> xs(xsSet.begin(), xsSet.end());
        // 初始化线段树
        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        // 扫面：计算总面积和记录中间状态
        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // 记录前缀和和宽度
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }
        // 计算目标面积（向上取整）
        long long target = (long long)(total_area + 1) / 2;
        // 二分查找第一个>=target的位置
        int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // 获取对应的面积、宽度和高度
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
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


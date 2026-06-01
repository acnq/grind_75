/*
 * @lc app=leetcode.cn id=3161 lang=cpp
 * @lcpr version=30204
 *
 * [3161] 物块放置查询
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
class Solution {
    // I. 线段树
    // 问题实际上是：[0, x]区间是否包含一个长度为sz的空白区间
    // 我们定义如下变量维护空白区间：
    // p[i]: i左边最近的障碍物的距离
    // d[i] = i - p[i]: 以i结尾的最大空白区间长度
    // 问题等价于是否存在i<=x, s.t. d[i] >= sz
    //  i.e. 在[0, x]中查询i<=x, s.t. d[i]的最大值是否至少为sz；
    // 我们将每个区间长度d[r]保存在右端点r处，
    // 我们用线段树来维护数组d, 令pre, nxt分别表示x左右最近的障碍物位置
    // 插入障碍物即更新d[x], d[nxt], 
    // 查找时[0, pre]是完整区间，在线段树中查询，[pre, x]则需要计算
    // tc: O(qlogq + qlogM) (M: x的最大值), sc: O(M + q)

    // II. 树状数组
    // 树状数组需要先保持最细粒度的障碍物的存在，然后逐个合并
    // d[r]: r到左边最近障碍物的距离
    // pre, nxt: x左右最近障碍物的位置，
    // d[x] = x - pre
    // 如果删除x, [pre, x]和[pre, nxt]会合并为新区间[pre, nxt]
    // 为此我们用树状数组维护前缀最大值，
    // 倒序读入输入，查询最大值
    // // tc: O(qlogq + qlogM) (M: x的最大值), sc: O(M + q)
public:
    // I.
    // vector<int> seg;
    // // seg[p]: 对应数组d区间[l, r]上d[i]的最大值
    // void update(int idx, int val, int p, int l, int r) {
    //     // d[idx]改成val, 一路更新影响到的所有区间
    //     if (l == r) {
    //         seg[p] = val;
    //         return;
    //     }
    //     int mid = (l + r) >> 1;
    //     if (idx <= mid) {
    //         update(idx, val, p << 1, l, mid);
    //     } else {
    //         update(idx, val, p << 1 | 1, mid + 1, r);
    //     }
    //     seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    // }

    // int query(int L, int R, int p, int l, int r) {
    //     // d数组中，查询区间[L, R]的最大值
    //     if (L <= l && r <= R) {
    //         return seg[p];
    //     }
    //     int mid = (l + r) >> 1;
    //     int res = 0;
    //     if (L <= mid) {
    //         res = max(res, query(L, R, p << 1, l, mid));
    //     }
    //     if (R > mid) {
    //         res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
    //     }
    //     return res;
    // }

    // II.
    vector<int> bt;
    // [i - lowbit(i) + 1, i]内的d的最大值，
    // lowbit(i) = i & -i, i能整除的最大2的幂

    void update(int x, int v) {
        // d[x]更新为v, 并更新所有"包含x的BIT区间"的最大值
        for (; x < bt.size(); x += x & -x) { // 右跳父区间
            bt[x] = max(bt[x], v);
        }
    }

    int query(int x) {
        // 求前缀[1:x]的最大值
        int res = 0;
        for (; x > 0; x -= x & -x) { // 左条父区间
            res = max(res, bt[x]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // I.
        // int mx = 50000;
        // seg.resize(mx << 2);
        // set<int> st = {0, mx}; // 所有障碍物的下标位置
        // update(mx, mx, 1, 0, mx);
        // vector<bool> ans;

        // for (auto& q: queries) {
        //     if (q[0] == 1) {
        //         // 添加障碍->更新线段树
        //         int x = q[1];
        //         auto it = st.upper_bound(x); 
        //         int r = *it; // x右侧的障碍物
        //         int l = *prev(it); // x左侧最近的障碍物
        //         update(x, x - l, 1, 0, mx);
        //         update(r, r - x, 1, 0, mx);
        //         st.insert(x);
        //     } else {
        //         // 查询位置
        //         int x = q[1];
        //         int sz = q[2];
        //         auto it = st.upper_bound(x); // 第一个严格>x的元素
        //         it--; // 不用lower_bound是防止x本身是障碍物
        //         int pre = *it; // x 左边最近的障碍物
        //         int max_space = query(0, pre, 1, 0, mx);
        //         max_space = max(max_space, x - pre);
        //         ans.push_back(max_space >= sz);
        //     }
        // }
        // return ans;

        // II.
        int mx = 50000;

        set<int> st = {0, mx};

        for (auto& q: queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            }
        }
        // 首先给每个有障碍的位置做上标记

        bt.resize(mx + 1);

        int pre = 0;

        for (int x: st) {
            if (x == 0) {
                continue;
            }
            update(x, x - pre);
            pre = x;
        }

        reverse(queries.begin(), queries.end());
        vector<bool> ans;
        for (auto& q: queries) {
            // 倒序的删除这些障碍以适配树状数组的组织
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                it--;
                int pre = *it;
                int max_space = query(pre);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            } else {
                int x = q[1];
                auto it = st.find(x);
                int pre = *prev(it);
                int nxt = *next(it);
                update(nxt, nxt - pre);
                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3,3],[2,3,1],[2,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]\n
// @lcpr case=end

 */


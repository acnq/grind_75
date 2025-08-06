// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3479 lang=cpp
 * @lcpr version=30204
 *
 * [34779] 水果成篮 III
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
    // I. 分块法
    // 同样采用模拟的思想，只是这次我们把数组basket依照\sqrt(n) = m的大小分块
    // n = basket.size(), 每块上维护最大值maxV, 表示当前块中的最大篮子容量
    // 枚举fruits的每种水果，遍历每个块，
    //  如果当前块最大值maxV小于水果质量，
    // 则整块都没有满足条件的容器, 直接遍历下一个
    // 如果有，那么这个块中存在容量满足条件的容器，从左到右遍历这个块，
    // 遇到满足的置零，如果遍历所有块之后无满足的容器，计数器++，
    // 注意更新maxV
    // tc: O(n*sqrt(n)); sc: O(n)

    // II. 线段树 + 二分
    // 要用线段树来维护数组区间最大值并且二分查找第一个满足的
    // 1. 建树，初始化维护内容为区间的最大值
    // 2. 枚举fruits中的水果，二分查找区间最大值来找到首个满足条件的水果
    //    若找到，则用线段树单点修改篮子值为0，否则cnt++
    // 3. 二分过程：左区间最大值>当前水果质量，左区间二分，
    //      <=且右区间最大值>=, 右区间二分，
    //      否则返回没找到
    // tc: O(n logn), sc: O(n)
public:
    // II.
    int segTree[400007]; // seg[p]存储对应区间的最大值
    vector<int> baskets;

    void build(int p, int l, int r) {
        // p: 当前节点，用于递归
        if (l == r) {
            segTree[p] = baskets[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid); // p << 1 = p * 2, 构建左子树
        build(p << 1 | 1, mid + 1, r); // 构建右子树，这里按位或理解为加一，
        segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
    }
    int query(int p, int l, int r, int ql, int qr) {
        // 查找[l, r]线段树在区间[ql, qr]内的最大值
        if (ql > r || qr < l) {
            return INT_MIN;
        }
        if (ql <= l && r <= qr) {
            return segTree[p];
        } // [ql, qr] >= [l, r], 直接返回[l, r]的最大值即可
        // 因为线段树是完全的，所以不用考虑[ql, qr]包含[l, r]未排序的数组的情况
        int mid = (l + r) >> 1; // 否则细分查找即可
        return max(query(p << 1, l, mid, ql, qr),
                    query(p << 1 | 1, mid + 1, r, ql, qr));
    }
    void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(p << 1, l, mid, pos, val);
        } else {
            update(p << 1 | 1, mid + 1, r, pos, val);
        }
        segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
    }
    int numOfUplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // I.
        // int n = baskets.size();
        // int m = sqrt(n);

        // int section = (n + m - 1) / m; 
        // // 标准向上取整操作 \floor{n / m} = (n + m - 1) / m
        // int count = 0;

        // vector<int> maxV(section);
        // for (int i = 0; i < n; i++) {
        //     maxV[i / m] = max(maxV[i / m], baskets[i]);
        // }
        // for (int fruit: fruits) {
        //     int sec;
        //     int unset = 1;
        //     for (sec = 0; sec < section; sec++) {
        //         if (maxV[sec] < fruit) {
        //             continue;
        //         }
        //         int choose = 0; // 用于防止一个fruit放到多个basket里面
        //         maxV[sec] = 0; // 用于更新maxV
        //         for (int i = 0; i < m; i++) {
        //             int pos = sec * m + i;
        //             if (pos < n && baskets[pos] >= fruit && !choose) {
        //                 baskets[pos] = 0;
        //                 choose = 1;
        //             } 
        //             if (pos < n) {
        //                 maxV[sec] = max(maxV[sec], baskets[pos]);
        //             } // 重新计算maxV
        //         }
        //         unset = 0;
        //         break;
        //     }
        //     count += unset;
        // }
        // return count;

        // II.
        this->baskets = baskets;
        int m = baskets.size();
        int count = 0;
        if (m == 0) {
            return fruits.size();
        }
        build(1, 0, m - 1);
        for (int i = 0; i < m; i++) {
            int l = 0, r = m - 1,res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(1, 0, m - 1, 0, mid) >= fruits[i]) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (res != -1 && baskets[res] >= fruits[i]) {
                update(1, 0, m - 1, res, INT_MIN);
            } else {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numOfUplacedFruits
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,5]\n[3,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,1]\n[6,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */


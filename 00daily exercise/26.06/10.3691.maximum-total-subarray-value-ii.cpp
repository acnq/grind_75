/*
 * @lc app=leetcode.cn id=3691 lang=cpp
 * @lcpr version=30204
 *
 * [3691] 最大子数组总值 II
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
class SegTree {
    vector<int> maxv, minv;
    int n;

public:
    SegTree(vector<int>& nums) {
        n = nums.size();
        maxv.resize(n * 4);
        minv.resize(n * 4);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2, res = INT_MIN;
        if (ql <= m) {
            res = max(res, queryMax(node * 2, l, m, ql, qr));
        }
        if(qr > m) {
            res = max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2, res = INT_MAX;
        if (ql <= m) {
            res = min(res, queryMin(node * 2, l, m, ql, qr));
        }
        if(qr > m) {
            res = min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
};


class Solution {
    // I. ST表 + 最大堆
    // 固定左端点l, 右端点r增大时，nums[l:r]的最大值只增不减
    // 而最小值也是只减不增，因此子数组的“值”是单调递增的。
    // 每个左端点l, 有一个长度为n - l的单调递增序列，
    // 第i个元素为nums[l:(l+i)]的值，枚举l从1到n的所有n个
    // 单调递增序列，我们需要求出所有序列中前k大的元素之和
    // 注意到每个序列的末尾元素是该序列的最大值，我们使用堆来筛选
    // 每次取全局最大，然后将其前个元素入堆，重复k次：
    // 1. 初始时，每个序列的最后一个元素(r = n - 1)及其坐标(l, r)入堆
    // 2. 重复k: 弹出堆顶元素(v, l, r), v累积到答案，然后将同一序列的
    //      的前一个元素(l, r - 1), 放入堆中
    // 我们需要在O(1)时间内查询任意子数组[l, r]的最大最小值，
    // 这个可以用ST表（稀疏表），【也可以如II一样用线段树】
    // 预处理stMax[i][j]: 下标i开始，长度为2^j的区间内的最大值
    // 查询[l, r]时，令j = \floor{log2(r - l + 1)}
    // 则区间最值为max(st[l][j], st[r - 2^j + 1][j])
    // 这两个长度为2^j的区间恰好覆盖[l, r], 
    // 预处理用时O(nlogn)
    // tc: O(nlogn + klogn), sc: O(nlogn)

    // II. 线段树 + 最大堆
    // 我们使用线段树代替ST表，预处理sc: O(n), 查询用时O(logn)
    // 1. 预处理线段树，存储每个区间的最大值和最小值
    // 2. 对于左端点l, 子数组nums[l:(n-1)]的值放入最大堆
    // 3. 重复k: 弹出堆顶，累加答案，r > l, 则nums[l:(r-1)]入堆
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // I.
        // int n = nums.size();
        // int logn = 32 - __builtin_clz(n);
        // vector<vector<int>> stMax(n, vector<int>(logn));
        // vector<vector<int>> stMin(n, vector<int>(logn));
        // for (int i = 0; i < n; i++) {
        //     stMax[i][0] = stMin[i][0] = nums[i];
        // }   
        // for (int j = 1; j < logn; j++) {
        //     for (int i = 0; i + (1 << j) <= n; i++) {
        //         stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        //         stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]); 
        //     }
        // }
        
        // auto queryMax = [&](int l, int r) {
        //     int j = 31 - __builtin_clz(r - l + 1);
        //     return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        // };
        // auto queryMin = [&](int l, int r) {
        //     int j = 31 - __builtin_clz(r - l + 1);
        //     return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        // };
        // priority_queue<tuple<int, int, int>> pq;
        // for (int l = 0; l < n; l++) {
        //     pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
        // }
        // long long ans = 0;
        // while(k--) {
        //     auto [val, l, r] = pq.top();
        //     pq.pop();
        //     ans += val;
        //     if (r > l) {
        //         pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
        //     }
        // }

        // return ans;

        // II.
        int n = nums.size();
        SegTree seg(nums);
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.emplace(seg.queryMax(1, 0, n - 1, l, n - 1) - seg.queryMin(1, 0, n - 1, l, n - 1), l, n - 1);
        }
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(seg.queryMax(1, 0, n - 1, l, r - 1) - seg.queryMin(1, 0, n - 1, l, r - 1), l, r - 1);
            }
        } 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,1]\n3\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3721 lang=cpp
 * @lcpr version=30204
 *
 * [3721] 最长平衡子数组 II
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

#include <map>
// @lcpr-template-end
// @lc code=start

// I
struct LazyTag {
    int to_add = 0;

    LazyTag& operator+=(const LazyTag& other) {
        this->to_add += other.to_add;
        return *this;
    }

    bool has_tag() const {return to_add != 0;}

    void clear() {to_add = 0;}

};

struct SegmentTreeNode {
    int min_value = 0;
    int max_value = 0;
    // data不需要，只有叶节点有意义才需要
    LazyTag lazy_tag;
};

class SegmentTree {
private:
    inline void apply_tag(int i, const LazyTag& tag) {
        tree[i].min_value += tag.to_add;
        tree[i].max_value += tag.to_add;
        tree[i].lazy_tag += tag;
    }
    inline void pushdown(int i) {
        // 向下分发tag的变化
        if (tree[i].lazy_tag.has_tag()) {
            LazyTag tag = tree[i].lazy_tag;
            apply_tag(i << 1, tag); // i << 1 <=> i * 2
            apply_tag(i << 1 | 1, tag); // i << 1 <=> i * 2 + 1
            // 偶数最低位是0， +1 <=> | 1
            tree[i].lazy_tag.clear();
        }
    }

    inline void pushup(int i) {
        // 向上汇总左右子树的更新
        tree[i].min_value = min(tree[i << 1].min_value, tree[i << 1 | 1].min_value);
        tree[i].max_value = max(tree[i << 1].max_value, tree[i << 1 | 1].max_value);
    }

    void build(const vector<int>& data, int l, int r, int i) {
        if (l == r) {
            tree[i].min_value = tree[i].max_value = data[l - 1];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(data, l, mid, i << 1);
        build(data, mid + 1, r, i << 1 | 1);

        pushup(i);
    }

    void update(int target_l, int target_r, const LazyTag& tag, int l, int r, int i) {
        // target_l/r是操作（这里是更新）区间，l/r是i管理的区间
        if (target_l <= l && r <= target_r) {
            // 整个区间都要改
            apply_tag(i, tag); // 打懒标记，后续pushdown再改
            return;
        }
        pushdown(i); // 往下递归之前首先要传递懒标记保证真实，因为懒标记自身不累加
        // 仿子必传父
        int mid = l + ((r - l) >> 1);
        if (target_l <= mid) {
            // 更新左子
            update(target_l, target_r, tag, l, mid, i << 1);
        }
        if (target_r > mid) {
            // 更新右子
            update(target_l, target_r, tag, mid + 1, r, i << 1 | 1);
        }
        // 合并更新
        pushup(i);
    }

    int find(int target_l, int target_r, int val, int l, int r, int i) {
        if (tree[i].min_value > val || tree[i].max_value < val){
            // 目标<区间最小值或者目标>区间最大值=>val不在此区间
            return -1;
        }
        // 否则根据介值定理，此区间存在必然有解
        if (l == r) {
            return l;
        }
        pushdown(i); // 往下递归之前首先要传递懒标记保证真实
        int mid = l + ((r - l) >> 1);

        // target_l 一定<=r
        if (target_r >= mid + 1) {
            // 先搜索右子树
            int res = find(target_l, target_r, val, mid + 1, r, i << 1 | 1);
            if (res != -1) {
                return res;
            }
        }

        if (l <= target_r && mid >= target_l) {
            // 在搜索左子树
            return find(target_l, target_r, val, l, mid, i << 1);
        }
        return -1;
    }

public:
    int n;
    vector<SegmentTreeNode> tree;

    SegmentTree(const vector<int>& data) : n(data.size()) {
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag{val};
        update(l, r, tag, 1, n, 1);
    }

    int find_last(int start, int val) {
        if (start > n) {
            return -1;
        }
        return find(start, n, val, 1, n, 1);
    }
};

class Solution {
    // I. 前缀和 + 线段树
    // 不能使用滑动窗口，因为例如我们测试用例1，滑动窗口容易过早的抛弃最终答案的一部分
    // 假设出现一种新奇数元素记为-1，一种新的偶数元素记为+1, (旧元素记为0)，
    // 子数组平衡的条件即为转换后所有元素和为0
    // 我们计算此数组的前缀和，如果前缀和为0，则对应前缀子数组平衡
    // 固定左边界的情况下，最长的平衡子数组的右边界即为该前缀和中最后一个0所在的位置
    // 由于原数组变化量绝对值不超过1，前缀和有如下结论：如果前缀和数组中有1和-1，二者之间必有0
    // 我们用线段树寻找最右边的0，计算方案如下：
    // 1. 维护区间的最大值和最小值
    // 2. 判断0是否存在于右区间（位于最大值最小值构成的区间内），若存在则只搜索右区间
    // 3. 否则搜索左区间
    // 这个搜索可以用O(logn)时间完成，因为我们只要找到最大最小值即可
    // 接下来我们只要遍历左端点，寻找前缀和对应的最右侧0即可，设当前左边界下标i,
    // 已知最长平衡子数组长度为l, 搜索起点可以定为i+l,
    // 那么我们右移左端点的时候，如何撤销前一个位置元素对后面前缀和的贡献呢？
    // 假如元素x先后出现在位置p1,p2, p1处x贡献了区间[p1, p2-1], p2则贡献了[p2,:]
    // 因此，我们要将每种元素出现的所有位置记录到各自的队列，更新左边界时，
    // 得到要撤销贡献的元素在前缀和中的贡献区间，在此区间中减去它的贡献即可
    // tc: O(nlogn), sc: O(n)
public:
    int longestBalanced(vector<int>& nums) {
        map<int, queue<int>> occurrences;
        auto sgn = [](int x) {return (x % 2) == 0 ? 1: -1;};

        int len = 0;
        vector<int> prefix_sum(nums.size(), 0);

        prefix_sum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);

        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1];
            auto& occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefix_sum[i] += sgn(nums[i]);
            }
            occ.push(i + 1);
        }

        SegmentTree seg(prefix_sum);

        for (int i = 0; i < nums.size(); i++) {
            len = max(len, seg.find_last(i + len, 0) - i);

            auto next_pos = nums.size() + 1;
            occurrences[nums[i]].pop();
            if (!occurrences[nums[i]].empty()) {
                next_pos = occurrences[nums[i]].front();
            }

            seg.add(i + 1, next_pos - 1, -sgn(nums[i]));
        }
        return len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2]\n
// @lcpr case=end

 */


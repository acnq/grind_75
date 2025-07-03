/*
 * @lc app=leetcode.cn id=528 lang=cpp
 * @lcpr version=30204
 *
 * [528] 按权重随机选择
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

#include <random> // mt19937
#include <numeric> // accumulate
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 前缀和 + 二分查找
    // 设\sum_w = total, 我们将[1, total]范围内所有整数分为n个部分
    // n = |w|, 第i部分恰好包含w[i]个整数，并且这n各部分两两交集为空
    // 随后我们在[1, total]范围内随机选择整数x, 如果x包含在第i部分，返回i
    // e.g. w = [3, 1, 2, 4], 划分： [1, 3]; [4, 4]; [5, 6]; [7, 10]
    // 每个区间元素的左边界为她之前所有出现过的元素+1, 右边界为到她为止所有元素的和
    // 设pre[i] = \sum_{k=0}^iw[k], 第i个区间为[pre[i] - w[i] + 1, pre[i]]
    // 完成划分之后，我们假设随机到了整数x, 我们要找到
    // pre[i] - w[i] + 1 <= x < pre[i], 由于pre[i]递增，二分查找即可
    // tc: 初始化O(n), 选择O(logn); sc: O(n)
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;

public:
    Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Solution","pickIndex"][[[1]],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"][[[1,3]],[],[],[],[],[]]\n
// @lcpr case=end

 */


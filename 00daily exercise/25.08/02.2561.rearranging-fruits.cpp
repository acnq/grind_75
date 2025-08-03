/*
 * @lc app=leetcode.cn id=2561 lang=cpp
 * @lcpr version=30204
 *
 * [2561] 重排水果
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 贪心
    // 任意水果的成本x在两个果篮的总出现次数必定是偶数，否则无法将其均分到两个果篮
    // 我们要获取两个果篮之间水果成本的差异，用两个哈希表count_1, count_2分别统计
    // 两个果篮basket1和basket2的水果成本出现次数，对于水果成本x:
    // 1. 若count1[x] + count2[x] 不为偶数，返回-1
    // 2. 若count1[x] > count2[x], 那么basket1成本为x的水果需要交换其中
    // (count1[x] - count2[x]) / 2个到basket2，反之亦然
    // 根据2，枚举所有成本x, 并将成本以待交换的数量放置到列表merge, 然后merge从小到大排序
    // 根据贪心配对思想，前一半和后一半进行交换可以最小化交换成本，
    // 如果两个成本x_1<x_2的交换方案有两种，
    // 1. 直接交换，成本x1;
    // 2. 简介交换，x1先与两个果篮中成本最小值m交换，x2再与m交换，成本降为2*m
    // 遍历merge前一半元素，累积min(x, 2*m)到最终交换成本。
    // tc: O(nlogn), sc: O(n)
public: 
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> freq_map;
        for (int b1: basket1) {
            freq_map[b1]++;
            m = min(m, b1);
        }
        for (int b2: basket2) {
            freq_map[b2]--;
            m = min(m, b2);
        }
        vector<int> merge;
        for (auto[k, c]: freq_map) {
            if (c % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(c) / 2; i++) {
                merge.push_back(k);
            }
        }
        nth_element(merge.begin(), merge.begin() + merge.size() / 2, merge.end());
        // 半排序算法：将[merge[0], merge[-1]]中从大到小第merge[n/2]个元素放merge[n/2]
        // 同时把比他小的都放在左边，比他大的都放在右边。
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll, 
            [&](long long res, int x) -> long long {
                return res + min(2 * m, x);
            });
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,2,2]\n[1,4,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,1]\n[3,2,5,1]\n
// @lcpr case=end

 */


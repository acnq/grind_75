/*
 * @lc app=leetcode.cn id=632 lang=cpp
 * @lcpr version=30204
 *
 * [632] 最小区间
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
    // I. 贪心 + 最小堆
    // 问题可以转化为，从k个列表中各取一个数，使得这k个数中的最大值与最小值的差最小
    // 假设这k个数中的最小值是ith列表中的x, \forall j != i, 设第j个列表中被选为k个数之一的事y
    // y应该取第j个列表中大于等于x的最小的数字，
    // 注意到由于k个列表都是升序排列，所以给每个列表维护一个指针，
    // 使用最小堆维护k个指针指向的元素中最小值，同时维护堆中元素的最大值，每次从堆中取出最小值，
    // 根据最大值和最小值计算当前区间，如果当前区间小于最小区间则用当前区间更新最小区间，并更新堆中元素最大值
    // 如果一个列表的指针超出该列表的下标范围，则说明该列表中所有元素都被遍历过，堆中不会有列表元素，退出循环。
    // tc: O(nklogk), n: 所有列表平均长度，k列表数量； sc: O(k)

    // II. 哈希表 + 滑动窗口
    // 参考T76, 设A序列为0:(k-1)表示k个列表，我们想要在一个B序列中找到一个区间，可以覆盖A序列
    // B序列如下构造：B[i]表示i在哪些列表中出现过，用哈希表表示，键为列表中的某个数值，值为某个数组
    // 数组的元素为当前键在哪些列表中。
    // 仿照T76, 我们在B序列上维护两个指针限定的滑动窗口，并用一个哈希表维护当前串口中已经包含了哪些列表中的元素
    // 遍历B中每个元素
    // 1. 指向窗口右边界的指针右移当前仅当每次遍历到锌元素，将这个信元素对应的值数组中的每个数加入到哈希表
    // 2. 指向窗口左边界的指针右移当前仅当当前区间内的元素包含A中所有元素，同时将原来的左边界对应的值数组的元素从哈希表中移除
    // 3. 答案更新当前仅当当前窗口内的元素包含A中所有元素。
    // tc: O(nk + |V|), |V|: 列表中元素的值域， sc: O(nk)
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // I.
        // int left = 0, right = INT_MAX;
        // int size = nums.size();
        // vector<int> next(size);

        // auto cmp = [&](const int& u, const int& v) {
        //     return nums[u][next[u]] > nums[v][next[v]];
        // };
        // priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        // int minValue = 0, maxValue = INT_MIN;
        // for (int i = 0; i < size; i++)
        // {
        //     pq.emplace(i);
        //     maxValue = max(maxValue, nums[i][0]);
        // }
        
        // while (true)
        // {
        //     int row = pq.top();
        //     pq.pop();
        //     minValue = nums[row][next[row]];
        //     if (maxValue - minValue < right - left)
        //     {
        //         left = minValue;
        //         right = maxValue;
        //     }
        //     if (next[row] == nums[row].size() - 1)
        //     {
        //         break;
        //     }
        //     next[row]++;
        //     maxValue = max(maxValue, nums[row][next[row]]);
        //     pq.emplace(row);
        // }
        // return {left, right};

        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (const int& x: nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }

        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;

        while (right < xMax)
        {
            right++;
            if (indices.count(right))
            {
                for (const int& x: indices[right]) {
                    freq[x]++;
                    if (freq[x] == 1)
                    {
                        inside++;
                    }
                }
                while (inside == n)
                {
                    if (right - left < bestRight - bestLeft)
                    {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left))
                    {
                        for (const int& x: indices[left]) {
                            freq[x]--;
                            if (freq[x] == 0)
                            {
                                inside--;
                            }
                        }
                    }
                    left++;
                }
            }
        }
        return {bestLeft, bestRight};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[1,2,3],[1,2,3]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30204
 *
 * [435] 无重叠区间
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
    // I. DP
    // 题目等价于“选出最少的区间，使得彼此互不重叠”
    // 首先按照端点从小到大排序，随后即可使用dp
    // 设左右端点的序列为l_0:l_{n-1}; r_0:r_{n-1}
    // f_i: “区间i为最后一个区间，可以选出的区间数量最大值”
    // f_i = \max_{j < i \land r_j \leq l_i} {f_j} + 1, 如果没有满足的f_j, f_i = 1
    // 最后答案就是f_i中的最大值。
    // tc: O(n^2); sc: O(n) c++会超时

    // II. 贪心
    // 假设某一种最优方法中，[l_k, r_k]为最左侧的区间，设想一下，如果有另一个区间
    // [l_j, r_j], s.t. r_j < r_k, 那么把区间k替换为j, 他和剩余的右侧区间也是不重叠的，
    // 所以这也是一个最优解法，这启示我们：
    // 首个区间总是可以选择为所有区间中右端点最小的那个元素。于是我们得到了一个最优子结构
    // 如果有多个区间的右端点同样小如何呢？由于最左侧没有其他区间可以影响了，那么左端点何处并不重要
    // 我们可以任选
    // 这时我们发现，问题规模已经减小了1，那么下一个区间，我们只要找到首个与第一个区间不重合，
    // 且右端点最小的区间即可
    // tc: O(n logn); sc: O(logn)
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if (intervals.empty())
        // {
        //     return 0;
        // }
        // sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v){
        //     return u[0] < v[0];
        // });

        // int n = intervals.size();
        // vector<int> f(n, 1);
        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (intervals[j][1] <= intervals[i][0])
        //         {
        //             f[i] = max(f[i], f[j] + 1);
        //         }
        //     }
        // }
        // return n - *max_element(f.begin(), f.end());

        // II.
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= right)
            {
                ans++;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */


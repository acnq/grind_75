/*
 * @lc app=leetcode.cn id=1840 lang=cpp
 * @lcpr version=30204
 *
 * [1840] 最高建筑高度
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
    // I. 限制传递
    // 我们将restrictions简写为(i, hi), 表示建筑i高度不超过hi
    // 如果建筑i的高度不能超过hi, 则因为相邻建筑的高度差不能超过1
    // 所以建筑j高度不能超过hi + |i - j|
    // 我们据此得到第i栋建筑的真正最低限制，limit_i, 
    // 表示第i栋建筑的最高高度为limit_i;
    // 注意，我们发现n在10^9的数量级上，所以O(n)得到limit_i, 也超限
    // 为此，我们关注所有n栋建筑高度的最大值，
    // 假设有两栋建筑i,j; i<j且除了limit_i和limit_j之外没有别的限制
    // 那么在i,j之间，我们可以形成一个山脉，从i单调递增到最大值，
    // 然后单调递减到j, 假设这个最大值为best(i, j):
    // (best(i, j) - limit_i) + (best(i, j) - limit_j) <= j - i
    // 解得：
    // best(i, j) = \floor{((j - i) + limit_i + limit_j) / 2}
    // 于是问题转化为求出所有limit_i
    // 为了方便处理边界情况，我们在restrictions中添加(1, 0)和(n, n - 1)
    // 我们对限制数组进行两次遍历，分别‘从左到右’和‘从右到左'
    // 每次只处理restriction数组中相邻的i和j
    // 1. '从左到右’：(i, hi)传递到j会变为(j, hi + (j - i))
    //      将hj更新为较小值即可
    // 2. '从右到左': i变为(i, hj + (j - i)), hi更新为较小值即可
    // 之后所有hi即为limit_i, 然后结合best(i,j)的算法填充没有limit
    // 的best即可
    // tc: O(mlogm), sc: O(logm)
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;  // 无论res是左值或者右值都直接引用
        // 增加限制(1, 0)
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        // 增加限制(n, n - 1)
        if (r.back()[0] != n) {
            r.push_back({n, n - 1});
        }

        int m = r.size();

        // 左向右传递 (只处理相邻的restrictions)
        for (int i = 1; i < m; i++) {
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }
        // 从右向左传递  (只处理相邻的restrictions)
        for (int i = m - 2; i >= 0; i--) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        int ans = 0;
        for (int i = 0; i < m - 1; i++) {
            // 计算r[i][0]和r[i + 1][0]之间的建筑的最大高度
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[2,1],[4,1]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[[5,3],[2,5],[7,4],[10,3]]\n
// @lcpr case=end

 */


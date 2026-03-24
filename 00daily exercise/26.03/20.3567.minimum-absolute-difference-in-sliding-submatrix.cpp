/*
 * @lc app=leetcode.cn id=3567 lang=cpp
 * @lcpr version=30204
 *
 * [3567] 子矩阵的最小绝对差
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
    // I. 排序
    // 每个连续的k * k子阵,将子矩阵的所有元素放到数组kgrid里,
    // 然后排序,遍历kgrid, 计算数组kgrid所有相邻且不等的元素间差值
    // 即得子阵的最小绝对差
    // tc: O((m - k) * (n - k) * k^2 * logk), sc: O(k^2)
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> kgrid;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.push_back(grid[x][y]);
                    }
                }
                int kmin = INT_MAX;
                sort(kgrid.begin(), kgrid.end());
                for (int t = 1; t < kgrid.size(); t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != INT_MAX) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,8],[3,-2]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[3,-1]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,-2,3],[2,3,5]]\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3558 lang=cpp
 * @lcpr version=30204
 *
 * [3558] 给边赋权值的方案数 I
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
    // I. DFS + 数学
    // 以1为根的树，需要找到深度最深的节点x, 然后计算1到x的路径
    // 权值之和为奇数的赋值方案，注意权值2不影响奇偶性，
    // 路径和的奇偶性仅取决于权值为1的边数量是否为奇数
    // 我们先计算节点1到x的距离max_dp
    // 然后我们计算从max_dp条边中选择奇数条边的方案数
    // d[i][0]: 从i条边中选择偶数条边赋值为1的方案数
    // d[i][1]:             奇数                
    // d[i][1] = d[i - 1][0] + d[i - 1][1]
    // d[i][0] = d[i - 1][0] + d[i - 1][1]
    // (e.g. 以 d[i][1] 为例，
    // 第 i 条边赋值为 1 和赋值为 2 两种方案，
    // 对应于 d[i−1][0] 和 d[i−1][1])
    // init: d[0][0] = 1, d[0][1] = 0, 
    // ans: d[max_dp][1]
    // 发现i >= 1时，d[i][1] = d[i][0]
    // d[max_dp][0] + d[max_dp][1] = 2^{max_dp}, 
    // 所以答案为2^{max_dp - 1}
    // tc: O(n), sc: O(n)
public:
    static constexpr int mod = 1e9 + 7;
    int qpow(int x, int y) { // 快速幂
        int res = 1;
        for (;y; y>>=1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    int dfs(vector<vector<int>>& g, int x, int f) {
        int max_dp = 0;
        for (auto& y : g[x]) {
            if (y == f) {
                continue;
            }
            max_dp = max(max_dp, dfs(g, y, x) + 1);
        }
        return max_dp;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e: edges) {
            int u = e[0];
            int v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_dp = dfs(g, 1, 0);
        return qpow(2, max_dp - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,3],[3,4],[3,5]]\n
// @lcpr case=end

 */


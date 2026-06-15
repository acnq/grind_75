/*
 * @lc app=leetcode.cn id=3559 lang=cpp
 * @lcpr version=30204
 *
 * [3559] 给边赋权值的方案数 II
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
class LCA {
private:
    int n;
    int m;
    vector<int> d;
    vector<vector<int>> e;
    vector<vector<int>> f;

public:
    LCA(const vector<vector<int>>& edges, const int root = 1) {
        n = edges.size() + 1;
        m = (log(n) / log(2)) + 1;
        e.resize(n + 1); 
        d.resize(n + 1);
        f.resize(n + 1, vector<int>(m, 0));
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        for (int i = 1; i < m; i++) {
            for(int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }
    void dfs(int x, int fa) {
        f[x][0] = fa;
        for (auto& y: e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }

    int dis(int x, int y) {
        return d[x] + d[y] - d[(lca(x, y))] * 2;
    }
};

const int MOD = 1e9 + 7;
const int N = 100010;
int p2[N];
auto init = [] {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    return 0;
}();

class Solution {
    // I. LCA + 数学
    // 和T3558相比只是把从到根节点的长度变成了任意两点之间的长度
    // 要计算任意两点间的长度，我们可以首先计算最近公共祖先（LCA)
    // 再根据容斥原理计算出距离，d[x]: 结点x到根的距离
    // x和y的距离=d[x] + d[y] - 2 * d[lca(x, y)]
    // 参考T1483计算树上任意两点的最近公共祖先，简单来说
    // 预处理每个结点的第2^k个祖先，
    // f[x][k]: x向上跳2^k步到达的祖先，
    // f[x][k] = f[f[x][k - 1]][k - 1]
    // 查询最近公共祖先时，先将两点调整到同一深度，再利用二进制
    // 拼凑的方式同步上跳，最终相遇的节点为最近公共祖先
    // 已知x,y的距离，设为dis, 从中选出奇数个方案数的个数为2^(dis - 1)
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA lca(edges, 1);
        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                res[i] = p2[lca.dis(x, y) - 1];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2]]\n[[1,1],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,3],[3,4],[3,5]]\n[[1,4],[3,4],[2,5]]\n
// @lcpr case=end

 */


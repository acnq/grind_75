/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 * @lcpr version=30204
 *
 * [2685] 统计完全连通分量的数量
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

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n): parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[y] > rank[x]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
};
class Solution {
    // I. DFS
    // 完全连通分量的边数E和点数V有如下等式: E=V(V - 1) / 2
    // DFS遍历到点就把所有链接这个点的边加入到E中
    // tc = sc = O(V + E), 

    // II.BFS:
    // 通过BFS搜索同个图中的节点
    // tc = sc = O(V + E), 

    // III. 并查集
    // fa: 每个结点的父节点，ie.所属集合
    // numV, numE: 每个节点包含的点和边的数量，
    // 遍历edges过程中将相连节点放入同一个集合
    // 完成预处理之后, 遍历节点，Find函数找到节点i所属的x，
    // numV[find(i)]++;
    // 遍历边，找到edge所属的集合x, numE[find(edge[0])]++;
    // 对每个集合判断numE和numV是否满足等式
    // tc: O((V + E) * \alpha(V)), sc: O(V)
    // \alpha(x): x的反阿克曼数
public:

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // I.
        // vector<int> visit(n, 0);
        // vector<vector<int>> g(n);
        // for (auto& e: edges) {
        //     int u = e[0];
        //     int v = e[1];
        //     g[u].push_back(v);
        //     g[v].push_back(u);
        // }
        // int ans = 0, V, E;
        // auto dfs = [&](auto&& dfs, int u) -> void {
        //     visit[u] = 1;
        //     V++;
        //     E += g[u].size();
        //     for (int v: g[u]) {
        //         if (!visit[v]) {
        //             dfs(dfs, v);
        //         }
        //     }
        // };

        // for (int i = 0; i < n; i++) {
        //     if (!visit[i]) {
        //         V = 0;
        //         E = 0;
        //         dfs(dfs, i);
        //         ans += E == V * (V - 1); // 点统计了两遍
        //     }
        // }
        // return ans;

        // II.
        // vector<vector<int>> g(n);
        // vector<int> vis(n, 0);
        // int ans = 0, V, E;
        // for (auto edge: edges) {
        //     int u = edge[0];
        //     int v = edge[1];
        //     g[u].push_back(v);
        //     g[v].push_back(u);
        // }
        // auto bfs = [&](int s) -> bool {
        //     queue<int> q;
        //     q.push(s);
        //     while (!q.empty()){
        //         int u = q.front();
        //         q.pop();
        //         if (vis[u]) {
        //             continue;
        //         }
        //         vis[u] = 1;
        //         V++;
        //         E += g[u].size();
        //         for (auto v: g[u]) {
        //             q.push(v);
        //         }
        //     }
        //     return E == V * (V - 1);
        // };
        // for (int i = 0; i < n; i++) {
        //     if (!vis[i]) {
        //         V = 0;
        //         E = 0;
        //         if (bfs(i)) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // II.
        DSU dsu(n);
        for (auto& edge: edges){
            dsu.unionSet(edge[0], edge[1]);
        }

        vector<int> numV(n, 0);
        vector<int> numE(n, 0);
        for (int i = 0; i < n; i++) {
            numV[dsu.find(i)]++;
        }
        for (auto& edge: edges){
            numE[dsu.find(edge[0])]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                ans += numE[i] == (numV[i] * (numV[i] - 1) / 2);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4],[3,5]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=310 lang=cpp
 * @lcpr version=30204
 *
 * [310] 最小高度树
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
    // I. BFS
    // dist[x][y]: 节点x和节点y的距离
    // 假设书中距离最长的两个节点为(x*, y*)
    // maxdist = dist[x*][y*], 树的最小高度为minheight = \ceiling(maxdist / 2)
    // 且最小高度树的根节点一定在x*到y*的路径上
    // (证明：
    //      1. 证明高度，反证法，假设存在节点z, 以节点z为根的树的高度h < minheight
    //          讨论z在不在从x,y的路径上，都可以证明dist[x][y] < dist[x][y])
    //      2. 证明最小高度树的根节点一定在x,y的路径上, 反证，设z到x,y有两条路径，从a分差
    //          可知dist[a][x] + dist[a][y] < dist[x][y], 矛盾)
    // 假设最长路径的m个节点依次为p_1 -> p_2 -> ...... -> p_m
    // 如果m为偶数，节点p_{m/2}或p_{m/2 + 1}, 高度为m / 2
    // 如果m为奇数，根节点p_{(m + 1) / 2}，最小高度(m - 1) / 2
    // 因此我们只需要求出路径最长的两个叶子节点，再求出中间节点, 即为最小高度树的根节点
    // 算法：
    //  1. 任意结点p，广搜或者深搜找到以p为起点的最终路径的终点x;
    //  2. 节点x出发，以x为起点的最长路径的终点y
    //  3. x, y路径即为上文所要求的最长路径
    //  证明见这里：https://oi-wiki.org/graph/tree-diameter/

    // II DFS
    // 将上文的广搜变为深搜

    // III. 拓扑排序
    // 假设树中距离最大的两个节点为(x, y), 距离为maxdist = dist[x][y]
    // 路径为x -> p_1 -> ... ... -> p_k -> y
    // 删除最外层度为1的节点x, y后，相邻p_1, p_k变为节点为1
    // algo:
    //  1. 首先找到所有度为1的节点压入队列，令节点剩余计数remainNodes=n;
    //  2. remainNodes--, 最外层度为1的叶子结点取出，相邻节点度减少，度为1的节点压入队列
    //  3. 重复，直到remainNodes < 2, 剩余的节点就是当前高度最小树的根

public:
    // I.
    // int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
    //     int n = adj.size();
    //     queue<int> qu;
    //     vector<bool> visit(n);
    //     qu.emplace(u);
    //     visit[u] = true;
    //     int node = -1;

    //     while (!qu.empty())
    //     {
    //         int cur = qu.front();
    //         qu.pop();
    //         node = cur;
    //         for(auto& v: adj[cur]) {
    //             if (!visit[v])
    //             {
    //                 visit[v] = true;
    //                 parent[v] = cur;
    //                 qu.emplace(v);
    //             }
    //         }
    //     }
    //     return node;
    // }

    // II. 
    void dfs(int u, vector<int>& dist, vector<int>& parent, const vector<vector<int>>& adj) {
        for(auto& v: adj[u]) {
            if (dist[v] < 0)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                dfs(v, dist, parent, adj);
            }
        }
    }
    // II.
    // int findLongestNode(int u, vector<int>& parent, const vector<vector<int>>& adj) {
    //     int n = adj.size();
    //     vector<int> dist(n, - 1);
    //     dist[u] = 0;
    //     dfs(u, dist, parent, adj);
    //     int maxdist = 0;
    //     int node = -1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (dist[i] > maxdist)
    //         {
    //             maxdist = dist[i];
    //             node = i;
    //         }
    //     }
    //     return node;
    // }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // I.
        // if (n == 1)
        // {
        //     return {0};
        // }

        // vector<vector<int>> adj(n);
        // for(auto& edge: edges) {
        //     adj[edge[0]].emplace_back(edge[1]);
        //     adj[edge[1]].emplace_back(edge[0]);
        // }

        // vector<int> parent(n, -1);
        // /* 找到与节点0距离最远的节点x */
        // int x = findLongestNode(0, parent, adj);
        // /* 找到与节点x最远的节点y */
        // int y = findLongestNode(x, parent, adj);
        // /* 求出节点x到节点y的路径 */
        // vector<int> path;
        // parent[x] = -1;
        // while (y != -1)
        // {
        //     path.emplace_back(y);
        //     y = parent[y];
        // }
        // int m = path.size();
        // if (m % 2 == 0)
        // {
        //     return {path[m / 2 - 1], path[m / 2]};
        // } else {
        //     return {path[m / 2]};
        // }
        // II.
        // if (n == 1)
        // {
        //     return {0};
        // }

        // vector<vector<int>> adj(n);
        // for(auto& edge: edges) {
        //     adj[edge[0]].emplace_back(edge[1]);
        //     adj[edge[1]].emplace_back(edge[0]);
        // }

        // vector<int> parent(n, -1);
        // /* 找到与节点0距离最远的节点x */
        // int x = findLongestNode(0, parent, adj);
        // /* 找到与节点x最远的节点y */
        // int y = findLongestNode(x, parent, adj);
        // /* 求出节点x到节点y的路径 */
        // vector<int> path;
        // parent[x] = -1;
        // while (y != -1)
        // {
        //     path.emplace_back(y);
        //     y = parent[y];
        // }
        // int m = path.size();
        // if (m % 2 == 0)
        // {
        //     return {path[m / 2 - 1], path[m / 2]};
        // } else {
        //     return {path[m / 2]};
        // }

        if (n == 1)
        {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
            {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2)
        {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++)
            {
                int cur = qu.front();
                qu.pop();
                for(auto& v: adj[cur]) {
                    if (--degree[v] == 1)
                    {
                        qu.emplace(v);
                    }
                }
            }
        }

        while (!qu.empty())
        {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,0],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
// @lcpr case=end

 */


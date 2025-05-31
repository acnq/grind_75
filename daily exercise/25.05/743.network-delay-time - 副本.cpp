/*
 * @lc app=leetcode.cn id=743 lang=cpp
 * @lcpr version=30204
 *
 * [743] 网络延迟时间
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
    // 本题作为Dijkstra算法的例题
    // 主要思想：贪心

    // 每次从“未确定节点”中取一个与起点距离最短的点，归为“已确定节点”
    // 用他“更新”从起点到其他所有“未确定节点”的距离，直到所有点都归为“已确定”
    // "更新"：从A“更新”B意为，min(起点到节点A的最短路长度+AB边长, 起点到节点B的最短路长度)
    // 也叫做“松弛”
    
    // I. Dijkstra
    // k到x的时间就是k->x的最短路，需要求出k到其余所有店的最短路
    // 最大值就是答案，若存在从k无法到达的节点，返回-1
    // I.i 枚举
    // I.ii 小根堆
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // I.i
        // const int inf = INT_MAX / 2;
        // vector<vector<int>> g(n, vector<int>(n, inf));
        // for (auto& t: times)
        // {
        //     int x = t[0] - 1, y = t[1] - 1;
        //     g[x][y] = t[2];
        // }
        // vector<int> dist(n, inf);
        // dist[k - 1] = 0;
        // vector<int> used(n);
        // for (int i = 0; i < n; i++)
        // {
        //     int x = -1;
        //     for (int y = 0; y < n; y++)
        //     {
        //         if (!used[y] && (x == -1 || dist[y] < dist[x]))
        //         {
        //             x = y;
        //         }
        //     }
        //     used[x] = true;
        //     for (int y = 0; y < n; y++)
        //     {
        //         dist[y] = min(dist[y], dist[x] + g[x][y]);
        //     }
        // }
        
        // int ans = *max_element(dist.begin(), dist.end());
        // return ans == inf? -1: ans;
        
        // I.ii
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for(auto& t: times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty())
        {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time)
            {
                continue;
            }
            for(auto& e: g[x])
            {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y])
                {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1: ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */


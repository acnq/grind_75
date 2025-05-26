/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 * @lcpr version=30204
 *
 * [1857] 有向图中最大颜色值
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
    // 5.26.2025
    // I.
    // 对于一种颜色c, 以及一条路径path, 
    // 记path_c: 路径path中颜色为c的节点个数
    // 问题等价于：枚举c, 选出使得path_c达到最大值的path, 这些path_c中最大的即为答案
    // 给定有向图有环，则不存在拓补排序，否则，则是DAG，一定存在拓扑排序
    // 显然一条路径上点的顺序与他们在拓扑排序中出现的顺序
    // 结论：拓扑排序+DP
    
    // f(v, c): v为终点的所有路径中，包含颜色c的节点数量的最大值
    // 考虑所有v的前驱结点prev_v:
    // f(v, c) = (max_{u \in prev_v} f(u, c)) + 1(v, c)
    // 找出前驱结点中包含颜色c的节点数量最多的那个节点进行转移，
    // 如果v本身颜色为c, f(v, c)值还要+1， 1(v, c)为示性函数，v颜色为c时=1，否则为0
    // path_c = max_{v}f(v, c)

    // 思路:
    // 直接将转移方法加入BFS求解拓扑排序
    // 遍历到节点u时：
    //  1.u颜色为c, f(u, c)++
    //  2.枚举u的所有后继结点v，f(v, c) 更新为其与f(u, c)的较大值
    // 这样比上面的存储前驱好一点
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        
        vector<vector<int>> g(n);
        // 邻接表
        
        vector<int> indeg(n);
        // 节点入度统计，用于找出拓扑排序的最开始节点
        for(auto&& edge: edges) {
            indeg[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
        }

        // 记录拓扑排序过程中遇到的节点个数
        // 如果最终found的值不为n, 说明图中有环
        int found = 0;
        vector<array<int, 26>> f(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!indeg[i])
            {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            found++;
            int u = q.front();
            q.pop();
            // u 对应的颜色++
            f[u][colors[u] - 'a']++;
            // 枚举u的后继结点v
            for(int v: g[u]) {
                indeg[v]--;
                // f(v, c)更新为f(u, c)的较大值
                for (int c = 0; c < 26; c++)
                {
                    f[v][c] = max(f[v][c], f[u][c]);
                }
                if (!indeg[v])
                {
                    q.push(v);
                }
            }
        }

        if (found != n)
        {
            return -1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, *max_element(f[i].begin(), f[i].end()));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abaca"\n[[0,1],[0,2],[2,3],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// "a"\n[[0,0]]\n
// @lcpr case=end

 */


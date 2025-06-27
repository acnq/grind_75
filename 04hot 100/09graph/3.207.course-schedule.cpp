/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
    // 这是一道拓扑排序题目
    // I. DFS
    // 用一个栈来存储所有已经搜索完成的节点
    // 1. 任取未搜索的节点u，标记为“搜索中”，遍历该节点的每个相邻节点v（有向边可通达的节点）
    //      1.1 若v未搜索，开始搜索v, 待搜索完回溯到u;
    //      1.2.若v被标记为“搜索中”，则已经出现环，返回不存咋拓扑排序。
    //      1.3.若v为“已搜索”，则v已经被访问而u还未，但u无论如何入栈都不会影响二者关系，不进行任何操作
    // 2. u的所有相邻节点都“已搜索”，u入栈，u也标记为“已搜索”
    // 以上没有发现环的话，栈中自顶向下就是个拓扑排序
    // 注意到此题我们甚至不需要返回一个拓扑排序，而只需要判断有无环
    // 为此我们省去栈，记录每个节点的状态就可以了。

    // II. BFS
    // 考虑拓扑排序的第一个节点，他一定是没有入边的，将他加入答案之后，直接移除它的所有出边
    // 如果这导致了它的某个相邻节点变成了0入边的节点，就代表这个节点也可以加入答案了
    // 如此反复，直到答案包含所有节点（得到一种拓扑排序），或者找不到任何0入边的节点（有环）
    // 用队列储存所有0入边的节点
    // 首先取出队首u
    //  u放入答案
    //  移除u所有出边，u所有邻接点入度-1，如果邻接点v入度=0， v放入队列
public:
    // I.
    // vector<vector<int>> edges;
    // vector<int> vis; // visited
    // bool valid = true;

    // II.
    vector<vector<int>> edges;
    vector<int> indeg; 

    // I.
    // void dfs(int u) {
    //     vis[u] = 1; // 正在搜索
    //     for(int v: edges[u]) {
    //         if (vis[v] == 0) 
    //         { // 0: 未搜索
    //             dfs(v);
    //             if (!valid)
    //             {
    //                 return;
    //             }
    //         } else if (vis[v] == 1)
    //         {
    //             valid = false;
    //             return;
    //         }
    //     }
    //     vis[u] = 2; // 搜索完成
    // }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // I.
        // edges.resize(numCourses);
        // vis.resize(numCourses);
        // for (const auto& info: prerequisites) {
        //     edges[info[1]].push_back(info[0]); // info1的是info0的先修课
        // }
        // for (int i = 0; i < numCourses && valid; i++)
        // {
        //     if (!vis[i])
        //     {
        //         dfs(i);
        //     }
        // }
        // return valid;

        // II.
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        
        int vis = 0;
        while (!q.empty())
        {
            vis++;
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return vis == numCourses;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */


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
    // 拓扑排序
public:
    // dfs
    // vector<vector<int>> edges;
    // vector<int> visited;
    // bool valid = true;
    // bfs
    vector<vector<int>> edges;
    vector<int> indeg;
    
    // void dfs(int u) {
    //     visited[u] = 1;
    //     for (int v: edges[u])
    //     {
    //         if (visited[v] == 0)
    //         {
    //             dfs(v);
    //             if (!valid)
    //             {
    //                 return;
    //             }
    //         }
    //         else if (visited[v] == 1)
    //         {
    //             valid = false;
    //             return;
    //         }
    //     }
    //     visited[u] = 2;
    // }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs
        // 未搜索：没有搜索到这个节点
        // 搜索中：搜索过但是没有回溯到节点，该节点还没有入栈，还有相邻节点没有搜索完成
        // 已完成：回溯过这个节点，已经入栈，所有该节点的相邻节点都在栈的更底部，满足拓扑条件

        // algo:
        // 任取一个“未搜索”节点u，
        //   遍历该节点的相邻节点v, 
        //      如果v为“未搜索”，搜索v, 待完成回溯u；
        //      如果v为“搜索中”，找到了图中的环，不存在拓扑排序
        //      如果v为“已完成”，说明v已经在栈中了，而u还不在栈中，因此u无论何时入栈都不会
        //          影响到(u, v)之前的拓扑关系，不用进行任何操作
        //  u的所有相邻节点都为“已完成”，u放入栈中，标记为“已完成”

        // 上述过程没有找到图中的环，那么栈中存储的所有n个节点，从栈顶到栈底的顺序为一种拓扑排序
        // 因为拓扑排序的结果不需要返回，我们可以省去栈，而只记录每个节点的状态
        // edges.resize(numCourses);
        // visited.resize(numCourses);
        // for (const auto& info: prerequisites)
        // {
        //     edges[info[1]].push_back(info[0]);
        // }
        // for (int i = 0; i < numCourses && valid; i++)
        // {
        //     if (!visited[i])
        //     {
        //         dfs(i);
        //     }
        // }
        // return valid;

        // bfs
        // 顺序加入节点，首先加入的节点一定不会有任何入边
        // 加入一个节点之后，移除它的所有出边，代表和它相邻节点
        // 少了一门先修课，直到某个相邻节点变成没有入边，加入此节点
        // 直到答案中包含所有节点，或者不存在没有入边的节点（包含环）
        // algo:
        // 所有入度为0的节点都被放入队列，
        // 每一步，队首节点取出为u:
        //      u放入答案；
        //      移除u所有出边，如果邻节点v的入度变为0，将v放入队列
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        
        int visited = 0;
        while (!q.empty())
        {
            visited++;
            int u = q.front();
            q.pop();
            for (int v : edges[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }        
        return visited == numCourses;
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


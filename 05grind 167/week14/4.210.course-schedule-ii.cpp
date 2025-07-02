/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30204
 *
 * [210] 课程表 II
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
    // 和207相比的区别在于这次要返回一个可行的拓扑排序
    // I. DFS
    // 和207类似，\forall u, 如果所有相邻结点都“已搜索”，则回溯到u，让u也“已搜索”
    // 如果我们把所有“已搜索”的元素入栈，那么u会出现在所有相邻元素前面（栈顶作为最前）
    // 那么我们进行DFS之后，栈顶到栈底就会形成所需要的拓扑排序，
    // 具体dfs可以参考T201, 关键是如果u在“搜索中”，遇到其相邻节点v也在“搜索中”，那么直接返回false
    // 遇到v未搜索则开始搜索v, v"已搜索“则不做任何操作，当u所有节点”已搜索“，u入栈并标记为”已搜索“
    // tc/sc: O(n + m); n课程数，m要求数
    // II. BFS
    // 所有入度为0的节点入队作为拓扑排序最前面的节点，这些节点彼此之间的顺序其实无关紧要
    // 因此，我们每次取出队首节点u, 直接将其放入答案，然后移除它的所有出边，
    // 如果这导致某个相邻的节点v的入度也变为0，将其入队
    // bfs完成之后如果覆盖了所有节点则无环，返回答案，如果还有节点，则有环返回false。
public:
    // I. DFS
    // // 存储有向图
    // vector<vector<int>> edges;
    // // 标记搜索状态：0=未搜索；1=搜索中；2=已搜索
    // vector<int> vis;
    // // 数组模拟栈，0为底，n-1为顶，方便遍历
    // vector<int> res;
    // // 判断是否有环
    // bool valid = true;

    // void dfs(int u) {
    //     // 标记节点为搜索中
    //     vis[u] = 1;
    //     // 搜索相邻节点
    //     // 发现环立即停止
    //     for (int v: edges[u]) {
    //         // v未搜索：直接搜索v
    //         if (vis[v] == 0)
    //         {
    //             dfs(v);
    //             if (!valid)
    //             {
    //                 return;
    //             }
    //         } else if (vis[v] == 1)
    //         { // v搜索中：找到环
    //             valid = false;
    //             return;
    //         }
    //     }
    //     // 标记u为“已搜索”
    //     vis[u] = 2;
    //     // 入栈
    //     res.push_back(u);
    // }

    // II. BFS
    // 存储图
    vector<vector<int>> edges;
    // 存储入度
    vector<int> indeg;
    // 存储答案
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // I.
        // edges.resize(numCourses);
        // vis.resize(numCourses);
        // for(const auto& info: prerequisites) {
        //     edges[info[1]].push_back(info[0]);
        // }
        // // 挑选“未搜索”的节点开始深搜
        // for (int i = 0; i < numCourses && valid; i++)
        // {
        //     if (!vis[i])
        //     {
        //         dfs(i);
        //     }
        // }
        // if (!valid)
        // {
        //     return {};
        // }
        // // 无环直接返回拓扑排序，注意要反序
        // reverse(res.begin(), res.end());
        // return res;

        // II. 
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        // 入度为0的节点放入队列
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            // 队首取出一个节点
            int u = q.front();
            q.pop();
            // 放入答案中
            res.push_back(u);
            for(int v: edges[u]) {
                indeg[v]--;
                // 若相邻节点v入度为0，可以选v对应的课程
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        if (res.size() != numCourses)
        {
            return {};
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */


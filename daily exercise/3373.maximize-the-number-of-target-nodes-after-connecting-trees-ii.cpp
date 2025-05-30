/*
 * @lc app=leetcode.cn id=3373 lang=cpp
 * @lcpr version=30204
 *
 * [3373] 连接两棵树后最大目标节点数目 II
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
    // 5.25.2025
    // I DFS:
    // 我们使用DFS染色，对两颗树如下染色
    // 根节点和距离根偶数距离的染成白色0，其他染成黑色1
    // 将白色和黑色节点的数目也保存下来，显然，任意结点的目标节点与原节点颜色相同
    // 染色的结果是两个包含01的一维数组color_1, color_2, 以及两棵树中黑白节点的数目 
    // 查询结果如下：
    // 1. color1[i]找到节点i的颜色，（那么对应颜色的节点数目即为第一棵树的结果）
    // 2. 加上第二棵树中黑色/白色节点的数目的最大值（无论如何链接，第二棵树上的目标节点都是同色的，而且都能取到）
public:
    int dfs(int node, int parent, int depth, const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for(int child : children[node]) {
            if (child == parent)
            {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for(const auto& edge: edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        int res = dfs(0, -1, 0, children, color);
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);

        vector<int> res(edges1.size() + 1);
        for (int i = 0; i < n; i++)
        {
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[2,3],[2,4]]\n[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2],[0,3],[0,4]]\n[[0,1],[1,2],[2,3]]\n
// @lcpr case=end

 */


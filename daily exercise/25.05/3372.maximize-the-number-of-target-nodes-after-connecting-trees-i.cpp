/*
 * @lc app=leetcode.cn id=3372 lang=cpp
 * @lcpr version=30204
 *
 * [3372] 连接两棵树后最大目标节点数目 I
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
public:
    // I. DFS
    // 使用第一棵树的节点i去链接第二棵树的节点时
    // 第二棵树的节点与此节点i的距离会更小，所以目标结点会更多
    // 设第二棵树的节点为j, 所以我们首先需要统计第一棵树中和节点i距离<=k的数目count_1[i]
    // 然后第二棵树中和第一棵树节点i的距离 <= (k - 1)的节点数目count_2[j]

    // 注意到count_2[j]的计算与查询无关，所以我们DFS与计算第二棵树中与节点j的距离<= (k - 1)的节点数目 count_2[j]
    // 然后枚举节点j, 计算count_2[j]的最大值maxCount2
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0)
        {
            return 0;
        }
        int res = 1;
        for(int child: children[node]) {
            if (child == parent)
            {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for(const auto& edge: edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxCount2 = *max_element(count2.begin(), count2.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[2,3],[2,4]]\n[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2],[0,3],[0,4]]\n[[0,1],[1,2],[2,3]]\n1\n
// @lcpr case=end

 */


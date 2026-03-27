/*
 * @lc app=leetcode.cn id=3600 lang=cpp
 * @lcpr version=30204
 *
 * [3600] 升级后最大生成树稳定性
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

#include <numeric>
// @lcpr-template-end
// @lc code=start

struct Edge{
    int u, v, w, type;
};

class DSU {
    // 并查集
public:
    vector<int> parent;

    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return parent[x] == x ? x: (parent[x] = find(parent[x]));
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

const int MAX_STABILITY = 2e5;

class Solution {
    // I. 二分+Kruskal
    // Kruskal是构成最小生成树的按边贪心算法
    // 将每个边按照权重排序之后,在不形成环的情况下不断将边并入,
    // 直到所有节点都被包含在树中
    // 
    // 为了"最大化"生成树的边权"最小值",可以使用二分作为框架
    // 事先二分边权最小值作为约束,然后验证是否可以构建出满足约束的生成树
    // 首先不考虑k次翻倍的情况,那么我们直接用Kruskal贪心顺序取较大的边即可
    // 
    // 如果要考虑翻倍,首先注意到Kruskal贪心选取已然省下了翻倍机会
    // 此时如果遇到边权小于约束的边,那么我们只能尝试翻倍以继续构建
    // 如果翻倍后仍然小于最小值约束或者翻倍机会也用完,
    // 则所有余下的边都无法满足约束,构建失败
    // 
    // 所以预处理的时候,我们强制选择所有must=1的边,得到初始并查集
    // 并将此时的二分上界作为最小边权的约束,然后我们按照降序排列must=0的边
    // 之后我们执行kruskal算法按序选取,遇到突破约束的按照上文尝试翻倍即可
    // 
    // 注意:题目中三个性质实际上无环情况下,联通和恰好有n-1条边是等价条件
    // 我们用并查集保证无环,只需要判断选取边数是否恰好为n-1,即可判断是否是生成树

    // tc: O(mlogm + (n + m \alpha(n)) * logv), m = |edges|, v: 二分上界, \alpha:反阿克曼数
    // sc: O(n + m), 
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans = -1;

        if (edges.size() < n - 1) {
            return -1;
        }

        vector<Edge> sortedEdges;
        sortedEdges.reserve(edges.size());
        for (const auto&edge: edges) {
            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
        }

        vector<Edge> mustEdges;
        vector<Edge> optionalEdges;

        for (const auto&edge: sortedEdges) {
            if (edge.type == 1) {
                mustEdges.push_back(edge);
            } else {
                optionalEdges.push_back(edge);
            }
        }

        if (mustEdges.size() > n - 1) {
            return -1;
        }
        sort(optionalEdges.begin(), optionalEdges.end(), [](const Edge& a, const Edge& b) {
            return b.w < a.w;
        });

        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;
        vector<int> intialParent(n);
        iota(intialParent.begin(), intialParent.end(), 0);
        DSU dusInit(intialParent);

        for (const auto& edge: mustEdges) {
            // Kruskal算法
            if (dusInit.find(edge.u) == dusInit.find(edge.v)) {
                return -1;
            }

            dusInit.join(edge.u, edge.v);
            selectedInit++;
            mustMinStability = min(mustMinStability, edge.w);
        }

        int l = 0;
        int r = mustMinStability;

        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu(dusInit.parent);

            int selected = selectedInit;
            int doubleCount = 0;

            for (const auto& edge: optionalEdges) {
                if (dsu.find(edge.u) == dsu.find(edge.v)) {
                    continue;
                }

                if (edge.w >= mid) {
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else if (doubleCount < k && edge.w * 2 >= mid) {
                    doubleCount++;
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1,2,1],[1,2,3,0]]\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,4,0],[1,2,3,0],[0,2,1,0]]\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,1,1],[1,2,1,1],[2,0,1,1]]\n0\n
// @lcpr case=end

 */


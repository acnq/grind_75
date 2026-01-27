// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 * @lcpr version=30204
 *
 * [3650] 边反转的最小路径总成本
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
    // I. Dijkstra
    // 注意我们是每个节点都有翻转机会，而不是整个路径只有一次翻转机会
    // 而Dijkstra算法每个结点最多也只会被遍历一次，所以我们只需要先把翻转边准备好即可
    // 具体来说，我们将每条边[x, y, w]的反向边[y, x, 2w]加入图中，
    // 然后用Dijkstra算法求解0：n-1的最短路径，注意可以有最小堆优化
    // 每次从堆中回去当前未到达的的点集中距离最小的点，
    // tc: O(n + mlogm) (n: 点的数量，m: 边的数量)， sc: O(n + m)

public:
    using PII = pair<int, int>;
    int minCost(int n, vector<vector<int>>& edges)  {
        vector<vector<PII>> g(n);

        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }

        vector<int> d(n, INT_MAX);
        vector<bool> v(n, false);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        d[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return d[x];
            }
            // 第一次出堆松弛其他节点
            if (v[x]) {
                continue;
            }
            v[x] = 1;

            for (auto &[y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumAbsDifference
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 4\n[[0,1,3],[3,1,1],[2,3,4],[0,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,2,1],[2,1,1],[1,3,1],[2,3,3]]\n
// @lcpr case=end

 */


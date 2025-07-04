/*
 * @lc app=leetcode.cn id=815 lang=cpp
 * @lcpr version=30204
 *
 * [815] 公交路线
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
    // I. 优化建图+BFS
    // 把公交路线当作点，如果有相同车站，则这两条公交路线之间可视为有一条长度为1的边
    // 这样建出的图包含的点数量为公共路线的数量，记为n
    // 那么新图的起点和终点怎么确定呢？
    // 注意到原本的起/终点车站可能同时位于多条公交路线上，因此新图上得有多个起点和终点
    // 对此，初始时要有多个点同时入队，并在BFS侯检查各个终点的最短路径，取出最小值
    // 实现中，我们使用哈希表映射来实时维护“车站所属的公交路线列表”， 
    // 特别地，如果起点和重点相同，直接返回0
    // tc: O(mn + n^2), n: 路线数量，m:车站总数，sc: O(n^2 + m)
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
        {
            return 0;
        }
        
        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; i++)
        {
            for (int site: routes[i]) {
                for (int j : rec[site]) {
                    edge[i][j] = edge[j][i] = true;
                }
                rec[site].push_back(i);
            }
        }
        
        vector<int> dis(n, -1);
        queue<int> que;
        for (int bus: rec[source]) {
            dis[bus] = 1;
            que.push(bus);
        }
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            for (int y = 0; y < n; y++)
            {
                if (edge[x][y] && dis[y] == -1)
                {
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }
        
        int ret = INT_MAX;
        for (int bus: rec[target]) {
            if (dis[bus] != -1)
            {
                ret = min(ret, dis[bus]);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,7],[3,6,7]]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
// @lcpr case=end

 */


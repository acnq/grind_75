/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 * @lcpr version=30204
 *
 * [3341] 到达最后一个房间的最少时间 I
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
    // I. 最短路 + Dijkstra
    // 看做 n * m的无向图，(i, j) 连向(i - 1, j), (i + 1, j), (i, j-1), (i, j + 1)
    // 求解(0, 0)到(n - 1, m - 1)的最短路
    // 利用Dijkstra，参考T743
    
    // 和一般不一样的地方，
    // 设d[i][j]表示从(0, 0)到(i, j)所需最短时间
    // 那么从(i, j)走到相邻坐标(u, v)时间为
    // max(d[i][j], moveTime[u][v]) + 1, 其他和经典Dijkstra一致
public:
    struct State
    {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis): x(x), y(y), dis(dis) {};
        bool operator < (const State& rth) const {
            return dis > rth.dis;
        }
    };
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;
        priority_queue<State> q;
        q.push(State(0, 0, 0));

        while (q.size())
        {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y])
            {
                continue;
            }
            v[s.x][s.y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist)
                {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,4],[4,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2]]\n
// @lcpr case=end

 */


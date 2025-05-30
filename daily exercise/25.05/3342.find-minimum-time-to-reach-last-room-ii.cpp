/*
 * @lc app=leetcode.cn id=3342 lang=cpp
 * @lcpr version=30204
 *
 * [3342] 到达最后一个房间的最少时间 II
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
    // I. 仿照T3341
    // 发现每次移动时(i, j)只会变化1，所以(i + j)奇偶性必定变化
    // d[i][j]: (0, 0)->(i, j)所需最短时间
    // (i, j)->(u, v)的最短时间：max(d[i][j], moveTime[u][v]) + (i + j) mod 2 + 1
    // 细节：因为我们一定可以到达(n - 1, m - 1), 可以循环探索当前点是否为此终点
    // 若是则直接跳出
public:
    struct State
    {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator < (const State& rth) const {
            return dis > rth.dis;
        }
    };
    
    const int inf = 0x3f3f3f3f;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));  // d as shown in I.
        vector<vector<int>> v(n, vector<int>(m, 0));    // visited
        
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
            if (s.x == n - 1 && s.y == m - 1)
            {
                break; // reach dist
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
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;
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
// [[0,0,0,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2]]\n
// @lcpr case=end

 */


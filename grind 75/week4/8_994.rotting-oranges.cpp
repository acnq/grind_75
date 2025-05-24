/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30204
 *
 * [994] 腐烂的橘子
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
    int cnt;
    int dis[10][10]; // 1 <= m, n <= 10, 每个橘子腐烂最短的时间
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        // BFS:
        // 超级源点，将腐烂橘子都放进队列进行BFS即可
        // cnt 表示当前网络中的新鲜橘子数量，广搜发现橘子腐烂
        // 则cnt--; 最后搜索结束若有cnt >= 0, 则返回-1，
        // 否则返回广搜的次数，即是腐烂时间
        queue<pair<int, int>> q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                } else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = r + dir_x[i];
                int ty = c + dir_y[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m
                    || ~dis[tx][ty] || !grid[tx][ty])
                {
                    continue;
                }
                dis[tx][ty] = dis[r][c] + 1;
                q.emplace(tx, ty);
                if (grid[tx][ty] == 1)
                {
                    cnt--;
                    ans = dis[tx][ty];
                    if (!cnt)
                    {
                        break;
                    }
                }
            }
        }
        return cnt ? -1: ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */


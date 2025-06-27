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
    // 模拟广度优先搜索的
    // 上下左右相邻的新鲜橘子就是源腐烂橘子尝试访问的同层节点
    // 路径长度就是新鲜橘子被腐烂的时间。
    // 但是思考一下，我们会有好多源腐烂橘子，我们需要对每个腐烂橘子作BFS
    // 然后用dis[x][y][i]表示只考虑第i个腐烂橘子为起点DFS, 坐标(x, y)的新鲜橘子被腐烂的时间么？
    // 其实不需要，因为我们把所有的源腐烂橘子当做广度优先搜索的第一层
    // I. 多源BFS
    // 其实所有的源腐烂橘子，都可以看做是一个腐烂橘子（“超级源点”）造成的第一层腐烂橘子
    // 操作时，只需要把他们都放进队列进行BFS, 最后每个新鲜橘子被腐烂的最短时间为dis[x][y]
    // 当然为了确认是否所有新鲜橘子都被腐烂了，还需要一个变量cnt表示新鲜橘子总数，
    // 队列为空时，如果cnt > 0, 说明有橘子被隔离，返回-1，否则返回被腐烂的最大时间。
public:
    int cnt;
    int dis[10][10]; // 题目中grid的大小最大为10 * 10
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n = (int)grid.size(), m = (int)grid[0].size(), ans = 0;
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

                if (tx < 0 || tx >= n || ty < 0 || ty >= m || ~dis[tx][ty] || !grid[tx][ty])
                { // ~dis[tx][ty]表示dis[tx][ty]不是-1则直接continue，因为它已经被访问，（~按位取反）
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
        return cnt ? -1 : ans;
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


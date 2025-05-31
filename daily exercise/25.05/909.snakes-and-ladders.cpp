/*
 * @lc app=leetcode.cn id=909 lang=cpp
 * @lcpr version=30204
 *
 * [909] 蛇梯棋
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
    // I. BFS
    // 将棋盘转化为包含N^2个节点的有向图
    // 每个节点x, 若 x + i (1 <= i <= 6)上没有蛇梯，则链接有向边x->x+i
    // 否则记蛇梯的目的地为y, 连接x->y
    // 如此转化后，原问题=>从这张有向图上求出1->N^2的最短路径长
    // BFS即可，注意搜索状态不仅包含节点编号，也要记录到达该节点的移动次数
    // 用队列存储搜索状态，一开始(1, 0)入队（到达起点1移动0次）
    // 然后不断取出队首，扩展新状态
    // （即遍历该节点的出边，若出边对应的节点未被访问，则将该节点和当前移动次数+1作为新状态加入队列）
    // 循环直到队列为空或者到达终点
    // 设编号为id, 由于每行n个，所以其位于棋盘从下往上数第\floor{(id - 1) / n}行
    // 记作r, 由于转行交替性，r % 2 == 0 => 列号=(id - 1) mod n; r % 2 == 1 => 列号=n - 1 - ((id - 1) mod n)

public:
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1)
        {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> vis(n * n + 1);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++)
            {
                int nxt = p.first + i;
                if (nxt > n * n)
                {
                    break;
                }
                auto rc = id2rc(nxt, n); 
                if (board[rc.first][rc.second] > 0)
                { // 存在蛇梯
                    nxt = board[rc.first][rc.second];
                }
                if (nxt == n * n)
                { // 到达终点
                    return p.second + 1;
                }
                if (!vis[nxt])
                {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // 扩展新状态
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1,-1],[-1,3]]\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=542 lang=cpp
 * @lcpr version=30204
 *
 * [542] 01 矩阵
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
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // BFS:
        // 通过一个超级源点
        // int m = mat.size(), n = mat[0].size();
        // vector<vector<int>> dist(m, vector<int>(n)); // 缺省初始化为0
        // vector<vector<int>> seen(m, vector<int>(n)); // 缺省初始化为0
        // queue<pair<int, int>> q;
        // // 将所有0添加到初始队列中：
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (mat[i][j] == 0)
        //         {
        //             q.emplace(i, j);
        //             seen[i][j] = 1;
        //         }
        //     }
        // }

        // // 广优
        // while (!q.empty())
        // {
        //     auto [i, j] = q.front();
        //     q.pop();
        //     for (int d = 0; d < 4; d++)
        //     {
        //         int ni = i + dirs[d][0];
        //         int nj = j + dirs[d][1];
        //         if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj])
        //         {
        //             dist[ni][nj] = dist[i][j] + 1;
        //             q.emplace(ni, nj);
        //             seen[ni][nj] = 1;
        //         }
        //     }
        // }
        
        // return dist;

        // dp;
        // f(i, j): (i, j) 到0的最近距离
        // 最近距离只有四种走法
        // 1. （只）向左+向上；
        // 2. (只)向左 + 向下；
        // 3. （只）向右+向上；
        // 4. （只）向右+向下；
        // 在2的情况下，有
        // f(i, j) = {1 + min(f(i-1, j), f(i, j - 1)), a(i, j) = 1
        //           {0                                a(i, j) = 0
        // 其他类似
        int m = mat.size(), n = mat[0].size();
        // 初始化动态规划数组
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        // mat(i, j) = 0 => dist(i, j) = 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                }
            }
        }
        
        // 向左+向上；注意计算顺序
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);

                }
                if (j - 1 >= 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // 向左+向下；注意计算顺序
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + 1 < m)
                {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j - 1 >= 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // 向右+向上；注意计算顺序
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i - 1 >= 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j + 1 < n)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        

        // 向右+向下；注意计算顺序
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i + 1 < m)
                {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;

        // 可以把左下和右上的部分去掉，理由如下：
        // 假设距离（i,j)最近的点在(i-a, j+b);
        // 则距离(i, j + b)最近的点也在(i-a, j+b);
        // 第一个dp时，(i, j)没有取得最优值，
        // 但第二个dp时，由于(i, j+b)已经取得最优值，
        // 所以(i, j)也能取得最优值
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,0],[1,1,1]]\n
// @lcpr case=end

 */


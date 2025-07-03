/*
 * @lc app=leetcode.cn id=329 lang=cpp
 * @lcpr version=30204
 *
 * [329] 矩阵中的最长递增路径
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
    // I. 记忆化深搜
    // 矩阵看做有向图：单元格->节点；若两个单元格值不等，则从较小节点有指向较大节点的有向边，
    // 问题转化为求此图的最长路径
    // 朴素的深搜会TLE, 原因是可能重复访问单元格。由于同一单元格对应的最长递增路径不变，
    // 所以我们采用记忆化搜索，memo作为缓存矩阵，如果访问到单元格(i, j),而memo[i][j] != 0
    // 说明该单元格已经计算过，直接从缓存中读取即可，memo[i][j] = 0才需要搜索，且结果记得存入缓存。
    // 遍历完单元格之后即可得到最长递增路径。
    // tc/sc: O(mn)
    
    // II. 拓扑排序
    // 可以用动态规划建模memo[i][j] = max{memo[x][y]} + 1 (x, y)与(i, j)相邻，且matrix[x][y] > matrix[i][j]
    // 同样将矩阵看做有向图，可以直接从所有出度为0的点开始BFS, 然后更新剩余单元格初度，
    // 将出度变为0的元素再加入下一层搜索，当搜索结束时，总层数即为答案（相当于我们把最高点作为边界条件）
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;

    // I.
    // int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
    //     if (memo[row][col] != 0)
    //     {
    //         return memo[row][col];
    //     }
    //     memo[row][col]++;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int newRow = row + dirs[i][0];
    //         int newCol = col + dirs[i][1];
    //         if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col])
    //         {
    //             memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
    //         }
    //     }
    //     return memo[row][col];
    // }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // I.
        // if (matrix.size() == 0 || matrix[0].size() == 0)
        // {
        //     return 0;
        // }
        // rows = matrix.size();
        // cols = matrix[0].size();
        // auto memo = vector<vector<int>> (rows, vector<int>(cols));
        // int ans = 0;
        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < cols; j++)
        //     {
        //         ans = max(ans, dfs(matrix, i, j, memo));
        //     }
        // }
        // return ans;   

        // II.
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        rows = matrix.size();
        cols = matrix[0].size();
        auto outdegrees = vector<vector<int>> (rows, vector<int>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int newRow = i + dirs[k][0];
                    int newCol = j + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[i][j])
                    {
                        outdegrees[i][j]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (outdegrees[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto cell = q.front();
                q.pop();

                int row = cell.first, col = cell.second;
                for (int k = 0; k < 4; k++)
                {
                    int newRow = row + dirs[k][0];
                    int newCol = col + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] < matrix[row][col])
                    {
                        outdegrees[newRow][newCol]--;
                        if (outdegrees[newRow][newCol] == 0)
                        {
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[9,9,4],[6,6,8],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,5],[3,2,6],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */


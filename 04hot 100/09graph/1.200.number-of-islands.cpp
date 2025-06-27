/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] 岛屿数量
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

// III.
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    parent.push_back(i * n + j);
                    count++;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }
    int find(int i) {
        if (parent[i] != i)
        {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
            {
                rank[rootx] += 1;
            }
            count--;
        }
    }

    int getCount() const {
        return count;
    }
};


class Solution {
    // I. DFS
    // 扫描整个网格，如果位置为1，则开始进行DFS, 碰到1标记为0

    // II. BFS
    // 遇到位置为1的，将其加入队列，然后每个被搜到的都标记为0，直到队列为空。

    // III. 并查集
    // 找出相邻的方向上为1的元素并且在并查集中进行合并。
public:
    // I.
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
            dfs(grid, r - 1, c);
        }
        if (r + 1 < nr && grid[r + 1][c] == '1')
        {
            dfs(grid, r + 1, c);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
        {
            dfs(grid, r, c - 1);
        }
        if (c + 1 < nc && grid[r][c + 1] == '1')
        {
            dfs(grid, r, c + 1);
        }
    }

    
    int numIslands(vector<vector<char>>& grid) {
        // I.
        // int nr = grid.size();
        // if (!nr) {
        //     return 0;
        // }
        // int nc = grid[0].size();

        // int nums_is = 0;
        // for (int r = 0; r < nr; r++)
        // {
        //     for (int c = 0; c < nc; c++)
        //     {
        //         if (grid[r][c] == '1')
        //         {
        //             nums_is++;
        //             dfs(grid, r, c);
        //         }
        //     }
        // }
        // return nums_is;

        // II.
        // int nr = grid.size();
        // if (!nr)
        // {
        //     return 0;
        // }
        // int nc = grid[0].size();

        // int num_is = 0;
        // for (int r = 0; r < nr; r++)
        // {
        //     for (int c = 0; c < nc; c++)
        //     {
        //         if (grid[r][c] == '1')
        //         {
        //             num_is++;
        //             grid[r][c] = '0';
        //             queue<pair<int, int>> neighbours; 
        //             neighbours.push({r, c});
        //             while (!neighbours.empty())
        //             {
        //                 auto rc = neighbours.front();
        //                 neighbours.pop();
        //                 int row = rc.first, col = rc.second;
        //                 if (row - 1 >= 0 && grid[row - 1][col] == '1')
        //                 {
        //                     neighbours.push({row - 1, col});
        //                     grid[row - 1][col] = '0';
        //                 }
        //                 if (row + 1 < nr && grid[row + 1][col] == '1')
        //                 {
        //                     neighbours.push({row + 1, col});
        //                     grid[row + 1][col] = '0';
        //                 }
        //                 if (col - 1 >= 0 && grid[row][col - 1] == '1')
        //                 {
        //                     neighbours.push({row, col - 1});
        //                     grid[row][col - 1] = '0';
        //                 }
        //                 if (col + 1 < nc && grid[row][col + 1] == '1')
        //                 {
        //                     neighbours.push({row, col + 1});
        //                     grid[row][col + 1] = '0';
        //                 }
        //             }
        //         }
        //     }
        // }
        // return num_is;       
        
        int nr = grid.size();
        if (!nr)
        {
            return 0;
        }
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_is = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1')
                    {
                        uf.unite(r * nc + c, (r - 1) * nc + c);
                    }
                    if (r + 1 < nr && grid[r + 1][c] == '1')
                    {
                        uf.unite(r * nc + c, (r + 1) * nc + c);
                    }
                    if (c - 1 >= 0 && grid[r][c - 1] == '1')
                    {
                        uf.unite(r * nc + c, r * nc + c - 1);
                    }
                    if (c + 1 < nc && grid[r][c + 1] == '1')
                    {
                        uf.unite(r * nc + c, r * nc + c + 1);
                    }
                }
            }
        }
        return uf.getCount();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */


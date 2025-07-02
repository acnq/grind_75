/*
 * @lc app=leetcode.cn id=417 lang=cpp
 * @lcpr version=30204
 *
 * [417] 太平洋大西洋水流问题
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


static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
    // I. DFS
    // 从某个单元格开始，搜索方法模拟雨水流动，
    // 这样好像会重复遍历每个单元格，导致时间复杂度过高，
    // 我们不如从矩阵的边界开始反向搜索雨水流向边界的单元格
    // 反向搜索，只能移动到高度相同或更大的单元格
    // 因为矩阵左边界和上边界是太平洋，矩阵的右边界和下边界是大西洋
    // 所以矩阵的左上开始反向搜索可以找到雨水流向太平洋的单元格，右下反向可找到流向大西洋的单元格
    // 这样记录每个单元格能否反向到达，搜索结束后，遍历每个网格，如果发现能到达两边，则加入答案
    // tc/sc: O(mn), 

    // II. BFS
    // 同样反向搜索
    // tc/sc: O(mn)
public:
    vector<vector<int>> heights;
        
    // I.
    void dfs(int row, int col, vector<vector<bool>>& ocean) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col])
        {
            return; // 已经访问过了
        }
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col])
            {
                dfs(newRow, newCol, ocean);
            }
        }
    }
    // II.
    void bfs(int row, int col, vector<vector<bool>>& ocean) {
        if (ocean[row][col])
        {
            return;
        }
        int m = heights.size();
        int n = heights[0].size();
        ocean[row][col] = true;
        queue<pair<int, int>> qu;
        qu.emplace(row, col);
        while (!qu.empty())
        {
            auto [row, col] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol])
                {
                    ocean[newRow][newCol] = true;
                    qu.emplace(newRow, newCol);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // I.
        // this->heights = heights;
        // int m = heights.size();
        // int n = heights[0].size();
        // vector<vector<bool>> pacific(m, vector<bool>(n, false));
        // vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // for (int i = 0; i < m; i++)
        // {
        //     dfs(i, 0, pacific);
        // }
        // for (int j = 1; j < n; j++)
        // {
        //     dfs(0, j, pacific);
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     dfs(i, n - 1, atlantic);
        // }
        // for (int j = 0; j < n - 1; j++)
        // {
        //     dfs(m - 1, j, atlantic);
        // }
        
        // vector<vector<int>> res;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (pacific[i][j] && atlantic[i][j])
        //         {
        //             vector<int> cell;
        //             cell.emplace_back(i);
        //             cell.emplace_back(j);
        //             res.emplace_back(cell);
        //         }
        //     }
        // }
        // return res;

        // II.
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            bfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++)
        {
            bfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++)
        {
            bfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++)
        {
            bfs(m - 1, j, atlantic);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    res.emplace_back(cell);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1],[1,2]]\n
// @lcpr case=end

 */


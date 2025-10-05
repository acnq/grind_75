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
// I. & II.
static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
    // I. DFS
    // 我们直接从每个单元格开始通过搜索的方式模拟雨水的流动来判断
    // 但是如果真的穷举“每个”单元格，显然会有重复，
    // 我们从矩形的边界开始反向搜索，寻找雨水可以流向边界的单元格
    // 从左上开始搜索流向太平洋的单元格，右下开始搜索流向大西洋的单元格
    // DFS记录每个单元格是否可以从太平洋反向到达以及是否可以从大西洋反向到达
    // 结束后，遍历网格找到同时满足的即可。
    // tc = sc = O(mn), dfs最多遍历每个单元格两次

    // II. BFS
    // 同理反向搜索即可
    // tc = sc = O(mn)
public:
    // I & II
    vector<vector<int>> heights;

    // I.
    void dfs(int row, int col, vector<vector<bool>>& ocean) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col]) { // 访问过了
            return;
        }
        ocean[row][col] = true; // 这个位置能流入相应的海洋
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                && heights[newRow][newCol] >= heights[row][col]) {
                    dfs(newRow, newCol, ocean);
            }
        }
    }

    // II.
    void bfs(int row, int col, vector<vector<bool>>& ocean) {
        if (ocean[row][col]) {
            return;
        }
        int m = heights.size();
        int n = heights[0].size();
        ocean[row][col] = true;
        queue<pair<int, int>> qu;
        qu.emplace(row, col);
        while (!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol]) {
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

        // for (int i = 0; i < m; i++) {
        //     dfs(i, 0, pacific);
        // }
        // for (int j = 1; j < n; j++) {
        //     dfs(0, j, pacific);
        // }
        // for (int i = 0; i < m; i++) {
        //     dfs(i, n - 1, atlantic);
        // }
        // for (int j = 0; j < n - 1; j++) {
        //     dfs(m - 1, j, atlantic);
        // }
        // vector<vector<int>> result;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (pacific[i][j] && atlantic[i][j]) {
        //             vector<int> cell;
        //             cell.emplace_back(i);
        //             cell.emplace_back(j);
        //             result.emplace_back(cell);
        //         }
        //     }
        // }
        // return result;

        // II.
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));


        for (int i = 0; i < m; i++) {
            bfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++) {
            bfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            bfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            bfs(m - 1, j , atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
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


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=733 lang=cpp
 * @lcpr version=30204
 *
 * [733] 图像渲染
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
    // used only in DFS
    void dfs(vector<vector<int>>& image, int x, int y, int org_color, int color) {
        int N = image.size();
        int M = image[0].size();
        image[x][y] = color;
        
        if (x + 1 < N && image[x + 1][y] == org_color)
        {
            dfs(image, x + 1, y, org_color, color);
        }
        if (x - 1 >= 0 && image[x - 1][y] == org_color)
        {
            dfs(image, x - 1, y, org_color, color);
        }
        if (y + 1 < M && image[x][y + 1] == org_color)
        {
            dfs(image, x, y + 1, org_color, color);
        }
        if (y - 1 >= 0 && image[x][y - 1] == org_color)
        {
            dfs(image, x, y - 1, org_color, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // BFS
        // if (image.size() == 0 || image[0].size() == 0 || image[sr][sc] == color)
        // {
        //     return image;
        // } else {
        //     int N = image.size();
        //     int M = image[0].size();
        //     int org_color = image[sr][sc];
        //     queue<pair<int, int>> q; // q[i][j] 表示需要染色的格子；
        //     q.emplace(sr, sc);
        //     while (!q.empty())
        //     {
        //         int x = q.front().first, y = q.front().second;
        //         image[x][y] = color;
        //         q.pop();
        //         if (x + 1 < N && image[x + 1][y] == org_color)
        //         {
        //             q.emplace(x + 1, y);
        //         }
        //         if (x - 1 >= 0 && image[x - 1][y] == org_color)
        //         {
        //             q.emplace(x - 1, y);
        //         }
        //         if (y + 1 < M && image[x][y + 1] == org_color)
        //         {
        //             q.emplace(x, y + 1);
        //         }
        //         if (y - 1 >= 0 && image[x][y - 1] == org_color)
        //         {
        //             q.emplace(x, y - 1);
        //         }
        //     }
        //     return image;
        // }

        if (image.size() == 0 || image[0].size() == 0 || image[sr][sc] == color)
        {
            return image;
        } else {
            int N = image.size();
            int M = image[0].size();
            int org_color = image[sr][sc];
            dfs(image, sr, sc, org_color, color);
            return image;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,1,0],[1,0\n1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n0\n0\n0\n
// @lcpr case=end

 */


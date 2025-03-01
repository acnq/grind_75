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
    const vector<int> dx = {0, 1, -1, 0};
    const vector<int> dy = {1, 0, 0, -1};

    void dfs(vector<vector<int>>& image, int x, int y, int org_color, int color) {
        if (image[x][y] == org_color)
        {
            image[x][y] = color;
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size())
                {
                    dfs(image, mx, my, org_color, color);
                }
                
            }
            
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int org_col = image[sr][sc];
        // if (color == org_col)
        // {
        //     return image;
        // }

        // int n = image.size();
        // int m = image[0].size();
        // queue<pair<int, int>> que;
        // que.emplace(sr, sc);
        // image[sr][sc] = color;
        // while (!que.empty())
        // {
        //     int x = que.front().first, y = que.front().second;
        //     que.pop();
        //     for (int i = 0; i < 4; i++)
        //     {
        //         int mx = x + dx[i];
        //         int my = y + dy[i];
        //         if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == org_col)
        //         {
        //             que.emplace(mx, my);
        //             image[mx][my] = color;
        //         }
        //     }
        // }
        // return image;

        int org_color = image[sr][sc];
        if (org_color != color)
        {
            dfs(image, sr, sc, org_color, color);
        }
        return image;
        
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


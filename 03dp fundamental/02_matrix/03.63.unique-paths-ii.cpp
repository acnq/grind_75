/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
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
    // dp[i][j] = {0: grid[i][j] = 1 (有障碍物的格子一定没法到达)
    //            {dp[i][j - 1] + dp[i - 1][j]: grid[i][j] = 0
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // bool blocked = false;
        // for(int i = 0; i < m; i++) {
        //     if(obstacleGrid[i][0] == 0 && !blocked) {
        //         dp[i][0] = 1; 
        //     } else {
        //         dp[i][0] = 0;
        //         blocked = true;
        //     }
        // }
        // blocked = false;
        // for (int j = 0; j < n; j++)
        // {
        //     if (obstacleGrid[0][j] == 0 && !blocked)
        //     {
        //         dp[0][j] = 1;
        //     } else {
        //         dp[0][j] = 0;
        //         blocked = true;
        //     }
        // }
        

        // for(int i = 1; i < m; i++) {
        //     for(int j = 1; j < n; j++) {
        //         if(obstacleGrid[i][j] == 0) {
        //             dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        //         } else {
        //             dp[i][j] = 0;
        //         }
        //     }
        // }

        // return dp[m - 1][n - 1];
        //  官方题解：滚动数组优化
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */


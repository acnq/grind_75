/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=30204
 *
 * [931] 下降路径最小和
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
    // dp[i][j] = mat[i][j] + { min(dp[i - 1][j], dp[i - 1][j + 1]), j == 0
    //                        { min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]), else
    //                        { min(dp[i - 1][j - 1], dp[i - 1][j]), j == n - 1;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = matrix[i][j];
                if (j == 0)
                {
                    dp[i][j] = tmp + min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == n - 1)
                {
                    dp[i][j] = tmp + min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = tmp + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                }
            }
        }
        
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */


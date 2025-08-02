// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 杨辉三角
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
    // 做过了，我们这里直接用DP来做，不思考数学方案了
    // dp[i][0] = dp[i][i] = 1; i = 0, 1, 2, ......,
    // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        // vector<vector<int>> ans;
        // dp[0][0] = 1;
        // for(int i = 0; i < numRows; i++) {
        //     dp[i][0] = 1;
        //     dp[i][i] = 1;
        //     for(int j = 1; j < i; j++) { // i不是i-1
        //         dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        //     }
        //     vector<int> tmp(dp[i].begin(), dp[i].begin() + i + 1);
        //     ans.push_back(tmp);
        // }
        // return ans;

        // II. 官方写法（比我写的优雅）
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; i++) {
            ret[i].resize(i + 1); // 注意resize的妙用
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30204
 *
 * [62] 不同路径
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
    // f[m][n] = f[m - 1][n] + f[m][n - 1]
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        if (m <= 1 || n <= 1)
        {
            return 1;
        } else {
            for (int i = 0; i <= m; i++)
            {
                f[i][1] = 1;
            }
            for (int j = 0; j <= n; j++)
            {
                f[1][j] = 1;
            }
            
            
            for (int i = 2; i <= m; i++)
            {
                for (int j = 2; j <= n; j++)
                {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
            return f[m][n];
        }

        // 这样写好一点：
        // for (int i = 0; i < m; ++i) {
        //     f[i][0] = 1;
        // }
        // for (int j = 0; j < n; ++j) {
        //     f[0][j] = 1;
        // }
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         f[i][j] = f[i - 1][j] + f[i][j - 1];
        //     }
        // }
        // return f[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2906 lang=cpp
 * @lcpr version=30204
 *
 * [2906] 构造乘积矩阵
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
    // I. 后缀乘积
    // 参考T238
    // 计算每个元素p[i][j]的过程如下:
    // 1. 计算当前元素之后的后缀积, grid[i][j]到grid[n - 1][m - 1]的乘积
    //    记作suffix[i][j], 可以边倒序边遍历计算
    // 2. 计算当前元素之前的前缀积, grid[0][0]到grid[i][j]上个元素的乘积
    //    记作prefix[i][j], 可以顺序计算
    // p[i][j] = prefix[i][j] * suffix[i][j]
    // 为了节省空间,先在倒序计算后缀时初始化p[i][j] = suffix[i][j]
    // 顺序计算前缀积时,不必开拓新空间, 直接将当前前缀积保存在变量
    // prefix中,然后直接乘p[i][j]得答案
    // 
    // tc: O(nm), sc: O(1) [除了返回的p之外无需额外空间]
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));

        // 倒序计算后缀积
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        }

        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = p[i][j] * prefix % MOD;
                prefix = prefix * grid[i][j] % MOD;
            }
        }

        return p;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[12345],[2],[1]]\n
// @lcpr case=end

 */


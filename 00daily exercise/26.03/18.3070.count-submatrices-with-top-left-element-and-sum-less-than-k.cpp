/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 * @lcpr version=30204
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
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
    // I. 二维前缀和
    // 按行优先遍历,到(i, j)时,将其作为子矩阵的右下角
    // 维护cols[j], 记录当前行之前第j列所有元素和.
    // 遍历第i行时, 从左到右遍历j, grid[i][j]累加到cols[j], 
    // 再将cols[j]累加,若和<=k, 则答案+1;
    //
    // 
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cols(m);

        int res = 0;
        for (int i = 0; i < n; i++) {
            int rows = 0;
            for (int j = 0; j < m; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,6,3],[6,6,1]]\n18\n
// @lcpr case=end

// @lcpr case=start
// [[7,2,9],[1,5,0],[2,6,6]]\n20\n
// @lcpr case=end

 */


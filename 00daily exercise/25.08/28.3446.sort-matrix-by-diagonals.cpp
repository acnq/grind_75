/*
 * @lc app=leetcode.cn id=3446 lang=cpp
 * @lcpr version=30204
 *
 * [3446] 按对角线进行矩阵排序
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
    // I. 模拟
    // 左下角三角形每一条元素是grid[i + j][j]
    // 右上角三角形每一条元素是grid[i][j + i]
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; i + j < n; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }

        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }
        return grid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,7,3],[9,8,2],[4,5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */


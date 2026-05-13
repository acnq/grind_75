/*
 * @lc app=leetcode.cn id=1914 lang=cpp
 * @lcpr version=30204
 *
 * [1914] 循环轮转矩阵
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
    // I. 枚举各层
    // 对于每个m * n的矩阵grid, 层数为min(m / 2, n / 2), 
    // 从外向内枚举每一层并且模拟循环轮转
    // 从左上角起按逆时针遍历每层，分为四个部分
    // 将元素行、列、数值保存在对应的数组r,c,val中，并计算总数total
    // 实际循环轮转操作数量为kk = k % total
    // 第i个位置在轮转操作后存放的值对应val中下标为(i - kk + total) % total
    //  tc: O(mn), sc: O(m + n)
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int nlayers = min(m / 2, n / 2); // 层数
        // 左上角起逆时针枚举
        for (int layer = 0; layer < nlayers; layer++) {
            vector<int> r, c, val; // 读取行列下标和值
            for (int i = layer; i < m - layer - 1; i++) {
                // 左
                r.push_back(i);
                c.push_back(layer);
                val.push_back(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; j++) {
                // 下
                r.push_back(m - layer - 1);
                c.push_back(j);
                val.push_back(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; i--) {
                // 右
                r.push_back(i);
                c.push_back(n - layer - 1);
                val.push_back(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; j--) {
                // 上
                r.push_back(layer);
                c.push_back(j);
                val.push_back(grid[layer][j]);
            }

            int total = val.size(); // 单层总数
            int kk = k % total;
            // 找到每个下标对应的轮转后的取值
            for (int i = 0; i < total; i++) {
                int idx = (i + total - kk) % total;  // 轮转后对应的下标
                grid[r[i]][c[i]] = val[idx];
            }
        }

        return grid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[40,10],[30,20]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n2\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2711 lang=cpp
 * @lcpr version=30204
 *
 * [2711] 对角线上不同值的数量差
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

#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 模拟

    // II. 前缀和：
    // 向右下方向出发，用集合记录不同元素，
    // 这样就可以得到这些单元格，左上角对角线上不同值数量。
    // 同理我们可以从最后一行和最后一列出发，向左上方向出发，
    // 用集合记录不同元素，这样就可以得到这些单元格，右下角对角线上不同值数量。

    // 最后我们对每个单元格求差值的绝对值，就得到最后的答案。
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        // I. 模拟：
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set<int> s1;
                int x = i + 1, y = j + 1;
                while (x < m && y < n)
                {
                    s1.insert(grid[x][y]);
                    x ++;
                    y ++;
                }
                set<int> s2;
                x = i - 1, y = j - 1;
                while (x >= 0 && y >= 0)
                {
                    s2.insert(grid[x][y]);
                    x--;
                    y--;
                }
                res[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        return res;

        // II. 前缀和
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> res(m, vector<int>(n, 0));

        // // res 左下部分
        // for (int i = 0; i < m; i++)
        // {
        //     int x = i, y = 0;
        //     set<int> s;
        //     while (x < m & y < n)
        //     {
        //         res[x][y] += s.size();
        //         s.insert(grid[x][y]);
        //         x += 1;
        //         y += 1;
        //     }
            
        // }
        // // res 右上部分
        // for (int j = 0; j < n; j++)
        // {
        //     int x = 0, y = j;
        //     set<int> s;
        //     while (x < m && y < n)
        //     {
        //         res[x][y] += s.size();
        //         s.insert(grid[x][y]);
        //         x += 1;
        //         y += 1;
        //     }
        // }

        // // res 右上部分
        // for (int i = 0; i < m; i++)
        // {
        //     int x = i, y = n - 1;
        //     set<int> s;
        //     while (x >= 0 && y >= 0)
        //     {
        //         res[x][y] -= s.size();
        //         res[x][y] = abs(res[x][y]);
        //         s.insert(grid[x][y]);
        //         x --;
        //         y --;
        //     }
        // }
        
        // // res 左下部分
        // for (int j = n - 2; j >= 0; j--)
        // {
        //     int x = m - 1, y = j;
        //     set<int> s;
        //     while (x >= 0 && y >= 0)
        //     {
        //         res[x][y] -= s.size();
        //         res[x][y] = abs(res[x][y]);
        //         s.insert(grid[x][y]);
        //         x--;
        //         y--;
        //     }
        // }
        
        // return res;

        // 前两个循环看到右下有一样的就加
        // 后两个循环看到左上有一样的就减
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=differenceOfDistinctValues
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,2,3],[3,1,5],[3,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */


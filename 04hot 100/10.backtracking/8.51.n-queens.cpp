/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    // 基本思想是基于回溯，而且可以看到，同行同列不可能有皇后，因此遍历的tc不超过O(N!)
    // I.基于集合回溯
    // 枚举行，同时辅助三个集合col, dia1, dia2分别记录每列和两个方向的对角线上是否有皇后
    // dia1表示正对角线，其特征为行列下标之差相等，dia2表示反对角线，特征为行列下标和相等
    // 分别用这个和或者差来表征皇后所在的正反对角线即可
    // tc: O(N!), sc: O(N)

    // II. 基于位运算回溯
    // 我们只用三个整数cols, dias1,dias2分别记录，每个整数N个二进制位
    // 对应一列，最左最低 
    // 开始三个数设定为0，表示无任何皇后
    // 放置皇后，如果在第i列，将三个整数的第i个二进制位设为1
    // 下一行时，cols不变，dias1左移一位，dias2右移一位
    // 每次皇后防止，三个整数按位或运算的结果即为不能放置的位置，
    // 通过(2^n - 1) & (~(cols | dias1 | dias2))得到可以放置的位置（为1可放）
    // 遍历尝试，我们还有以下技巧
    // 1. x & (-x): 获取x中最低位的1
    // 2. x & (x - 1)将x最低位的1变成0
public:
    
    vector<string> generateBoard(vector<int>& queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++)
        {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
    // I.
    void backtrack(vector<vector<string>>& sols, vector<int>& queens, int n, int row, unordered_set<int>& cols, unordered_set<int>& dias1, unordered_set<int>& dias2) {
        if (row == n)
        {
            vector<string> board = generateBoard(queens, n);
            sols.push_back(board);
        } else {
            for (int i = 0; i < n; i++)
            {
                if (cols.find(i) != cols.end())
                {
                    continue;
                }
                int dia1 = row - i;
                if (dias1.find(dia1) != dias1.end())
                {
                    continue;
                }
                int dia2 = row + i;
                if (dias2.find(dia2) != dias2.end())
                {
                    continue;
                }
                queens[row] = i;
                cols.insert(i);
                dias1.insert(dia1);
                dias2.insert(dia2);
                backtrack(sols, queens, n, row + 1, cols, dias1, dias2);
                // 恢复现场
                queens[row] = -1;
                cols.erase(i);
                dias1.erase(dia1);
                dias2.erase(dia2);
            }
        }
    }

    // II.
    void solve(vector<vector<string>>& sols, vector<int>& queens, int n, int row, int cols, int dias1, int dias2) {
        if (row == n)
        {
            auto board = generateBoard(queens, n);
            sols.push_back(board);
        } else
        {
            int availPos = ((1 << n) - 1) & (~ (cols | dias1 | dias2));
            while (availPos != 0)
            {
                int pos = availPos & (- availPos);
                availPos = availPos & (availPos - 1);
                int col = __builtin_ctz(pos);
                queens[row] = col;
                solve(sols, queens, n, row + 1, cols | pos, (dias1 | pos) >> 1, (dias2 | pos) << 1);
                queens[row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // I.
        // auto sols = vector<vector<string>>();
        // auto queens = vector<int>(n, -1);
        // auto cols = unordered_set<int>(); // 有queen的列
        // auto dias1 = unordered_set<int>(); // 正对角线
        // auto dias2 = unordered_set<int>(); // 反对角线
        // backtrack(sols, queens, n, 0, cols, dias1, dias2);  
        // return sols;
        
        // II.
        auto sols = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(sols, queens, n, 0, 0, 0, 0);
        return sols;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


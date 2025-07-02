/*
 * @lc app=leetcode.cn id=36 lang=cpp
 * @lcpr version=30204
 *
 * [36] 有效的数独
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
    // I. 一次遍历
    // 用哈希表记录每一行，每一列，每一个九宫格中每个数字出现的次数即可
    // (i, j)所在的九宫格的行数和列数分别为\floor{i/3}和\floor{j/3}
    // 由于数独中的数字范围是1-9，可以直接用数组代替哈希表计数
    // 二维数组rows, cols分别记录数独中每行每列中每个数字出现的次数，
    // 三维数组subbox记录每个九宫格每个数字出现次数
    // rows[i][idx], cols[j][idx], subbox[\floor{i/3}][\floor{j/3}][idx]
    // 分别表示(i,j)所在和行、列、九宫格中，数字idx + 1出现的次数
    // 如果board[i][j]填入数字n, rows[i][n - 1], cols[j][n - 1], subbox[\floor{i/3}][\floor{j/3}][n-1]各+1
    // 如果更新后有计数>1, 则返回false; 如果没有计数>1, 则返回true. 
    // sc/tc: O(81) = O(1)
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int subbox[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(subbox, 0, sizeof(subbox));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int idx =  c - '0' - 1;
                    rows[i][idx]++;
                    cols[j][idx]++;
                    subbox[i / 3][j / 3][idx]++;
                    if (rows[i][idx] > 1 || cols[j][idx] > 1 || subbox[i / 3][j / 3][idx] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */


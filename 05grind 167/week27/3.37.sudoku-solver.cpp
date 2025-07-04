/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30204
 *
 * [37] 解数独
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
    // 行优先：顺序依次枚举空白格中的数字，递归+回溯美剧所有可能填法
    // 递归到最后一个空白格仍然没有冲突，则说明找到了答案，如果递归过程中，当前格无法填数字，则回溯
    // 下面三种方法都是基于递归+回溯，渐进复杂度为O(9 ^{9 * 9})
    // I. 回溯
    // 用bool数组表示值是否出现过
    // 算法：
    // 遍历到i行j列的位置
    //  1. 如果该位置是个空白格，将其加入一个用来存储空白格位置的列表中
    //  2. 如果该位置是个数字x, rows[i][x-1], cols[j][x-1]以及block[\floor{i/3}][\floor{j/3}][x-1]置True
    // 结束了遍历过程后，就可以递归枚举。当递归到(i, j)，枚举填入的数字x
    // 因为不能行列单元格重复，所以rows[i][x-1], cols[j][x-1], block[\floor{i/3}][\floor{j/3}][x-1]必须false
    // 填入了数字x之后，三个值置位True, 继续下一个空白格递归，回溯恢复现场时还要重置为False。

    // II. 位运算优化
    // 不再使用bool数组，直接用数字表示，数b的二进制表示第i位（从低到高，最低位为0)为1, 表示数字i+1已经出现过
    // 1. 坐标(i, j) rows[i] | cols[j] | block[\floor{i/3}][\floor{j/3}]中第k位为1，表示该位置不能填入数字k + 1
    //  | 表示按位或，如果我们对这个值按位取反（~), 那么第k位为1表示该位置可以填入数字k + 1, 通过寻找1来进行枚举
    // 注意取反，这个数的高位也变为1，所以要和(111111111)_2 = (1FF)_{16}按位于运算，将无关位置置位0
    // 2. 使用按位异或运算，将第i位从0变为1，或1变为0，具体，与数1 << i按位异或，<< 左移
    // 3. b & (-b)得到b二进制位中最低位1，（因为 -b = ~b + 1)
    // 4. 得到最低位1时，通过一语言自带函数得到最低位1究竟是第几位
    // 5. b和最低位1按位异或，就可以将其从b中去除，这样就可以枚举下一个1，

    // III. 枚举优化
    // 在II的基础上，如果一个白格只有唯一的数可以填入，也就是b和b-1进行按位与运算得到0
    // i.e. b中只有一个二进制位为1，此时，我们可以确定这个空白格填入的数，而不用得到递归时处理它

private:
    // I.
    // bool rows[9][9];
    // bool cols[9][9];
    // bool block[3][3][9];
    //  bool valid;
    // vector<pair<int, int>> spaces;
    // II、III.
    int rows[9];
    int cols[9];
    int block[3][3];
    bool valid;
    vector<pair<int, int>> spaces;

public:

    // I.
    // void dfs(vector<vector<char>>& board, int pos) {
    //     if (pos == spaces.size())
    //     {
    //         valid = true;
    //         return;
    //     }
    //     auto [i, j] = spaces[pos];
    //     for (int digit = 0; digit < 9 && !valid; digit++)
    //     {
    //         if (!rows[i][digit] && !cols[j][digit] && !block[i / 3][j / 3][digit])
    //         {
    //             rows[i][digit] = cols[j][digit] = block[i / 3][j / 3][digit] = true;
    //             board[i][j] = digit + '0' + 1;
    //             dfs(board, pos + 1);
    //             rows[i][digit] = cols[j][digit] = block[i / 3][j / 3][digit] = false;
    //         }
    //     }
    // }

    // II. III
    void flip(int i, int j, int digit) {
        rows[i] ^= (1 << digit);
        cols[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }
    
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        auto [i, j] = spaces[pos];
        int mask = ~(rows[i] | cols[j] | block[i / 3][j / 3]) & 0x1ff;
        for ( ; mask && !valid; mask &= (mask - 1))
        {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // I.
        // memset(rows, false, sizeof(rows));
        // memset(cols, false, sizeof(cols));
        // memset(block, false, sizeof(block));
        // valid = false;

        // for (int i = 0; i < 9; i++)
        // {
        //     for (int j = 0; j < 9; j++)
        //     {
        //         if (board[i][j] == '.')
        //         {
        //             spaces.emplace_back(i, j);
        //         } else
        //         {
        //             int digit = board[i][j] - '0' - 1;
        //             rows[i][digit] = cols[j][digit] = block[i / 3][j / 3][digit] = true;
        //         }
        //     } 
        // }
        // dfs(board, 0);

        // II.
        // memset(rows, 0, sizeof(rows));
        // memset(cols, 0, sizeof(cols));
        // memset(block, 0, sizeof(block));
        // valid = false;

        // for (int i = 0; i < 9; i++)
        // {
        //     for (int j = 0; j < 9; j++)
        //     {
        //         if (board[i][j] == '.')
        //         {
        //             spaces.emplace_back(i, j);
        //         } else {
        //             int digit = board[i][j] - '0' - 1;
        //             flip(i, j, digit);
        //         }
        //     }
        // }
        // dfs(board, 0);

        // III.
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(block, 0, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
            }
        }

        while (true)
        {
            int modified = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        int mask = ~(rows[i] | cols[j] | block[i / 3][j / 3]) & 0x1ff;
                        if (!(mask & (mask - 1)))
                        {
                            int digit = __builtin_ctz(mask);
                            flip(i, j, digit);
                            board[i][j] = digit + '0' + 1;
                            modified = true;
                        }
                    }
                }
            }
            if (!modified)
            {
                break;
            }
        }
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
            }
        }
        dfs(board, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */


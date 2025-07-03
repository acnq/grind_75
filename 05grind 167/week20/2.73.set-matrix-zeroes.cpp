// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30204
 *
 * [73] 矩阵置零
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
    // 先进行一个SC: O(m + n)的算法
    // I. 标记变量
    // 额外SC: O(1)的算法关键是把上述的标记数组放到原数组的第一列和第一行
    // 那如果本来不包含0，这样修改了之后，第一行第一列不是必然置0了么
    // 我们用额外的标记变量记录分别记录首行和首列是否包含0即可
    // algo: (1) 首先给标记变量赋值，(2) 然后用其他行处理首行与首列，
    //       (3) 再然后用这两个序列更新其他行列; (4) 最后用标记变量还原第一行和第一列即可

    // II. 标记+倒序
    // 只用一个标记变量可么？
    // 可以，只标记第一列原本是否有0，matrix[0][0]标记第一行是否有0
    // 
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size(); 
        // unordered_set<int> zeroRows, zeroCols;

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(matrix[i][j] == 0) {
        //             zeroRows.insert(i);
        //             zeroCols.insert(j);
        //         }
        //     }
        // }

        // for(int zeroRow: zeroRows) {
        //     for(int j = 0; j < n; j++) {
        //         matrix[zeroRow][j] = 0;
        //     }
        // }
        // for(int zeroCol: zeroCols) {
        //     for(int i = 0; i < m; i++) {
        //         matrix[i][zeroCol] = 0;
        //     }
        // }
        // 10 min a.c., 但并非最优
        // 感觉这题的难度在矩阵元素的取值是满的，所以很难用特殊值标记

        // int m = matrix.size();
        // int n = matrix[0].size();
        // bool col0flg = false, row0flg = false;
        // for(int i = 0; i < m; i++) {
        //     if(matrix[i][0] == 0) {
        //         col0flg = true;
        //     }
        // }
        // for(int j = 0; j < n; j++) {
        //     if(matrix[0][j] == 0) {
        //         row0flg = true;
        //     }
        // }

        // for(int i = 1; i < m; i++) {
        //     for(int j = 1; j < n; j++) {
        //         if(matrix[i][j] == 0) {
        //             matrix[i][0] = 0;
        //             matrix[0][j] = 0;
        //         }
        //     }
        // }

        // for(int i = 1; i < m; i++) {
        //     for(int j = 1; j < n; j++) {
        //         if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // if(col0flg) {
        //     for(int i = 0; i < m; i++) {
        //         matrix[i][0] = 0;
        //     }
        // }

        // if(row0flg) {
        //     for(int j = 0; j < n; j++) {
        //         matrix[0][j] = 0;
        //     }
        // }

        int m = matrix.size();
        int n = matrix[0].size();
        bool col0flg = false;
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                col0flg = true;
            }
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (col0flg) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */


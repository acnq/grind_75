// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 * @lcpr version=30204
 *
 * [1886] 判断矩阵经轮转后是否一致
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
    vector<vector<int>> rotate90(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> ret(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = mat[n - 1 - j][i];
            }
        }
        return ret;
    }
    bool comp(vector<vector<int>>& p, vector<vector<int>>& q) {
        int n = p.size(), m = p[0].size(); // 题目保证mat和target大小一样
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] != q[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // 旋转四次即可
        // 完成公约30min
        // vector<vector<int>> src = mat;
        // for (int i = 0; i < 4; i++) {
        //     if (comp(src, target)) {
        //         return true;
        //     }
        //     vector<vector<int>> src_p = rotate90(src);
        //     src = src_p;
        // }
        // return false;

        // I. 参考答案直接原地旋转
        int n = mat.size();
        for (int k = 0; k < 4; k++) {
            // 旋转
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < (n + 1) / 2; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[n - 1 - j][i];
                    mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                    mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                    mat[j][n - 1 - i] = temp;
                }
            }
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findRotation
// paramTypes= ["number[][]","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[0,1],[1,0]]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,1]]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,0],[1,1,1]]\n[[1,1,1],[0,1,0],[0,0,0]]\n
// @lcpr case=end

 */


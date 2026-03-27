/*
 * @lc app=leetcode.cn id=1727 lang=cpp
 * @lcpr version=30204
 *
 * [1727] 重新排列后的最大子矩阵
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
    // I. 排序法:
    // 我们首先按列预处理矩阵,使得matrix(i, j)表示i上方连续的1的长度
    // 枚举矩阵的每个位置,当(i,j)作为右下角顶点的时候,子矩阵的高最多为matrix[i][j]
    // 同行中所有上方连续1长度>=matrix[i][j]列均可移到左侧,构成高为matrix[i][j]的全1矩阵
    // 于是我们将预处理后的矩阵每行从大到小排序,对矩阵顺序遍历计算以该行为底的最大全1矩阵
    // 遍历到(i,j)时,所得符合条件的矩阵面积为matrix[i][j] * (j + 1)
    // 如此每行更新即可
    //
    // tc: O(mnlogn), sc: O(logn) [排序]
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        // 预处理
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        // 枚举
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (j + 1) * matrix[i][j]);
            }
        }
        return maxArea;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1],[1,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[0,0]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=498 lang=cpp
 * @lcpr version=30204
 *
 * [498] 对角线遍历
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
    // I. 直接模拟
    // 1. 一共m + n - 1条对角线，相邻的便利方向不同
    // 2. 设对角线从上到下的编号为i \in [0, m + n - 2]
    //      i % 2 == 0： 从下往上遍历
    //      i % 2 == 1： 从上往下遍历
    // 3. i从下往上遍历：每次行索引-1，列索引+1，直到矩阵边界
    //      i < m: 起点位置(i, 0);
    //      i >= m: 起点位置(m - 1, i - m + 1)
    // 4. i从下往上遍历：每次行索引+1, 列索引-1，知道矩阵边界为止
    //      i < n: 起点位置(0, i)
    //      i >= n: 起点位置(i - n + 1, n - 1)
    // tc: O(m * n); sc: O(1)
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2) {
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0) {
                    res.emplace_back(mat[x][y]);
                    x++;
                    y--;
                } 
            } else {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n) {
                    res.emplace_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3548 lang=cpp
 * @lcpr version=30204
 *
 * [3548] 等和矩阵分割 II
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
    // I. 旋转矩阵 + 哈希表 + 枚举上半矩阵之和
    // 与T3546相比,添加了'删除至多一个单元格'和'删除后剩余部分保持联通'
    // 假设我们仅考虑是否存在水平分割线,并且进行删除操作时仅删除上方元素
    // 如果矩阵进行3次90°旋转,则每种方案都能划归为上述操作
    // 划归为上述约束之后,我们判断按如下:
    // 1. 假设当前grid上半矩阵和为sum, 整个矩阵grid和为total
    //    下半矩阵和为total - sum
    // 2. 假设要删除元素为x, 
    //     则sum - x == total - sum => x == sum * 2 - total;
    // 3. 因此,枚举每行之后只需判断是否存在grid[i][j]
    //    s.t. grid[i][j] == sum * 2 - total
    // 使用集合保存出现过的元素以便避免重复,预存0表示不删除元素的情况
    // 特殊情况:
    // 1. grid在遍历第一行时:
    //      能够删除的元素只有首尾,只需判断grid[0][0]和grid[0][n - 1]或者0
    // 2. grid只有一列:
    //      只能删除首行和尾行的元素,遍历第i行只需要判断
    //      grid[0][0]或者grid[i][0]或者0即可
    // 3. grid只有一行直接跳过,无法进行水平分割
    // 其他情况下,grid上班矩阵所有元素均可删除
    // 旋转3次之后可以覆盖所有情况.
    //
    // 
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum, tag;
        int m = grid.size(), n = grid[0].size();
        unordered_set<long long> exist;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        for (int k = 0; k < 4; k++) {
            exist.clear();
            exist.insert(0);
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            if (m < 2) {
                // 仅一行
                grid = rotation(grid);
                continue;
            }
            if (n == 1) {
                // 仅一列
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    tag = sum * 2 - total;
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                tag = sum * 2 - total;
                if (i == 0) {
                    if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]) {
                        return true;
                    }
                    continue;
                }
                if (exist.count(tag)) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,4],[2,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,8],[3,2,6]]\n
// @lcpr case=end

 */


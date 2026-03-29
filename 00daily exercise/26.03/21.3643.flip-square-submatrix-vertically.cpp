// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 * @lcpr version=30204
 *
 * [3643] 垂直翻转子矩阵
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
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ans = grid;
        int i = x, i_inv = x + k - 1;
        for (i = x; i < x + k / 2; i++) {
            // 24min 注意不要把i_inv = x + k - 1搬到这里,
            // i_inv应该是全局的
            for (int j = y; j < k + y; j++) {
                swap(ans[i][j], ans[i_inv][j]);
            }
            i_inv--;
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=reverseSubmatrix
// paramTypes= ["number[][]","number","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n1\n0\n3\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,2,3],[2,3,4,2]]\n0\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// [[14,3,18,16],[2,14,11,20],[19,19,4,15],[11,15,18,6]]\n0\n0\n4\n
// @lcpr case=end


 */


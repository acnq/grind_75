/*
 * @lc app=leetcode.cn id=2946 lang=cpp
 * @lcpr version=30204
 *
 * [2946] 循环移位后的矩阵相似检查
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
    vector<int> leftshift(vector<int>& array, int k) {
        int m = array.size();
        k = k % m;
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            if (i < m - k) {
                res[i] = array[i + k];
            } else {
                res[i] = array[(i + k) % m];
            }
        }
        return res;
    }

    vector<int> rightshift(vector<int>& array, int k) {
        int m = array.size();
        k = k % m;
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            if (i < k) {
                res[i] = array[m + (i - k)];
            } else {
                res[i] = array[i - k];
            }
        }
        return res;
    }

    bool comp(vector<vector<int>>& p, vector<vector<int>>& q) {
        int n = p.size(), m = p[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] != q[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        // 24min
        // vector<vector<int>> shifted = mat;
        // int n = mat.size(), m = mat[0].size();
        // for (int i = 0; i < n; i++) {
        //     if (i % 2 == 0) {
        //         shifted[i] = leftshift(mat[i], k);
        //     } else {
        //         shifted[i] = rightshift(mat[i], k);
        //     }
        // }
        // return comp(shifted, mat);

        // 标答写法
        int m = mat.size(), n = mat[0].size();
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 仅判断相等与否,不需要区分偶数行还是奇数行
                if (mat[i][j] != mat[i][(j + k) % n]){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1,2],[5,5,5,5],[6,3,6,3]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,2],[2,2]]\n3\n
// @lcpr case=end

 */


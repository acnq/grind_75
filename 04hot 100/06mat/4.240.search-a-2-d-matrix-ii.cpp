// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 * @lcpr version=30204
 *
 * [240] 搜索二维矩阵 II
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
    // 感觉只能想到通过递归作？
    // 而且这里matrix的nm好像标反了，一般矩阵竖为n，横为m, 这里反过来了
    // I. 穷举能做，但是太naive了, 不记
    // 
    // II. 按行二分查找
    // tc: O(m logn); sc: O(1)

    // III. Z型查找
    // 这才是需要会的算法
    // 我思路中，一直没有办法很好的处理左上角和右上角
    // 那么能不能我们直接把搜索范围放到这两个角度上
    // 我们从矩阵右上角(0, n - 1)进行搜索，如果我们位于位置(x, y)
    // 我们直接搜索matrix左下角到以(x, y)为右上角的矩阵中搜索，
    // 搜索范围，行[x, m - 1], 列[0, y];
    // matrix[x, y] = target: 搜索完成
    // matrix[x, y] > target: 那么位于第y列的元素都严格大于target, 全部忽略，i.e. y--;
    // matrix[x, y] < target: 同理位于第x行的元素都严格小于target, 全部忽略，i.e. x++;
    // 于是我们从右上角逐渐向右下角靠近，直到超出边界都无=，则矩阵不存在target
    // tc: O(m + n); sc: O(1);

public:
    bool searchMatIJ(vector<vector<int>>& matrix, int target, int lft, int top, int rght, int btn) {
        if (lft == rght && top == btn) {
            return matrix[lft][top] == target;
        }
        if (lft == rght - 1 && top == btn - 1) {
            return matrix[top][lft] == target || matrix[btn][lft] == target || matrix[top][rght] == target || matrix[btn][rght] == target;
        }
        if (lft == rght && top == btn - 1) {
            return matrix[top][lft] == target || matrix[btn][lft] == target;
        }
        if (lft == rght - 1 && top == btn) {
            return matrix[top][lft] == target || matrix[top][rght] == target;
        }
        int midi = (lft + rght) / 2, midj = (top + btn) / 2;
        int midVal = matrix[midj][midi];
        bool res1 = false, res2 = false;
        if(midVal == target) {
            return true;
        } else if(target < midVal) {
            res1 = searchMatIJ(matrix, target, lft, top, midi, midj);
        } else {
            res2 = searchMatIJ(matrix, target, midi, midj, rght, btn);
        }
        bool res3 = searchMatIJ(matrix, target, midi, top, rght, midj);
        bool res4 = searchMatIJ(matrix, target, lft, midj, midi, btn);
        return res1 || res2 || res3 || res4;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m = matrix.size(), n = matrix[0].size();
        // bool res = searchMatIJ(matrix, target, 0, 0, n - 1, m - 1);
        // return res;
        // 递归都写了51min, 感觉有点难TAT

        // II.
        // for(const auto& row: matrix) {
        //     auto it = lower_bound(row.begin(), row.end(), target);
        //     if(it != row.end() && *it == target) {
        //         return true;
        //     }
        // }
        // return false;

        // III.
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m && y >= 0) {
            if(matrix[x][y] == target) {
                return true;
            } else if(matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
// @lcpr case=end

// @lcpr case=start
//[[1,3,5]]\n-1\n
// @lcpr case=end


// @lcpr case=start
//[[3,5,9,9,14],[7,8,11,15,15],[8,10,16,16,17]]\n12\n
// @lcpr case=end
 */


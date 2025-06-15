// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 * @lcpr version=30204
 *
 * [1232] 缀点成线
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
    // 我们似乎只要顺序判断每两个相邻的点斜率是否一样即可
    // 如果是，则总体一定共线，否则便是不共线
    // 例外是与y轴平行的线，要单独考虑；
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // int n = coordinates.size();
        // if((coordinates[0][0] == coordinates[1][0])) {
        //     int coory = coordinates[1][0];
        //     for(int i = 2; i < n; i++) {
        //         if (coordinates[i][0] != coory) {
        //             return false;
        //         }
        //     }
        //     return true;
        // } else {
        //     double k = (coordinates[1][1] - coordinates[0][1]) * 1.0 / (coordinates[1][0] - coordinates[0][0]) * 1.0; 
        //     for(int i = 1; i < n - 1; i++) {
        //         if (coordinates[i + 1][0] == coordinates[i][0]) {
        //             return false;
        //         }
        //         double tmpk = (coordinates[i + 1][1] - coordinates[i][1]) * 1.0 / (coordinates[i + 1][0] - coordinates[i][0]) * 1.0;
        //         if (k != tmpk) {
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        // 不难，整体20min

        // 官方题解，我们不用除法, 就不用分类讨论了
        int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
        int n = coordinates.size();
        for (int i = 0; i < n; i++) {
            coordinates[i][0] -= deltaX;
            coordinates[i][1] -= deltaY;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if (A * x + B * y != 0) {
                return false;
            }
        }
        return true;
    } 
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=checkStraightLine
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[-4,-3],[1,0],[3,-1],[0,-1],[-5,2]]\n
// @lcpr case=end

 */


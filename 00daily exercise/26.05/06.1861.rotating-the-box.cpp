/*
 * @lc app=leetcode.cn id=1861 lang=cpp
 * @lcpr version=30204
 *
 * [1861] 旋转盒子
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
    // I. 队列维护空位
    // 顺时针旋转后，行会变成列，旋转前，行并不互相影响
    // 由于重力向下，我们应当从右向左遍历原先的每行
    // 我们用队列存放一行中的空位
    // 遍历到石头，从队首取出空位放置石头，无空位则石头不动
    // 遍历到空位，入队
    // 遍历到障碍，清空队列，因为右侧空位都不可以用
    // 遍历之后，我们顺时针90°转即可
    // (rotated[j][m - i - 1]) = box[i][j]
    // tc: O(mn), sc: O(n)
    // II. 指针维护
    // 通过方法I, 很显然，遍历到某个位置后，如果队列不会空，
    // 1. 队尾会变成该位置；（如果是石头，落下后变为空，如果是障碍，队首=队尾）
    // 2. 队列中位置依旧连续；（石头落下后空位必然也是连续的）
    // 所以我们无需显式维护这个队列，只需要维护队首的位置
    // 
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        // I.
        // int m = boxGrid.size();
        // int n = boxGrid[0].size();

        // for (int i = 0; i < m; i++) {
        //     deque<int> q;
        //     for (int j = n - 1; j >= 0; j--) {
        //         if (boxGrid[i][j] == '*') {
        //             // 遇到障碍物，清空队列
        //             q.clear();
        //         } else if (boxGrid[i][j] == '#') {
        //             if (!q.empty()) {
        //                 // 队列不空，石头落下
        //                 int pos = q.front();
        //                 q.pop_front();
        //                 boxGrid[i][pos] = '#';
        //                 boxGrid[i][j] = '.';
        //                 // 石头变为空位，也入队
        //                 q.push_back(j);
        //             }
        //         } else {
        //             // 空位入队
        //             q.push_back(j);
        //         }
        //     }
        // }

        // // 转动
        // vector<vector<char>> ans(n, vector<char>(m));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         ans[j][m - i - 1] = boxGrid[i][j];
        //     }
        // }
        // return ans;

        // II.
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            // 维护队首位置
            int front_pos = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    // 遇到障碍物，清空队列
                    front_pos = j - 1;
                } else if (boxGrid[i][j] == '#'){
                    if (front_pos > j) {
                        // 队列不空，石头落下
                        boxGrid[i][front_pos] = '#';
                        boxGrid[i][j] = '.';
                        front_pos--;
                    } else {
                        // 队列为空，移动队首
                        front_pos = j - 1;
                    }
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = boxGrid[i][j];
            }
        }
        return ans;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [["#",".","#"]]\n
// @lcpr case=end

// @lcpr case=start
// [["#",".","*","."],["#","#","*","."]]\n
// @lcpr case=end

// @lcpr case=start
// [["#","#","*",".","*","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // I. 模拟
        // if (matrix.size() == 0 || matrix[0].size() == 0)
        // {
        //     return {};
        // }

        // int rows = matrix.size(), columns = matrix[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(columns));
        // int total = rows * columns;
        // vector<int> order(total);

        // int row = 0, column = 0;
        // int directionIdx = 0;
        // for (int i = 0; i < total; i++)
        // {
        //     order[i] = matrix[row][column];
        //     visited[row][column] = true;
        //     int nextRow = row + directions[directionIdx][0];
        //     int nextColumn = column + directions[directionIdx][1];
        //     if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns
        //         || visited[nextRow][nextColumn])
        //     {
        //         directionIdx = (directionIdx + 1) % 4;
        //     }
        //     row += directions[directionIdx][0];
        //     column += directions[directionIdx][1];
        // }
        // return order;

        // II. 按层模拟
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom)
        {
            for (int column = left; column <= right; column++)
            {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++)
            {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom)
            {
                for (int column = right - 1; column > left; column--)
                {
                    order.push_back(matrix[bottom][column]);
                }
                for (int  row = bottom; row > top; row--)
                {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=799 lang=cpp
 * @lcpr version=30204
 *
 * [799] 香槟塔
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
    // I. 模拟
    // 首先求出每一层的每一只杯子中的香槟体积，
    // 求出row = query_row的杯子的香槟体积, 取第query_glass个杯子中的体积
    // 与1求较小值返回。
    // tc: O(query_row^2), sc: O(query_row)
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double)poured};

        for (int i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1, 0.0);
            for (int j = 0; j < row.size(); j++) {
                double volume = row[j];
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;
        }

        return min(1.0, row[query_glass]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 100000009\n33\n17\n
// @lcpr case=end

 */


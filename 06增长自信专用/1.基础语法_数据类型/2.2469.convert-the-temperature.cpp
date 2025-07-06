/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 * @lcpr version=30204
 *
 * [2469] 温度转换
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
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
        res.push_back(celsius + 273.15);
        res.push_back(celsius * 1.80 + 32.00);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 36.50\n
// @lcpr case=end

// @lcpr case=start
// 122.11\n
// @lcpr case=end

 */


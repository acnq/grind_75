/*
 * @lc app=leetcode.cn id=258 lang=cpp
 * @lcpr version=30204
 *
 * [258] 各位相加
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
    int addDigits(int num) {
        // I. 模拟
        // while (num >= 10)
        // {
        //     int sum = 0;
        //     while (num > 0)
        //     {
        //         sum += num % 10;
        //         num /= 10;
        //     }
        //     num = sum;
        // }
        // return num;

        // II. 取余
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 38\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */


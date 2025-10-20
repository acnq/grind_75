/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 * @lcpr version=30204
 *
 * [2011] 执行操作后的变量值
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
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string op: operations) {
            if (op == "X++" || op == "++X") {
                x++;
            }
            if (op == "X--" || op == "--X") {
                x--;
            }
        }
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["--X","X++","X++"]\n
// @lcpr case=end

// @lcpr case=start
// ["++X","++X","X++"]\n
// @lcpr case=end

// @lcpr case=start
// ["X++","++X","--X","X--"]\n
// @lcpr case=end

 */


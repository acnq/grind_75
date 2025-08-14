/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 * @lcpr version=30204
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
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
    // I. 禁止转化
    // 我们将n转换成3进制，只要每一位均不包含2，就能判断她一定可以被拆分
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 91\n
// @lcpr case=end

// @lcpr case=start
// 21\n
// @lcpr case=end

 */


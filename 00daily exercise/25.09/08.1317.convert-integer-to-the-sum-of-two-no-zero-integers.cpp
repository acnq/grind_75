/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 * @lcpr version=30204
 *
 * [1317] 将整数转换为两个无零整数的和
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
    // 6min, 秒杀
    bool isZeorInteger(int n) {
        while (n != 0) {
            int digit = n % 10;
            if (digit == 0) {
                return false;
            }
            n = n / 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (!isZeorInteger(i) && !(isZeorInteger(n - i))) {
                return {n, n - i};
            }
        }
        return {0, 0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 10000\n
// @lcpr case=end

// @lcpr case=start
// 69\n
// @lcpr case=end

// @lcpr case=start
// 1010\n
// @lcpr case=end

 */


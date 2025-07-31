/*
 * @lc app=leetcode.cn id=2683 lang=cpp
 * @lcpr version=30204
 *
 * [2683] 相邻值的按位异或
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 数学
    // derived[i] = { original[i] \circplus original[i + 1], i < n - 1
    //              { original[n - 1] \circplus original[0], i = n - 1
    // \Circplus_{i=0}^{n-1}derived[i] = \Circplus_{i=0}^{n-1}(original[i]\circplus original[i]) = 0
    // (因为一个数亦或自己=0)
    // 于是我们直接判断derived的全部元素亦或和是否为0，否则一定不可能
    // 那么是就一定可能么？当然，因为上述推导是可逆的，我们直接说明构造original的方法：
    // 令original[0] = 0, original[i] = original[i - 1] \circplus derived[i - 1]
    // derived[i - 1] = original[i - 1] \circplus o[i], 两边异或original[i - 1]即可。
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return reduce(derived.begin(), derived.end(), 0, bit_xor()) == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0]\n
// @lcpr case=end

 */


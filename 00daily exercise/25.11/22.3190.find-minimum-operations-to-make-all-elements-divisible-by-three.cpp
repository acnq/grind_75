/*
 * @lc app=leetcode.cn id=3190 lang=cpp
 * @lcpr version=30204
 *
 * [3190] 使所有元素都可以被 3 整除的最少操作数
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
public:
    int minimumOperations(vector<int>& nums) {
        // 每个不被3整除的元素操作一次即可被3整除
        // int op = 0;
        // for (int num: nums) {
        //     if (num % 3 != 0) {
        //         op++;
        //     }
        // }
        // return op;
        // 参考答案写复杂了：
        return accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + min(v % 3, 3 - v % 3);
        });
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,9]\n
// @lcpr case=end

 */


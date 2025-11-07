/*
 * @lc app=leetcode.cn id=3289 lang=cpp
 * @lcpr version=30204
 *
 * [3289] 数字小镇中的捣蛋鬼
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
    // I. 哈希（我的方法）
    // tc: O(n), sc: O(n)
    // II 位运算
    // 太复杂，Ommit
    // III. 数学
    // 设两个答案为x1, x2, nums的和为sum, 平方和为squSum,
    // 因为0到n-1的数字和为n(n-1)/2, 平方和为n(n-1)(2n-1)/6
    // 记sum2 = sum - n(n-1)/2, squSum2 = squSum - n(n-1)(2n-1)/6
    // x1 + x2 = sum2, x1^2 + x2^2 = squSum2
    // 解得x1 = (sum2 - \sqrt{2*squSum2 - sum2^2})/2
    //     x2 = (sum2 + \sqrt{2*squSum2 - sum2^2})/2
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // unordered_map<int, int> count;
        // vector<int> res;
        // for (int i = 0; i < n; i++) {
        //     count[nums[i]]++;
        // }
        // for (auto [k, v]: count) {
        //     if (v == 2) {
        //         res.push_back(k);
        //     }
        // }
        // return res;
        // III.
        int n = (int)nums.size() - 2;
        int sum = 0, squSum = 0;
        for (int x: nums) {
            sum += x;
            squSum += x * x;
        }
        int sum2 = sum - n * (n - 1) / 2;
        int squSum2 = squSum - n * (n - 1) * (2 * n - 1) / 6;
        int x1 = (sum2 - sqrt(2 * squSum2 - sum2 * sum2)) / 2;
        int x2 = (sum2 + sqrt(2 * squSum2 - sum2 * sum2)) / 2;
        return {x1, x2};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,2,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,5,4,3,4,6,0,9,5,8,2]\n
// @lcpr case=end

 */


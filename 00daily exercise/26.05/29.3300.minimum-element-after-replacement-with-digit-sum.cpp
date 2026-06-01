/*
 * @lc app=leetcode.cn id=3300 lang=cpp
 * @lcpr version=30204
 *
 * [3300] 替换为数位和以后的最小元素
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
    int digSum(int x) {
        int ans = 0;
        while (x > 0) {
            int digit = x % 10;
            ans += digit;
            x = x / 10; 
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        // O.
        // int ans = INT_MAX;
        // for (int num: nums) {
        //     int dig_sum = digSum(num);
        //     if (dig_sum < ans) {
        //         ans = dig_sum;
        //     }
        // }
        // return ans;

        // I. 标准答案
        int ans = 37; // 因为每个元素不超过10^4, ans > 4 * 9 = 36 即可
        for (int num: nums) {
            int dig = 0;
            while (num) {
                dig += num % 10;
                num /= 10;
            }
            ans = min(ans, dig);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,12,13,14]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [999,19,199]\n
// @lcpr case=end

 */


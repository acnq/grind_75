/*
 * @lc app=leetcode.cn id=2778 lang=cpp
 * @lcpr version=30204
 *
 * [2778] 特殊元素平方和
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
    int sumOfSquares(vector<int>& nums) {
        // O. 秒杀：
        // int n = nums.size();
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     if (n % (i + 1) == 0) {
                
        //         ans += nums[i] * nums[i];
        //     }
        // }
        // return ans;

        // II. 枚举因数
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
                if (i * i != n) {
                    ans += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,1,19,18,3]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2654 lang=cpp
 * @lcpr version=30204
 *
 * [2654] 使数组所有元素变成 1 的最少操作次数
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
    // I. 贪心
    // 如果nums中所有数字的gcd两两>1, 那么无论如何都无法让数组变为1
    // 如果nums中已经1，那我们可以让1和旁边非1操作，最多操作n - num1
    // num1表示nums中1的个数
    // 如果不属于以上两种情况，可以找到最小区间，这个区间所有数字的gcd是1
    // 假设这个区间长度是minLen, 由这些数字得到一个1需要minLen-1
    // 然后再由这个1使得其他数字都变为1所需次数为n-1, 共需要minLen + n - 2次
    // 我们按照区间长度从小到大枚举所有区间计算gcd

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        int g = 0;
        for (int x: nums) {
            if (x == 1) {
                num1++;
            }
            g = gcd(g, x);
        }
        if (num1 > 0) {
            return n - num1;
        }
        if (g > 1) {
            return -1;
        }

        int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return min_len + n - 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,10,6,14]\n
// @lcpr case=end

 */


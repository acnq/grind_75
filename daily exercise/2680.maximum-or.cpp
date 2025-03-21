/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 * @lcpr version=30204
 *
 * [2680] 最大或值
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
    // I. 贪心前缀和
    // 找到高位1的数字*2更能令或的结果最大,
    // k次操作都操作此数，效果最好
    // 如何快速获取其他整数的或
    // 维护后缀或数组suf和前缀或值pre,
    // 计算某个元素操作k次的结果只需要O(1)

    // II. 位运算技巧
    // 如果某位中，所有整数出现过两次及以上1，去除任何一个整数
    // 结果仍为1
    // 维护前缀或值，与当前枚举值进行与运算即可得到出现两次及以上的1
    // 将这些1进行或运算得到multi_bits
    // 设所有数字或值为or_sum, 当前枚举数字x
    // (or_sum 异或 x) 或 multi_bits = 除去x后剩余所有整数的或
public:
    using ll = long long;
    long long maximumOr(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<ll> suf(n + 1, 0);

        // for (int i = n - 1; i >= 0; i--)
        // {
        //     suf[i] = suf[i + 1] | nums[i];
        // }

        // ll res = 0;
        // ll pre = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     res = max(res, pre | (1ll * nums[i] << k) | suf[i + 1]);
        //     pre |= nums[i];
        // }
        // return res;
        
        // II
        int n = nums.size();
        ll or_sum = 0;
        ll multi_bits = 0;
        for(auto x: nums) {
            multi_bits |= (x & or_sum);
            or_sum |= x;
        }

        ll res = 0;
        for(auto x: nums) {
            res = max(res, (or_sum ^ x) | (1ll * x << k) | multi_bits);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [8,1,2]\n2\n
// @lcpr case=end

 */


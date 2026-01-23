/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 * @lcpr version=30204
 *
 * [1877] 数组中最大数对和的最小值
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
    // I. 排序+贪心
    // 考虑四个数字的情况x1 <= x2 <= x3 <= x4
    // 此时(x1, x4), (x2, x3)的拆分方法对应的最大数对和一定最小的
    // 证明：
    //      枚举另外两种拆分方法：
    //      1. (x1, x3), (x2, x4), 显然(x2, x4)一定会更大
    //          注意到，x2 + x4 >= x1 + x4; x2 + x4 >= x2 + x3
    //          max(x1 + x3, x2 + x4) >= x2 + x4 >= max(x1 + x4, x2 + x3)
    //      2. (x1, x2), (x3, x4), 显然(x3, x4)更大，同理有
    //         x3 + x4 >= max(x1 + x4, x2 + x3)
    // 于是我们可以声明：
    //  偶数个数的最有拆分为第k大的和第k小的组合成共n/2个数对
    //  证明：假设x_k + x_{n + 1 - k}的最大值在k = k'取到
    //       我们欲证对于任意拆分，总可以找到x_u + x_v >= x_{k'} + x_{n + 1 - k'}
    //       假设u < v, 是的x_v >= x_{n + 1 - k'}的v共有k'种
    //       (i.e.[n + 1 - k', n]中所有整数), 这些v对应的数对
    //       要有x_u + x_v < x_{k'} + x_{n + 1 - k'}恒成立
    //       必须有x_u < x_{k'}, 这样必须有k'不同的u取值
    //       但只有闭区间[1, k' - 1]中的k' - 1个整数满足x_u < x_{k'}条件，矛盾
    //       故一定有一组u, v, s.t. x_u + x_v >= x_{k'} + x_{n + 1 - k'}
    // 于是可以得到简短的代码如下：
    // tc: O(nlogn), sc: O(logn)
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,4,2,4,6]\n
// @lcpr case=end

 */


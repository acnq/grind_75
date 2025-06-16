// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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

#include <numeric> // for gcd
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 额外数组
    // 秒杀
    // II. 环状替换
    // 我们使用逐个替换的方案，比如，从s[0]开始，tmp=nums[0],
    // 注意到nums[0]最后一定会放到(0 + k) mod n的位置，于是让tmp放到nums[(0 + k) mod n]
    // 上，之后交换tmp和nums[(x + k) mod n] (x = (0 + k) mod n)
    // 循环转换，直到回到0，
    // 但是显然，这样跳转，可能会遍历不到部分变量，那怎么算结束呢？穷举么
    // 不放这么思考：以此跳转回到0，遍历了多少元素
    // 假设这个过程走了a圈，遍历了b个元素，an = bk => an为n, k的最小公倍数
    // 记为an = lcm(n, k), b = lcm(n, k) / k
    // 那么要访问所有元素，需要遍历次数：n / (lcm(n, k) / k) = nk / lcm(n, k) = gcd(n, k)

    // III. 四次翻转
    // k = k % n之后，尾部k个元素会进入头，其余后移k
    // 先全部翻转，这样尾部k个元素先到头，然后把[0, k-1]区间和[k - 1, n - 1]的元素翻转回来就是答案

public:
    void rotate(vector<int>& nums, int k) {
        // int n = nums.size();
        // k = k % n;
        // vector<int> tmp(n);
        // for (int i = 0; i < n; i++)
        // {
        //     if (i < k)
        //     {
        //         tmp[i] = nums[n - k + i];
        //     } else {
        //         tmp[i] = nums[i - k];
        //     }
        // }
        // nums = tmp;
        // II.
        // int n = nums.size();
        // k = k % n;
        // int cnt = gcd(k, n);
        // for (int i = 0; i < cnt; i++)
        // {
        //     int cur = i;
        //     int prev = nums[i];
        //     do {
        //         int nxt = (cur + k) % n;
        //         swap(nums[nxt], prev);
        //         cur = nxt;
        //     } while (i != cur);
        // }

        // III.
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */


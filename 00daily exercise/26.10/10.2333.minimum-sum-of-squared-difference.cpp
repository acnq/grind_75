/*
 * @lc app=leetcode.cn id=2333 lang=cpp
 * @lcpr version=30204
 *
 * [2333] 最小差值平方和
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
    // 显然，在nums1进行的操作可以被nums2上进行的等价操作替代
    // 所以nums1上的操作和nums2的奥做是等价的，
    // 我们最多可以进行 k = k1 + k2次操作
    // 我们的目标为：
    // min\sigma_{i=0}^{n-1}(nums1[i] - nums2[i])^2
    // 定义diff[i] := |nums1[i] - nums2[i]|, 每次操作都能使diff--
    // 所以直觉上，选择diff最大的元素-1是最佳的，
    // 我们于是将diff从大到小排序，遍历，到i的时候削减方式如下
    // i = 1, 将diff[0]削减diff[1]
    // i > 1, 由于diff[0:(i-1)]均被削减到diff[i-1]了，当前操作量为
    //      cost = (diff[i - 1] - diff[i]) * i
    // 如果k > cost, 说明当前剩余的操作次数能够支撑，k -= cost即可
    // 否则当前剩余操作无法满足前i个元素都削减为diff[i], 
    // 那么我们只能对部分元素进行削减，就需要进行收尾
    // 1. 先计算i个元素共同削减的值q=\floor{k/i}
    // 2. 再计算剩余次数r = k mod i, 以及削减后的元素diff[i-1]-q;
    // 3. 然后计算从0到i-1的差值平方和，
    //    3.1. 对于前i-r个元素，其差值平方和为hi * hi * (i - r)
    //    3.2. 对于后r个元素，每个元素还能多削减一次，其差值平方和
    //      为 (hi - 1) * (hi - 1) * r;
    //    3.3. 处理从i到n-1的差值平方和，
    //      即\sigma_{i}^{n-1}diff[i] * diff[i]
    // 我们可以在diff的最后插入一个0当做哨兵，避免边界判断
    // 代码实现中由于nums1能够复用，因此代码中diff体现为nums1.
    // tc: O(n\logn), sc: O(1);

    // II. 二分查找
    // 我们把diff的元素想象为高度是diff[i]的柱子，那么该题本质是
    // 要找到一个能够最大限度利用k的高度'h'，
    // 每根超过'h'的部分需要消耗k进行削减
    // 那么如何找到这个高度h呢？注意到答案随着h单调变化（h越大，对k的利用越大)
    // 二分查找这个h即可，计算剩余的k，统计答案时对还没有削减为0的元素削减
    // tc: O(n(\logn + \logm)) m: nums1/nums2各元素值的最大值；sc: O(1);
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // I.
        // long long k = (long long)k1 + k2;
        // int n = nums1.size();
        // for (int i = 0; i < n; i++) {
        //     nums1[i] = abs(nums1[i] - nums2[i]);
        // }
        //
        // if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k) {
        //     return 0; // 能全部削减到0
        // }
        // sort(nums1.begin(), nums1.end(), greater<int>());
        // nums1.push_back(0);
        // for (int i = 1; i <= n; i++) {
        //     long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
        //     if (cost > k) {
        //         long long q = k / i, r = k % i;
        //         long long hi = nums1[i - 1] - q;
        //         long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
        //         for (int j = i; j < n; j++) {
        //             ans += (long long)nums1[j] * nums1[j];
        //         }
        //         return ans;
        //     }
        //     k -= cost;
        // }
        // return 0;

        // II.
        int n = nums1.size();
        long long ans = 0;
        int k = k1 + k2;
        int maxDif = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxDif = max(maxDif, nums1[i]);
        }
        int l = 0, r = maxDif;
        auto check = [&](int mid) -> bool {
            long long sum = 0;
            for (int num: nums1) {
                sum += num > mid ? num - mid : 0;
            }
            return sum <= k;
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                res = mid;  // 表示h
            } else {
                l = mid + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums1[i] > res) {
                k -= (nums1[i] - res);
            }
        }

        sort(nums1.begin(), nums1.end(), greater<int>());
        for (int num: nums1) {
            long long diff = res >= num ? num : res;
            if (k && diff) {
                diff--;
                k--;
            }
            ans += diff * diff;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n[2,10,20,19]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,12]\n[5,8,6,9]\n1\n1\n
// @lcpr case=end

 */


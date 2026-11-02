/*
 * @lc app=leetcode.cn id=462 lang=cpp
 * @lcpr version=30204
 *
 * [462] 最小操作次数使数组元素相等 II
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
    // I. 排序
    // 我们首先假定数组长度为n偶数，将其排序之后首尾配对
    // 得到如下区间：
    // [nums_0, nums_{n-1}], [nums_1, nums_{n-2}], ..., [nums_{n/2-1}, nums_{n/2}]
    // 因为排序过了，我们有nums_0 < nums_1 < ... < nums_{n-1}
    // 设目标要把每个元素变成x, 注意到配对都要变成x的，所需要的移动最少为：
    // |nums_{n - 1 - i} - x| + |nums_i - x| >= |(nums_{n-1-i} - x) - (nums_i - x)|
    // = nums_{n-1-i} -nums_i, 等号当x \in [num_i, num_{n-1-i}]成立
    // 而且我们注意到区间序列中，后一个一定是前一个的子集，所以我们取
    // x \in [nums_{n/2 - 1}, nums_{n/2}]即可
    // n为奇数时，最后一个区间就是[nums_{\floor{n/2}}, nums_{\floor{n/2}}]
    // 则x \in [nums_{\floor{n/2}}, nums_{\floor{n/2}}] <=> x = nums_{\floor{n/2}}
    // 即可
    // 所以我们的目标就是找到nums_{\floor{n/2}} (无论n为奇数还是偶数)
    // 然后计算\sum_{i=0}^n |nums[i] - x| 即可
    // 绝对值不等式保证了这个和一定是最小的
    // tc: O(nlogn), sc: O(logn)

    // II. 快速选择算法
    // 我们要找到第k小的元素可以不用排序，有复杂度更低的快速选择算法
    // 参考快速排序，我们选取锚点p, 将所有比p大的元素放到右边，其余放到左边
    // 这是我们观察p的位置l, l一定是p在排序号后数组中的位置
    // 比较k和l的大小，如果k<l, 我们下面只递归[0, l]的部分，
    // 否则，只递归[l, n-1]的部分，
    // 这样相当于我们的快速排序每次只递归一半，复杂度会降低到O(n)
    // tc: O(n), sc: O(logn)
public:
    // II.
    int quickSelect(vector<int>& nums, int left, int right, int index) {
        int q = randomPartition(nums, left, right);
        if (q == index) {
            return nums[q];
        } else {
            return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
        }
    }
    inline int randomPartition(vector<int>& nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }
    inline int partition(vector<int>& nums, int left, int right) {
        int x = nums[right], i = left - 1;
        for (int j = left; j < right; j++) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
    int minMoves2(vector<int>& nums) {
        // I.
        // sort(nums.begin(), nums.end());
        // int n = nums.size(), ret =0, x = nums[n / 2];
        // for (int i = 0; i < n; i++) {
        //     ret += abs(nums[i] - x);
        // }
        // return ret;

        // II.
        srand(time(0));
        int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), ret = 0;
        for (int i = 0; i < n; i++) {
            ret += abs(nums[i] - x);
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,2,9]\n
// @lcpr case=end

 */


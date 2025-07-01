/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30204
 *
 * [169] 多数元素
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
    // I. 哈希表
    // 用哈希表存储每个元素出现的次数，然后返回最大值即可，
    // 遍历数组nums时维护最大值，这样就不用最后对哈希表的遍历
    // tc: O(n), sc: O(n)

    // II. 排序
    // nums单调排序之后，下标\floor{n/2}的元素一定是众数
    // tc: O(n logn); sc: O(logn)

    // III. 随机化
    // 随机挑选一个下标进行验证即可，因为众数如此之多，以至于有很低的期望复杂度
    // tc: O(n); sc: O(1)

    // IV 分治
    // 如果a是数组nums的众数，那么nums被分成两部分之后，a一定是至少一部分的众数
    // tc: O(n logn); sc: O(log n)

    // V. Boyer-Moore投票法
    // 1. 维护一个候选candidate和他出现的次数cnt, candidt可以任意初始化，cnt初始化为0
    // 2. 遍历nums，设当前元素为x, 如果count=0, 先将x赋予candidt; 随后我们如下判断：
    //      如果x与candidt相等，那么cnt++;
    //      如果x与candidt不等，cnt--;
    // 3. 遍历完成后，candit就是整个数组的众数
    // 其证明比较困难，可以看官方解法的解说
    // 唯一真正实现 tc: O(n)和sc: O(1)的算法

public:
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (nums[i] == target)
            {
                count++;
            }
        }
        return count;
    }

    int majority_element_rec(vector<int>& nums, int lo, int hi) {
        if (lo == hi)
        {
            return nums[lo];
        }
        int mid = (lo + hi) / 2;
        int left_maj = majority_element_rec(nums, lo, mid);
        int right_maj = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_maj, lo, hi) > (hi - lo + 1) / 2)
        {
            return left_maj;
        }
        if (count_in_range(nums, right_maj, lo, hi) > (hi - lo + 1) / 2)
        {
            return right_maj;
        }
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        // I.
        // unordered_map<int, int> counts;
        // int majority = 0, cnt = 0;
        // for (int num: nums) {
        //     counts[num]++;
        //     if (counts[num] > cnt)
        //     {
        //         majority = num;
        //         cnt = counts[num];
        //     }
        // }
        // return majority;

        // II.
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];

        // III.
        // while (true)
        // {
        //     int candidt = nums[rand() % nums.size()];
        //     int count = 0;
        //     for (int num: nums) {
        //         if (num == candidt)
        //         {
        //             count++;
        //         }
        //     }

        //     if (count > nums.size() / 2)
        //     {
        //         return candidt;
        //     }
        // }
        // return -1;

        // IV
        // return majority_element_rec(nums, 0, nums.size() - 1);

        // V
        int candidt = -1;
        int count = 0;
        for (int num: nums) {
            if (num == candidt)
            {
                count++;
            } else if (--count < 0)
            {
                candidt = num;
                count = 1;
            }
        }
        return candidt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */


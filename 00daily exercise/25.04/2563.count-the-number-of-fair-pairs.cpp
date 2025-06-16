/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=30204
 *
 * [2563] 统计公平数对的数目
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
    // I. 朴素算法
    // 超时

    // II. 二分查找
    // 首先O(nlogn)排序
    // 然后对于每个i, 用二分查找
    // 查找j, s.t. lower-nums[i] <= nums[j] <= upper-nums[j]
    // 首先找到<= upper-nums[j]个数，再减去<lower-nums[j]
    // 加入答案

    // III. 三指针
    // 首先排序，随着nums[j]变大
    // upper-nums[j]和lower-nums[j]都变小，于是我们用三指针
    // 两个left, right 指向<= upper-nums[j]和<lower-upper-nums[j]的最大元素位置
    // nums[i]就被夹在期间，作差得到答案
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // I.
        // using ll = long long;
        // ll ans = 0;
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper)
        //         {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // II.
        // using ll = long long;
        // sort(nums.begin(), nums.end());
        // ll ans = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
        //     auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
        //     ans += r - l;
        // }
        // return ans;

        // III.
        using ll = long long;
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int left = nums.size(), right = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            while (right && nums[right - 1] > upper - nums[i])
            {
                right--;
            }
            while (left && nums[left - 1] >= lower - nums[i])
            {
                left--;
            }
            ans += min(right, i) - min(left, i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3397 lang=cpp
 * @lcpr version=30204
 *
 * [3397] 执行操作后不同元素的最大数量
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
    // I. 贪心
    // 设nums中的最值为minVal, maxVal, 则操作之后范围变为
    // [minVal-k, maxVal + k], 我们只需要在构造每个元素时
    // 尽可能贪心的寻找最小可使用的元素，以便剩余元素有更大取值空间
    // 就可以构造最多不同的元素
    // 于是，我们首先将nums排序
    // 首先考虑nums[0], 我们让此元素尽可能小a_0 = nums[0] - k
    // 然后考虑nums[1], 需要他与a_0不同，所以取
    //      a_1 = min(max(nums[1] - k, a_0 + 1), nums[1] + k),
    //      如若a_1 > a_0, 说明不同元素数量+1，
    // 之后依次考虑nums[2:n-1], 不断遇上个元素比较，最终统计不同元素数量即可
    // tc: O(nlogn), sc: O(logn)
public:
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num: nums) {
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,3,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4,4]\n1\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3346 lang=cpp
 * @lcpr version=30204
 *
 * [3346] 执行操作后元素的最高频率 I
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
    // I. 排序 + 枚举 + 二分查找
    // 由于可以选定若干元素加0且|numOp| < |nums|
    // 所以实际上可以"至多"选择numOp个元素，使它们[-k, k]范围内调整
    // 考虑枚举目标众数，设nums的最小值和最大值为num_min, num_max
    // 显然有枚举区间[num_min, num_max]
    // 假设每个m_i, 都能给出最多f_i个数变为m_i, 
    // 那么将f_i作为ans_tmp去更新全局ans，
    // 那么如何计算f_i
    // 对每个m_i, 首先考虑约束条件k, 易得只有[m_i - k, m_i + k]
    // 这个范围内的数字才能变为m_i, 若对于nums排序，二分查找找到
    // m_i - k和m_i + k在nums对应的下界元素（第一个>=m_i - k的元素，下标记为l）
    // 和上界元素（最后一个<=m_i + k, 下标记为r)
    // 这意味着任意nums[i], i\in[l, r]都有机会消耗一次操作变为m_i
    // f_i = min(r - l + 1, numOp)
    // 注意如果我们枚举m_i是nums中的某个数，那么不应该在这些数上浪费操作次数
    // 所以我们还要预处理某个m_i的出现次数为count_i, 
    // f_i = min(r - l + 1, numOp + count_i)
    // tc: O(max(nlogn, klogn)), sc: O(n)
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        unordered_map<int, int> numCount;

        int lastNumIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[lastNumIdx]) {
                numCount[nums[lastNumIdx]] = i - lastNumIdx;
                ans = max(ans, i - lastNumIdx);
                lastNumIdx = i;
            }
        }

        numCount[nums[lastNumIdx]] = nums.size() - lastNumIdx;
        ans = max(ans, (int)nums.size() - lastNumIdx);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = leftBound(i - k);
            int r = rightBound(i + k);

            int tempAns;
            if (numCount.count(i)) {
                tempAns = min(r - l + 1, numCount[i] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }
            ans = max(ans, tempAns);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,5]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,11,20,20]\n5\n1\n
// @lcpr case=end

 */


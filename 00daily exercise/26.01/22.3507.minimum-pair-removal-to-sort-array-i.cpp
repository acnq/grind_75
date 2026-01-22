/*
 * @lc app=leetcode.cn id=3507 lang=cpp
 * @lcpr version=30204
 *
 * [3507] 移除最小数对使数组有序 I
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

#include <numeric> // iota
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 模拟
    // 和我的方法类似
    // tc: O(n^2), sc: O(1)
    // II. 模拟链表
    // 因为无论是判断单调性还是寻找最小相邻数对和，都只是线性遍历
    // 我们引入链表令删除变为O(1)
    // tc: O(n^2), sc: O(1)
public:
    bool isInc(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    void op(vector<int>& nums) {
        int n = nums.size();
        int adjsum = INT_MAX, adjidx = 0;
        if (n == 1) {
            return;
        }
        for (int i = 1; i < n; i++) {
            int sum = nums[i] + nums[i - 1];
            if (sum < adjsum) {
                adjsum = sum;
                adjidx = i;
            }
        }
        nums[adjidx - 1] = adjsum;
        nums.erase(nums.begin() + adjidx);
    }

    int minimumPairRemoval(vector<int>& nums) {
        // O.
        // int count = 0;
        // while (!isInc(nums)) {
        //     op(nums);
        //     count++;
        // }
        // return count;
        // I.
        // int count = 0;

        // while (nums.size() > 1) {
        //     bool isAscending = true;
        //     int minSum = std::numeric_limits<int>::max();
        //     int targetIdx = -1;

        //     for (size_t i = 0; i < nums.size() - 1; i++) {
        //         int sum = nums[i] + nums[i + 1];

        //         if (nums[i] > nums[i + 1]) {
        //             isAscending = false;
        //         }

        //         if (sum < minSum) {
        //             minSum = sum;
        //             targetIdx = static_cast<int>(i);
        //         }
        //     }

        //     if (isAscending) {
        //         break;
        //     }

        //     count++;
        //     nums[targetIdx] = minSum;
        //     nums.erase(nums.begin() + targetIdx + 1);
        // }
        // return count;
        // II.
        int n = nums.size();
        std::vector<int> next(n);
        std::iota(next.begin(), next.end(), 1);
        next[n - 1] = -1;
        int count = 0;

        while (n - count > 1) {
            int curr = 0;
            int target = 0;
            int targetAdjSum = nums[target] + nums[next[target]];
            bool isAscending = true;

            while (curr != -1 && next[curr] != -1) {
                if (nums[curr] > nums[next[curr]]) {
                    isAscending = false;
                }

                int currAdjSum = nums[curr] + nums[next[curr]];
                if (currAdjSum < targetAdjSum) {
                    target = curr;
                    targetAdjSum = currAdjSum;
                }
                curr = next[curr];
            }
            if (isAscending) {
                break;
            }
            count++;
            next[target] = next[next[target]];
            nums[target] = targetAdjSum;
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */


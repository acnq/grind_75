/*
 * @lc app=leetcode.cn id=852 lang=cpp
 * @lcpr version=30204
 *
 * [852] 山脉数组的峰顶索引
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
    // I. 枚举
    // 要求用O(logn), 这个O(n)的不一定能过，结果过了，笑死
    // II. 二分查找
    // 
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // I.
        // int n = arr.size();
        // int ans = -1;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (arr[i] > arr[i + 1])
        //     {
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        // II.
        int n = arr.size();
        int left = 1, right = n - 2, ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

 */


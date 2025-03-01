// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30204
 *
 * [704] 二分查找
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
public:
    int search(vector<int>& nums, int target) {
        // int N = nums.size();
        // int begin = 0, end = N - 1, mid = 0;
        // if (nums.size() == 1)
        // {
        //     if (nums[0] == target)
        //     {
        //         return 0;
        //     } else {
        //         return -1;
        //     }
            
        // }
        // if (nums.size() == 2)
        // {
        //     if(nums[0] == target) {
        //         return 0;
        //     } else if(nums[1] == target) {
        //         return 1;
        //     } else {
        //         return -1;
        //     }
        // }
        
        // while (begin < end - 1)
        // {
        //     mid = (begin + end) / 2;
        //     if (nums[begin] == target)
        //     {
        //         return begin;
        //     } else if (nums[end] == target)
        //     {
        //         return end;
        //     } else if(nums[mid] == target) {
        //         return mid;
        //     } else if (target > nums[begin] && target < nums[mid])
        //     {
        //         end = mid;
        //     } else if(target > nums[mid] && target < nums[end]) {
        //         begin = mid;
        //     } else {
        //         return -1;
        //     }
        // }
        // return -1;

        // 上述写法有点太刻奇了
        int N = nums.size();
        int begin = 0, end = N - 1, mid = 0;
        
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            int num = nums[mid];
            if (num == target)
            {
                return mid;
            } else if (num < target)
            {
                begin = mid;
            } else if(num > target)
            {
                end = mid;
            } else {
                return -1;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */


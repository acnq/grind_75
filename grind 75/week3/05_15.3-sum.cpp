/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
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
    // sort before searching
    // 三重循环
    // 某一重枚举到的元素不小于前一重枚举到的
    // 而且要保证和上一次枚举的元素不相等
    // nums.sort();
    // for first = 0 .. n - 1
    //     // 不相同才会枚举
    //     if first == 0 || nums[first] != nums[first - 1] then 
    //         for second = first + 1 .. n - 1
    //             if second == first + 1 or nums[second] != nums[seconde - 1] then 
    //                 for third = seconde + 1 .. n - 1
    //                     if third == second + 1 or nums[third] != nums[third - 1] then 
    //                         // 判断是否有 a + b + c == 0
    //                         check(first, second, third)  
    
    // 注意可以继续优化：
    // 前两重循环枚举到a,b之后，只有唯一的元素有a + b + c = 0，如果第二重往后枚举b' > b, 则c'<c 
    // 所以c' 一定在c左侧，这就是说，我们从小到大枚举b的同时，可以从大到小枚举c, 二三两重可以并列
    // 修改：
    // nums.sort();
    // for first = 0 .. n - 1
    //     // 不相同才会枚举
    // if first == 0 || nums[first] != nums[first - 1] then 
    //     // 第三重循环对应指针
    //     third = n - 1
    //     for second = first + 1 .. n - 1
    //         if second == first + 1 or nums[second] != nums[seconde - 1] then 
    //             // 左移指针，直到 a + b + c 不大于0
    //             while nums[first] + nums[second] + nums[third] > 0 
    //                 third = third - 1
    //             // 判断是否有 a + b + c == 0
    //             check(first, second, third)  
    // 这就是双指针法

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> ans;
        // // 枚举a
        // for (int first = 0; first < n; first++)
        // {
        //     // 需要与上次枚举的数不同
        //     if (first > 0 && nums[first] == nums[first - 1])
        //     {
        //         continue;
        //     }
        //     // c 对应的指针初始指向最右端（大端）
        //     int third = n - 1;
        //     int target = -nums[first];
        //     // 枚举b
        //     for (int second = first + 1; second < n; second++)
        //     {
        //         // 需要与上次枚举的数不同
        //         if (second > first + 1 && nums[second] == nums[second - 1])
        //         {
        //             continue;
        //         }
        //         // 需要保证b在c的左侧
        //         while (second < third && nums[second] + nums[third] > target)
        //         {
        //             --third;
        //         }
        //         // 若指针重合，b后续再增加
        //         // 也不会有a + b + c = 0 && b < c的c了
        //         if (second == third)
        //         {
        //             break;
        //         }
        //         if (nums[second] + nums[third] == target)
        //         {
        //             ans.push_back({nums[first], nums[second], nums[third]});
        //         }
        //     }
        // }
        // return ans;
        // 另一种双指针的写法
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            // 跳过重复的
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 双指针
            // 目标找到nums[l] + nums[r] = - nums[i]
            int l = i + 1, r = nums.size() - 1;
            int target = - nums[i];

            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // 跳过重复
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                } else if (sum < target)
                {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */


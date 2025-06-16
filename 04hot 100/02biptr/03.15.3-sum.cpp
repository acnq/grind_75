// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 这个双指针不是变动前两个，而是变动后两个
        // vector<vector<int>> res;
        // int l = 0, r = nums.size() - 1;
        // int step = 0;
        // while (l < r)
        // {
        //     int tgt = -(nums[l] + nums[r]);
        //     for (int i = l + 1; i < r; i++)
        //     {
        //         if (nums[i] == tgt)
        //         {
        //             vector<int> cur = {nums[l], nums[i], nums[r]};
        //             res.push_back(cur);
        //         }
        //     }
        //     if (step)
        //     {
        //         r--;
        //     } else {
        //         l++;
        //     }
        //     step = !step;
        // }
        // return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // 枚举a
        for (int i = 0; i < n; i++)
        {
            // 需要和上一次枚举的数不相同
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            // k 对应最右侧
            int k = n - 1;
            int tgt = -nums[i];
            // 同时枚举jk
            for (int j = i + 1; j < n; j++)
            {
                // 和上次枚举不同
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                // 保证j在k左侧
                while (j < k && nums[j] + nums[k] > tgt)
                {
                    k--;
                }
                // j==k, 则对此j来说之后的k都不会满足了
                if (j == k)
                {
                    break;  
                }
                if (nums[j] + nums[k] == tgt)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
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


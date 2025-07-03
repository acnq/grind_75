// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30204
 *
 * [560] 和为 K 的子数组
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
    //
public:
    int subarraySum(vector<int>& nums, int k) {
        // 失败经历，不知道能不能Debug出来
        // int n = nums.size();
        // if (n == 1)
        // {
        //     return k == nums[0] ? 1 : 0;
        // }
        
        // int i = 0, j = 0;
        // int res = 0;
        // int cur = 0;
        // while (i < n && j < n)
        // {
        //     while(j < n && cur != k){
        //         cur += nums[j];
        //         j++;
        //     }
        //     res++;
        //     cur -= nums[i];
        //     i++;
        // }
        // return res;

        // I. 暴力枚举区间[i, j] (C++会超时)
        // 首先枚举j, i从j开始枚举到0，这个过程中通过+sum[i]来避免重复计算
        // int res = 0;
        // int n = nums.size();
        // for (int j = 0; j < n; j++)
        // {
        //     int sum = 0;
        //     for (int i = j; i >= 0; i--)
        //     {
        //         sum += nums[i];
        //         if (sum == k)
        //         {
        //             res++;
        //         }
        //     }
            
        // }
        // return res;

        // II. 前缀和哈希
        // pre[i] := sum_{j=0}^i nums[j]
        // pre[i] = pre[i - 1] + nums[i], 
        // sum_{x=i}^j nums[x] == k => pre[i] - pre[j - 1] == k => pre[j - 1] == pre[i] + k
        // 因此，统计[i, j]对的数量，等价于寻找有多少前缀和为pre[i] - k的pre[j]即可
        // 那么，我们以前缀和pre[i]为键，记录pre[i]出现的次数，构建哈希表
        // 从左往右，一边更新mp, 一边计算答案，以i结尾的答案取mp[pre[i] - k]可在O(1)得到
        // 由于pre[i]的记录和计算只和前一项有关，所以pre可以从数组压缩为一个变量，保存pre[i-1]即可
        int res = 0;

        int n = nums.size(), pre = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if (mp.count(pre - k) > 0)
            {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end


// @lcpr case=start
// [-1,-1,1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,0]\n0\n
// @lcpr case=end

// @lcpr case=start
// [6,4,3,1]\n10\n
// @lcpr case=end
 */


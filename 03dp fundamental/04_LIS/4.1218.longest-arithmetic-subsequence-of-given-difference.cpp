// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 * @lcpr version=30204
 *
 * [1218] 最长定差子序列
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
    // ls[i]: 以i结尾的最长定差序列的长度
    // ls[i] = max_{j < i && nums[j] + d = nums[i]} ls[j] + 1; if \exit j s.t. nums[j] + d = ls[i]
    //       = 1; else 
    // 这种O(N^2)的算法会超时
    // I. 优化DP
    // 从左往右遍历arr, 计算arr[i]为结尾的最长等差子序列的长度dp[i]，取最大值，记为答案
    // 计算dp[i]需要再arr[i]左侧找到满足arr[j] = arr[i] - d的元素，将arr[i]加到以arr[j]为结尾的LCDS的末尾
    // 注意到，我们可以取所有满足j < i且arr[j] = arr[i] - d的最大j,
    // (显然，因为dp[i]总是递增的)
    // dp[i] = dp[j] + 1
    // 记arr[i] = v; 那么dp[v] = dp[v - d] + 1, 完全不需要枚举j, 
    // TC & SC: O(N)
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // int n = arr.size();
        // vector<int> ls(n);
        // for(int i = 0; i < n; i++) 
        // {
        //     int tmp_max = 0;
        //     for (int j = 0; j < i; j++)
        //     {
        //         if(arr[j] + difference == arr[i]) 
        //         {
        //             tmp_max = max(ls[j], tmp_max);
        //         }
        //     }
        //     ls[i] = tmp_max + 1;
        // }
        // return *max_element(ls.begin(), ls.end());

        int ans = 0;
        unordered_map<int, int> dp;
        for(int v: arr) 
        {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;

    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=longestSubsequence
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,5,7,8,5,3,4,2,1]\n-2\n
// @lcpr case=end

 */


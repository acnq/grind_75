// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=976 lang=cpp
 * @lcpr version=30204
 *
 * [976] 三角形的最大周长
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
    // I. 排序+贪心
    // 显然，排序过后，对于三边长 a <= b <= c;
    // 能组成的条件只要a + b > c即可
    // 所以与其枚举较小边，我们直接枚举最长边c
    // 选取小于c的最大的两个数字作为a, b; 此时最有可能满足a + b > c
    // 满足也一定是获得最大的周长，显然，如果最大的数字都不满足，那么其他更不可能
    // 所以我们倒序枚举第i个数作为最长边，只看前两个数nums[i - 2], nums[i - 1], 判断二者是否大于A[i],
    // 是则得到最大周长，否则以nums[i]为最长边一定不能组成三角形，i--即可。
    // tc下降到 O(N logN)
public:
    int largestPerimeter(vector<int>& nums) {
        // int maxPer = 0, curPer = 0;
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n - 2; i++) {
        //     for(int j = i + 1; j < n - 1; j++) {
        //         int limit = nums[i] + nums[j];
        //         auto it_lower = lower_bound(nums.begin() + j, nums.end(), limit);
        //         if(it_lower != nums.end() && (int)(it_lower - nums.begin() - 1) <= j) {
        //             continue;
        //         }
        //         int tgt = *(it_lower - 1);
        //         curPer = nums[i] + nums[j] + tgt;
        //         maxPer = max(curPer, maxPer);
        //     }
        // }
        // return maxPer;
        // 方法没问题，但是超时O(N^2logN)

        // I. 
        sort(nums.begin(), nums.end());
        for(int i = (int)nums.size() - 1; i >= 2; i--) {
            if(nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,10]\n
// @lcpr case=end

 */


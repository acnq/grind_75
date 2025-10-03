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
    // I. 贪心+排序
    // 还是根据定理，排序后的三边a<=b<=c能组成三角形的充要条件为
    // c < a + b
    // 要取得最大周长，我们从贪心出发
    // 枚举最长边c, 选出“小于c的最大两个数”作为a, b; 
    // 此时不仅最有可能a + b > c, 且此时的三角形周长最大
    // 我们排序数组，并且倒序枚举第i个数作为最长边
    // 只要看最长边A[i - 2], A[i - 1], 判断二者和是否大于A[i]
    // 如果是则找到最大周长的三角形，返回三者之和即可
    // 如果这两者都做不到，则不存在以此为最长边的三角形，直接枚举下一个i, 
    // 如果对于任何数作为最长边都不存在，返回答案0
    // tc: O(NlogN), sc: O(logN)
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i = (int) nums.size() - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
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


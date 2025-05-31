// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 * @lcpr version=30204
 *
 * [2444] 统计定界子数组的数目
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
    // I. 一次遍历
    // 首先，>maxK 或者 < minK的元素一定不会出现，所以可以依据此将nums分成若干段
    // 然后，对于每个段，记border 为左边界 （为求方便，border+1作为段内第一个元素）
    // 从左到右遍历，设当前位置为i, i左侧第一个=minK的位置为last_min
    // i左侧第一个=maxK位置为last_max, 则此段中，以i为右端点的“定界子数组”共有
    // min(last_min, last_max) - border 个
    // 从maxK, minK中较小的开始到border取，都可以构成一个“定界数组”
    // 递增i, 累加每次的结果即可
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll res = 0;
        int border = -1, last_min = -1, last_max = -1, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(nums[i] < minK || nums[i] > maxK) {
                border = i;
                last_min = -1;
                last_max = -1;
            }
            if(nums[i] == minK)
            {
                last_min = i;
            }
            if(nums[i] == maxK)
            {
                last_max = i;
            }
            if(last_min != -1 && last_max != -1) 
            {
                res += min(last_min, last_max) - border;
            }
            return res;
        }
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countSubarrays
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3,5,2,7,5]\n1\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n1\n1\n
// @lcpr case=end

 */


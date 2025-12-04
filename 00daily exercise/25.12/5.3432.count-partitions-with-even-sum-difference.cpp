// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3432 lang=cpp
 * @lcpr version=30204
 *
 * [3432] 统计元素和差值为偶数的分区方案
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
    // I. 数学
    // 直接用数学，如果数组元素和为sum
    // 若sum为奇数，则划分之后只有可能是一奇一偶（否则sum为偶），差一定是奇数
    // 若sum为偶数，则划分之后或者是双奇数，或者是双偶数，差必然也是偶数
    // 所以sum为偶，返回n-1, 为奇，返回0即可。
public:
    int countPartitions(vector<int>& nums) {
        // 我的答案，可过
        // int left = 0, right = 0;
        // int count = 0;
        // for (int num: nums) {
        //     right += num;
        // }
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     left += nums[i];
        //     right -= nums[i];
        //     if ((right - left) % 2 == 0 ) {
        //         count++;
        //     }
        // }
        // return count;

        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        return sum % 2 == 0 ? nums.size() - 1 : 0;
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countPartitions
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [10,10,3,7,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8]\n
// @lcpr case=end

 */


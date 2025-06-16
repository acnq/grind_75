// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3423 lang=cpp
 * @lcpr version=30204
 *
 * [3423] 循环数组中相邻元素的最大差值
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
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            maxDiff = max(diff, maxDiff);
        }
        return maxDiff;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxAdjacentDistance
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-5,-10,-5]\n
// @lcpr case=end


// @lcpr case=start
// [2,1,0]\n
// @lcpr case=end


 */


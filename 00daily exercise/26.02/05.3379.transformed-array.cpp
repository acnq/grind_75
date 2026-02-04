// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3379 lang=cpp
 * @lcpr version=30204
 *
 * [3379] 转换数组
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
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[i] = nums[(i + nums[i]) % n];
            } else {
                int idx = i + nums[i] > 0 ? (i + nums[i]) % n :  (((i + nums[i]) % n) + n) % n;
                result[i] = nums[idx];
            }
        }
        return result;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=constructTransformedArray
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,-2,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [-1,4,-1]\n
// @lcpr case=end

// @lcpr case=start
// [-10, -10]\n
// @lcpr case=end

 */


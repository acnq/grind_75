// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3740 lang=cpp
 * @lcpr version=30204
 *
 * [3740] 三个相等元素之间的最小距离 I
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
    int minimumDistance(vector<int>& nums) {
        // 秒杀题：8min
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // 这个+1忘了，浪费了点时间
                if (nums[i] == nums[j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[k] == nums[j]) {
                            int len = abs(i - j) + abs(j - k) + abs(k - i);
                            res = min(res, len);
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res ;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumDistance
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


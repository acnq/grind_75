// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 * @lcpr version=30204
 *
 * [2176] 统计数组中相等且可以被整除的数对
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
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countPairs
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,1,2,2,2,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n1\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 * @lcpr version=30204
 *
 * [1822] 数组元素积的符号
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
    int arraySign(vector<int>& nums) {
        // int res = 0;
        // int n = nums.size(), neg_cnt=0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] < 0)
        //     {
        //         neg_cnt++;
        //     } else if (nums[i] > 0)
        //     {
        //     } else {
        //         return 0;
        //     }
        // }
        // return neg_cnt % 2 == 0 ? 1: -1;
        // 官方题解：直接用一个变量记录变号的次数即可
        int sign = 1;
        for(int num: nums) {
            if (num == 0)
            {
                return 0;
            } else if (num < 0)
            {
                sign = -sign;
            }
        }
        return sign;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=arraySign
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [-1,-2,-3,-4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,0,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,-1,1,-1]\n
// @lcpr case=end

 */


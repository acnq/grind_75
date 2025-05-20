// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 * @lcpr version=30204
 *
 * [3355] 零数组变换 I
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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // 模拟？
        // 貌似贪心可解，先试试
        // 超时
        // for(auto& query: queries) {
        //     int li = query[0], ri= query[1];
        //     for (int i = li; i <= ri; i++)
        //     {
        //         nums[i] = max(0, nums[i]-1);
        //     }
        // }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] != 0)
        //     {
        //         return false;
        //     }
        // }
        
        // return true;

        // 用差分数组来做
        int n = nums.size();
        vector<int> diff(n + 1); // 见71行，要+1
        diff[0] = nums[0];
        // 构建差分数组
        for(int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }

        for(auto& query : queries) {
            int li = query[0], ri = query[1];
            diff[li]--;
            diff[ri + 1]++; // 注意是ri + 1, diff[ri]还是可以减到的，不需要处理
            // 和line43-46比较，部分复杂度下降到O(1)
        }

        if (diff[0] > 0)
        {
            return false;
        }

        for (int i = 1; i < n; i++)
        {
            diff[i] += diff[i - 1]; // 注意这个从差分数组恢复原数组的习语
            if (diff[i] > 0)
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=isZeroArray
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,0,1]\n[[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n[[1,3],[0,2]]\n
// @lcpr case=end

 */


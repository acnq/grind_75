// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2012 lang=cpp
 * @lcpr version=30204
 *
 * [2012] 数组美丽值求和
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
    int sumOfBeauties(vector<int>& nums) {
        // int N = nums.size();
        // vector<int> beauty(N, 0);

        // for (int i = 1; i < N - 1; i++)
        // {
        //     if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        //     {
        //         beauty[i] = 1;
        //     }
        
        // 这个部分O(N^2)了，可以通过两次遍历化为O(2 * N) = O(N)
        //     int flag_2 = 0; // is 2-degree beauty or not
        //     for (int j = 0; (j < i) && (flag_2 == 0); j++)
        //     {
        //         for (int k = i + 1; (k < N) && (flag_2 == 0); k++)
        //         {
        //             if (nums[j] >= nums[i] || nums[i] >= nums[k])
        //             {
        //                 flag_2 = 1;
        //             }
        //         }
        //     }
        //     if (flag_2 == 0)
        //     {
        //         beauty[i] = 2;
        //     }
        // }
        
        // int sum = 0;
        // for (int num: beauty)
        // {
        //     sum += num;
        // }
        // return sum;
        // 超时↑
        int N = nums.size();
        vector<int> state(N);
        int pre_max = nums[0];
        // 是否nums[i]严格大于前面的最大值
        for (int i = 1; i < N - 1; i++)
        {
            if (nums[i] > pre_max)
            {
                state[i] = 1; 
                pre_max = nums[i];
            }
        }
        int suf_min = nums[N - 1];
        int res = 0;
        // 是否nums[i]严格小于后面的最小值
        for(int i = N - 2; i > 0; i--) {
            if (state[i] && nums[i] < suf_min)
            {
                res += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            { // 这里顺便判断 1
                res += 1;
            }
            suf_min = min(suf_min, nums[i]);
        }
        return res;

    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=sumOfBeauties
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */


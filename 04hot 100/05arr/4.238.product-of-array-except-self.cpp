// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30204
 *
 * [238] 除自身以外数组的乘积
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
    // I. 前后缀数组
    // 看了提示做出来了
    // II. 空间压缩
    // prefix直接作为ans, suffix通过一次遍历来跟踪变化
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> prefix(n, 1), suffix(n, 1), answer(n, 1);
        // int tmp = 1;
        // for (int i = 0; i < n; i++)
        // {
        //     tmp *= nums[i];
        //     prefix[i] = tmp;
        // }
        // tmp = 1;
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     tmp *= nums[i];
        //     suffix[i] = tmp;
        // }
        // answer[0] = suffix[1];
        // answer[n - 1] = prefix[n - 2];
        // for (int i = 1; i < n - 1; i++)
        // {
        //     answer[i] = prefix[i - 1] * suffix[i + 1];
        // }
        // return answer;
        int n = nums.size();
        vector<int> answer(n, 1);
        answer[0] = 1;

        int tmp = 1;
        for (int i = 0; i < n; i++)
        {
            answer[i] *= tmp;
            tmp *= nums[i];
        }
        // 这时的answer相当于上解中的prefix[n-1]

        // suffix: 右边所有元素的乘积
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // 索引i左边的乘积为answer[i], 右边为suffix
            answer[i] = answer[i] * suffix;
            // suffix 遍历自乘即可
            suffix *= nums[i];
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */


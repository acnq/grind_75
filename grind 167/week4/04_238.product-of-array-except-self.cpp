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
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // I. 左右乘积列表
        // algo:
        // init 空数组L, R, L[i]表示i左侧所有数字的乘积，R[i]则为右侧
        // 两边循环填充，L[0] = 1, L[i] = L[i - 1] * nums[i - 1],
        // R[N - 1] = 1, R[i] = R[i + 1] * nums[i + 1]
        // R, L 填完的时候，乘积p[i] = L[i] * R[i]
        // int length = nums.size();

        // // L, R: 左右两侧乘积列表
        // vector<int> L(length, 0), R(length, 0);
        // vector<int> answer(length);

        // // L[i]: i左侧元素乘积
        // L[0] = 1;
        // for (int i = 1; i < length; i++)
        // {
        //     L[i] = nums[i - 1] * L[i - 1];
        // }
        
        // // R[i]: i右侧元素乘积
        // R[length - 1] = 1;
        // for (int i = length - 2; i >= 0; i--)
        // {
        //     R[i] = nums[i + 1] * R[i + 1];
        // }
        
        // // ans[i] = L[i] * R[i]
        // for (int i = 0; i < length; i++)
        // {
        //     answer[i] = L[i] * R[i];
        // }
        
        // return answer;

        // II. 减少空间
        // 将answer[i] 作为L[i]
        // 不构造R, 用一个遍历跟踪右侧元素乘积
        // i = N-1,..., 0: answer[i] = answer[i] * R, R = nums[i]
        int N = nums.size();
        vector<int> answer(N);

        // answer[i]: i 左侧所有元素的乘积
        answer[0] = 1;
        for (int i = 1; i < N; i++)
        {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        
        // R 为右侧元素乘积
        int R = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            // i左侧 乘积为answer[i], 右侧为R
            answer[i] = answer[i] * R;
            // R更新
            R *= nums[i];
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


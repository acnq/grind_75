/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
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
    // 懒得想进阶了

    // II. 双指针
    // 我们这么思考：
    // 如若数组全为非负，那么平方后保序，如若全为负数，那么平方后反序
    // 所以我们首先要找到nums的正负分界线neg，然后进行“归并”
    // 因为，平方后nums[0:neg]递减，nums[(neg+1):(n-1)]递增
    // 二者均有序，于是需要归并排序。双指针分别指向neg和neg+1，比较大小，
    // 较小的入答案并移动指针，直到某一指针到边界，另一指针的余量全部入答案

    // III. 双指针 II.
    // 我们又何必找到区分正负数的位置呢？
    // 平方后，原数组一定是两头大，中间小，我们直接用两个指针指向0和n-1
    // 每次比较二者，较大者逆序如答案即可，甚至不需要处理某一指针遇到边界的情况

public:
    vector<int> sortedSquares(vector<int>& nums) {
        // vector<int> res;
        // for(int num: nums) {
        //     res.push_back(num * num);
        // }
        // sort(res.begin(), res.end());
        // return res;
        
        // II.
        // int n = nums.size();
        // int neg = -1;
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] < 0) {
        //         neg = i;
        //     } else {
        //         break;
        //     }
        // }
        // vector<int> ans;
        // int i = neg, j = neg + 1;
        // while(i >= 0 || j < n) {
        //     if(i < 0) {
        //         ans.push_back(nums[j] * nums[j]);
        //         j++;
        //     } else if(j == n) {
        //         ans.push_back(nums[i] * nums[i]);
        //         i--;
        //     }
        //     else if(nums[i] * nums[i] < nums[j] * nums[j]) {
        //         ans.push_back(nums[i] * nums[i]);
        //         i--;
        //     } else {
        //         ans.push_back(nums[j] * nums[j]);
        //         j++;
        //     }
        // }
        // return ans;

        // III.
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if(nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                i++;
            } else {
                ans[pos] = nums[j] * nums[j];
                j--;
            }
            pos--;
        }
        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */


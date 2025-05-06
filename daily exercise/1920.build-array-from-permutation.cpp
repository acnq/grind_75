/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 * @lcpr version=30204
 *
 * [1920] 基于排列构建数组
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
    // I. naive
    // 可行

    // II. 原地构造
    // nums每个元素nums[i]能同时存储当前nums[i]和最终值nums[nums[i]]
    // 因为nums[i] \in [0, 999]
    // 用‘1000’进制来表示，除以1000的商数表示最终值，余数表示当前值
    // 遍历nums, 计算终值，乘1000加上，
    // 再次遍历，每个元素除以1000保留商数，即为结果
    
    // 细节：计算nums[i]的最终值，需要修改前的nums[nums[i]]的值，
    // 而nums中nums[i]的元素可能已经被修改了，因此需要取下标得到的值
    // 对1000取模
public:
    vector<int> buildArray(vector<int>& nums) {
        // I
        // vector<int> res;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     res.push_back(nums[nums[i]]);
        // }
        // return res;

        // II.
        int n = nums.size();
        // 第一次遍历编码最终值
        for(int i = 0; i < n; i++) {
            nums[i] += 1000 * (nums[nums[i]] % 1000); 
            //不要直接*，取余数
        }
        // 第二次遍历修改最终值
        for(int i = 0; i < n; i++) {
            nums[i] /= 1000;
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,2,1,5,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,0,1,2,3,4]\n
// @lcpr case=end

 */


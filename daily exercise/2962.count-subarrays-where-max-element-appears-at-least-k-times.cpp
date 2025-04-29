/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 * @lcpr version=30204
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
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
    // I. mx: nums 最大元素
    // 显然，子数组arr包含k个mx, 则所有包含arr的其他子数组也满足条件
    // 用滑动窗口
    // pos[i], 第i个mx出现的位置，两个指针left, right（在pos上滑动）
    // 对于每个left. 得到right = left + k - 1, 
    // 
    // 左端点位于(pos[left - 1], pos[left]], 右端点位于[pos[right], n]的子组
    // 都属于当前统计的花窗的贡献，所以共有(pos[left] - pos[left - 1]) * (n - pos[right])个
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> pos{-1};

        for(int i = 0; i < n; i++) {
            if(nums[i] == mx) {
                pos.push_back(i);
            } // 网络出了点问题？
        }

        int left = 1, right = k;
        long long ans = 0;
        while(right < pos.size()) {
            ans += (pos[left] - pos[left - 1]) * (n - pos[right]);
            left++;
            right++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,1]\n3\n
// @lcpr case=end

 */


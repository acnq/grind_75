/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=30204
 *
 * [525] 连续数组
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
    // I. 前缀和+哈希表
    // 将0看做-1，问题转化为“求最长连续子串，元素和为0”
    // 0->-1之后的数组称为newNums, prefixSum[i]: newNums[0:i]的前缀和
    // 则newNums[j+1:k]的元素和为prefixSum[k] - prefixSum[j]
    // 当prefixSum[k] - prefixSum[j] = 0, 得到长度为k - j的子数组元素和为0。
    // 实现中，只需要维护变量counter存储newNums的前缀和即可，
    // 遍历数组，遇到1counter++, 遇到0counter--, 用哈希表存储每个前缀和首次出现的下标
    // 规定空前缀结束下标为-1，故哈希表首先存入(0, -1), 于是每个下标i, 进行操作：
    // 1. counter值哈希表中已经存在，取出counter在哈希表中对应的下标prevIdx, 
    //    这时nums从preIdx + 1到i的子串有相同数量的0和1，长度为i - preIdx, 以此更新最长连续子串长
    // 2. counter值不存在，加入即可。
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> mp;
        int counter = 0;
        mp[counter] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num == 1)
            {
                counter++;
            } else
            {
                counter--;
            }
            if (mp.count(counter))
            {
                int prevIdx = mp[counter];
                maxLen = max(maxLen, i - prevIdx);
            } else
            {
                mp[counter] = i;
            }
        }
        return maxLen;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,1,1,0,0,0]\n
// @lcpr case=end

 */


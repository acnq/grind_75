/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 * @lcpr version=30204
 *
 * [2044] 统计按位或能得到最大值的子集数目
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
    // I. 位运算
    // 非空子集数目有2^n - 1个，用长度为n比特的整数表示不同的自己
    // 穷举每种整数对应的子集取舍所得的子集按位或的值，计算最大值和子集个数即可
    // tc: O(n 2^n), sc: O(1)
    // II. 回溯
    // 注意到每个长度为n比特的状态的按位或的值，都可以在长度为n-1比特的状态的按位或的值上计算出来
    // 定义搜索函数，pos:当前下标，orVal: 此下标之前的某个自己按位或的值，
    // 这样就可以保存子集按位或的值的信息，根据当前元素的选择与否更新orVal, 搜索到最后位置更新最大值和个数即可
public:
    // II.
    vector<int> nums;
    int maxOr, cnt;
    void dfs(int pos, int orVal) {
        if (pos == nums.size()) {
            if (orVal > maxOr) {
                maxOr = orVal;
                cnt = 1;
            } else if (orVal == maxOr) {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal | nums[pos]);
        dfs(pos + 1, orVal);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // I.
        // int n = nums.size(), maxVal = 0, cnt = 0, stateNum = 1 << n;
        // for (int i = 0; i < stateNum; i++) {
        //     int cur = 0; // i对应元素取舍的对应的子集, cur对应按位或的零食变量
        //     for (int j = 0; j < n; j++) {
        //         if (((i >> j) & 1) == 1) {// 注意这里取得取舍情况的写法
        //             cur |= nums[j];
        //         }
        //     }
        //     if (cur == maxVal) {
        //         cnt++;
        //     } else if (cur > maxVal) {
        //         maxVal = cur;
        //         cnt = 1;
        //     }
        // }
        // return cnt;

        // II.
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,5]\n
// @lcpr case=end

 */


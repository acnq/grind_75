// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 * @lcpr version=30204
 *
 * [2540] 最小公共值
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
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // O. 我的方法
        // unordered_set<int> u_set(nums1.begin(), nums1.end());
        // int res = INT_MAX;
        // for (int i = 0; i < nums2.size(); i++) {
        //     if (u_set.count(nums2[i]) != 0) {
        //         res = min(i, res);
        //     }
        // }
        // if (res != INT_MAX) {
        //     return nums2[res];
        // } else {
        //     return -1;
        // }

        // I. 二分
        // 从一个二分查找另一个数组中的元素是否存在
        // tc: O(nlogm), sc: O(1)
        // 
        // for (int num: nums1) {
        //     auto it = lower_bound(nums2.begin(), nums2.end(), num);
        //     if (it != nums2.end() && num == *it) {
        //         return num;
        //     }
        // }
        // return -1;

        // II. 哈希
        // 和我的方法类似，
        // tc: O(n + m), sc: O(n)
        // 
        // unordered_map<int, int> mp;
        // for (int num: nums1) {
        //     mp[num]++;
        // }
        // for (int num:nums2) {
        //     if (mp[num]) {
        //         return num;
        //     }
        // }
        // return -1;

        // III. 双指针
        // 固定nums1[i]， nums2中所有小于他的元素都不可能是答案
        // 只有nums2[j] >= nums1[i]时，比较是否是=，是则返回
        // 不是就后移i, 直到找到
        // tc: O(n + m), sc: O(1)
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getCommon
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3]\n[2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,6]\n[2,3,4,5]\n
// @lcpr case=end

 */


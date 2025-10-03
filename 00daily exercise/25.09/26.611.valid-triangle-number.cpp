/*
 * @lc app=leetcode.cn id=611 lang=cpp
 * @lcpr version=30204
 *
 * [611] 有效三角形的个数
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
    // I. 排序+二分查找
    // 对三角形三遍升序排序，s.t. a <= b <= c
    // 则只需要保证a + b > c， 三角形就能构成
    // 于是，我们将数组nums升序排序，随后使用二重循环枚举a, b
    // a = nums[i], b = nums[j] (i < j)
    // c < nums[i] + nums[j]即可，我们需要在
    // [j + 1, n - 1]范围内使用二分查找找出最大的nums[k] < nums[i] + nums[j]
    // 如此[j + 1, k]范围内的下标都可以作为c的下标，范围长度k - j加入答案
    // 如果nums包含0咋办？
    // 没关系，因为如果a,b有一位0，则nums[i]首先为0（排序）
    // c < nums[i] + nums[j] = nums[j], 则[j + 1, n - 1]范围内元素一定都大于nums[j]
    // 所以二分查找失败，k = j, k - j = 0.
    // tc: O(n^2 logn), sc: O(logn) (排序所需要的栈空间)

    // II. 排序+双指针
    // a =nums[i], b = nums[j], 记最大的满足nums[k] < nums[i] + nums[j]
    // 的k为k_{i,j}, 固定i, j递增，不等式右侧的nums只和也递增，所以k_{i,j}也递增
    // 所以j,k看做两个同向移动的指针, 基于I完成如下优化：
    // 1. 一重循环枚举i, 双指针j,k初始化为i;
    // 2. 每次j右移（j <- j + 1), 不断尝试右移k，找到最大的满足不等式的k
    //    将max(k - j, 0)累加入答案
    // tc: O(n^2), sc: O(logn)
public:
    int triangleNumber(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int left = j + 1, right = n - 1, k = j;
        //         while (left <= right) {
        //             int mid = (left + right) / 2;
        //             if (nums[mid] < nums[i] + nums[j]) {
        //                 k = mid;
        //                 left = mid + 1;
        //             } else {
        //                 right = mid - 1;
        //             }
        //         }
        //         ans += k - j; 
        //     }
        // }
        // return ans;

        // II.
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    k++;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,4]\n
// @lcpr case=end

 */


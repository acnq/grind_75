/*
 * @lc app=leetcode.cn id=287 lang=cpp
 * @lcpr version=30204
 *
 * [287] 寻找重复数
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
    // I. 二分查找
    // cnt[i]: nums数组中小于等于i的数有多少个；假设我们重复的数字是target
    // 那么[1, target - 1]所有的数满足cnt[i] <= i, [target, n]所有数满足cnt[i] > i
    // 这种半单调性可以直接用二分查找来实现
    // 不过考虑一个问题，如果target出现了三次以上，那么有些数不会出现在nums数组中
    // 而target替换了这些数，那会造成影响么？
    // 不会，因为如果替换的数i<target, 这只是让[i, target - 1]的cnt--;
    // 如果替换的数j >= target, 这只是让[target, j - 1]的cnt++, 这不会破坏单调性
    // tc: O(nlogn); sc: O(1)

    // II. 二进制
    // 我们把nums每个数字展开为二进制数，考虑第i位，记nums数组中二进制展开后第i位为1的数有x
    // [1, n]这n个数二进制展开后第i位为1的数有y个，那么重复数第i位为1当前仅当x > y
    // tc: O(nlogn); sc: O(1)

    // III. 快慢指针
    // 对nums数组建图，每个位置i连一条i -> nums[i]的边，因为存在重复数字target, target这个位置
    // 一定有起码两条指向它的边，于是整张图存在欢，而target就是环的入口，于是问题就等价于T142.
    // 那么就可以设置快慢指针slow和fast, slow走一步同时fast走两步，两个指针有环的情况下一定相遇
    // 此时slow放置到起点，两个指针再每次移动一步，再次相遇点就是答案
    // tc: O(n); sc: O(1)
public:
    int findDuplicate(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // int l = 1, r = n - 1, ans = -1;
        // while (l <= r)
        // {
        //     int mid = (l + r) >> 1;
        //     int cnt = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         cnt += nums[i] <= mid;
        //     }
        //     if (cnt <= mid)
        //     {
        //         l = mid + 1;
        //     } else
        //     {
        //         r = mid - 1;
        //         ans = mid;
        //     }
        // }
        // return ans;      

        // II.
        // int n = nums.size(), ans = 0;
        // // 确定二进制下最高位是多少
        // int bit_max = 31;
        // while (!((n - 1) >> bit_max))
        // {
        //     bit_max -= 1;
        // }
        // for (int bit = 0; bit <= bit_max; bit++)
        // {
        //     int x = 0, y = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (nums[i] & (1 << bit))
        //         {
        //             x++;
        //         }
        //         if (i >= 1 && (i & (1 << bit)))
        //         {
        //             y++;
        //         }
        //     }
        //     if (x > y)
        //     {
        //         ans |= 1 << bit;
        //     }
        // }
        // return ans;

        // III.
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */


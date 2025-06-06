// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30204
 *
 * [300] 最长递增子序列
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

// Longest Increasing Subsequence: abbr. LIS 
class Solution {
    // s[i]: 以i结尾的LIS长度
    // s[i] = max_{s[i] >= s[j]}{s[j]} + 1;
    // I. 动态规划
    // 如上，TC: O(n^2); SC: O(n)
    // II. 贪心 + 二分查找
    // 在限定长度的情况下，“最长的上升子序列必然是上升最慢的“
    //  维护数组d[i]: 长度为i的最长上升子序列的末尾元素的最小值，len记录目前LIS序列的长度
    //  len := 1 (init), d[1] = nums[0]
    //  d[i]必然是关于i单调递增（显然）
    //  依次遍历nums中每个元素，更新d和len, nums[i] > d[len], 加入元素，len++;
    //  否则d[1:len]找到d[i - 1] < nums[j] < d[i]的下标i, d[i] = nums[j]
    //  这样，我们可以把“找到XXX"的部分用二分查找优化，这样O(N^2)就能O(N log N)
    // 
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> lis(n);
        // for(int i = 0; i < n; i++) {
        //     int tmp_max = 0;
        //     for(int j = 0; j < i; j++) {
        //         if(nums[i] > nums[j]) {
        //             tmp_max = max(tmp_max, lis[j]);
        //         }
        //     }
        //     lis[i] = tmp_max + 1;
        // }
        // return *max_element(lis.begin(), lis.end());
        // 加上debug大约40min, 初见通

        int len = 1, n = (int)nums.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > d[len])
            {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; 
                // // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end


// @lcpr case=start
// [1,3,6,7,9,4,10,5,6]\n
// @lcpr case=end
 */


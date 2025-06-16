// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=673 lang=cpp
 * @lcpr version=30204
 *
 * [673] 最长递增子序列的个数
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
    // s[i]: 以i结尾的LIS长度; 
    // cnt[i]: 以i结尾且长为s[i]的个数，i.e. s[i] - 1在s[:i]中出现的个数
    // s[i] = max_{s[i] >= s[j]}{s[j]} + 1;
    // cnt[i] = \sum_{j=0}^i cnt[j] (s[j] = s[i] - 1);
    // 答案： 最大s[i]出现的cnt[i]之和 \sum_{j=1, s[i] = max_j s[j]}^i cnt[i]
    // 思路正确 (*^▽^*)
    // 官方写法：
    // I. DP
    // 同时处理s和cnt。
    // II. 贪心+前缀和+二分查找
    // 根据T300，d扩展为二维数组，d[i]：所有能成为长度为i的最长上升子序列的末尾元素的值
    // 具体来说，更新d[i] = nums[j]这一操作替换成将nums[j]置于d[i]的末尾，
    // 于是d[i]就保留了历史信息，而且d[i]的元素有序（递减）
    // 
    // 再定义二维数组cnt, cnt[i][j]: 以d[i][j]为结尾的最长上升子序列的个数
    // cnt[i][j]的计算要将所有满足d[i - 1][k] < d[i][j]和cnt[i - 1][k]累加到cnt[i][j]
    // ans: cnt[maxlen]的所有元素和
    // 这样，寻找最小的满足d[i - 1][k] < d[i][j]的下标k可以二分
    // 另一处改进是cnt改为前缀和，并在开头填上0
    // d[i][j]对应的最长上升子序列的个数就是cnt[i - 1][-1] - cnt[i - 1][k]
    // -1: 表示末尾
public:
    int binarySearch(int n, function<bool(int)> f) {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (f(mid))
            {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int findNumberOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> lis(n);
        // vector<int> cnt(n);
        // for(int i = 0; i < n; i++) {
        //     int tmp_max = 0;
        //     for(int j = 0; j < i; j++) {
        //         if(nums[j] < nums[i]) {
        //             tmp_max = max(tmp_max, lis[j]);
        //         }
        //     }
        //     lis[i] = tmp_max + 1;
        // }
        // cnt[0] = 1;
        // for (int i = 0; i < n; i++)
        // {
        //     int mod = 0;
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (lis[j] == lis[i] - 1 && nums[j] < nums[i])
        //         {
        //             cnt[i] += cnt[j];
        //             mod = 1;
        //         }
        //     }
        //     if (mod == 0)
        //     {
        //         cnt[i] = 1;
        //     }
        // }
        
        // int maxlis = *max_element(lis.begin(), lis.end());
        // int maxLISCnt = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (lis[i] == maxlis)
        //     {
        //         maxLISCnt += cnt[i];
        //     }
            
        // }

        // return maxLISCnt;
        // 初见通，但是连上Debug想了40分钟，有点慢

        // I.
        // int n = nums.size(), maxlen = 0, ans = 0;
        // vector<int> lis(n), cnt(n);
        // for (int i = 0; i < n; i++)
        // {
        //     lis[i] = 1;
        //     cnt[i] = 1;
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (nums[i] > nums[j])
        //         {
        //             if (lis[j] + 1 > lis[i])
        //             {
        //                 lis[i] = lis[j] + 1;
        //                 cnt[i] = cnt[j]; // 重置计数
        //             } else if (lis[j] + 1 == lis[i])
        //             {
        //                 cnt[i] += cnt[j];
        //             }
        //         }
        //     }
        //     if (lis[i] > maxlen)
        //     {
        //         maxlen = lis[i];
        //         ans = cnt[i];
        //     } else if (lis[i] == maxlen)
        //     {
        //         ans += cnt[i];
        //     }
        // }
        // return ans;
        vector<vector<int>> d, cnt;
        for(int v: nums) {
            int i = binarySearch(d.size(), [&](int i) {return d[i].back() >= v;});
            int c = 1;
            if (i > 0)
            {
                int k = binarySearch(d[i - 1].size(), [&](int k){ return d[i - 1][k] < v;});
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size())
            {
                d.push_back({v});
                cnt.push_back({0, c});
            } else {
                d[i].push_back(v);
                cnt[i].push_back((cnt[i].back() + c));
            }
        }
        return cnt.back().back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,3,5,4,7,2]\n
// @lcpr case=end



 */


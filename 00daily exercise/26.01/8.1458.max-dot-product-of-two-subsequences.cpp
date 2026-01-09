/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 * @lcpr version=30204
 *
 * [1458] 两个子序列的最大点积
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
    // I. DP
    // f[i][j]: 仅数组nums1的前i个元素和nums2前j个元素时
    //          可以得到的两个长度相同的非空子序列的最大点积
    // 考虑每个数组的最后一个元素，
    //     如果选择了nums1[i], nums[j], 对答案的贡献为x_{ij} = nums1[i] * nums2[j]
    //          在此基础上，如果选择前面的数字对，则最大点积为f[i-1][j-1] + x_{ij}
    //                        不选择         ， x_{ij}
    //        不选择，由于他们各自是对应数组的最后一个元素，
    //        故则nums1[i]和nums2[j]至少有一个不会与其他的任意元素形成点积
    //              忽略nums1[i], 最大点积：f[i - 1][j]
    //              忽略nums2[j], 最大点积：f[i][j - 1]
    //              忽略两个，              f[i - 1][j - 1]
    // f[i][j] = max(f[i - 1][j - 1] + x_{ij}, x_{ij}, f[i - 1][j], f[i][j - 1])
    // 返回f[m - 1][n - 1]即可，m = len(nums1), n = len(nums2)
    // tc = sc: O(mn)
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> f(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int xij = nums1[i] * nums2[j];
                f[i][j] = xij;
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                }
                if (i > 0 && j > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + xij);
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,-2,5]\n[3,0,-6]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2]\n[2,-6,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n[1,1]\n
// @lcpr case=end

 */


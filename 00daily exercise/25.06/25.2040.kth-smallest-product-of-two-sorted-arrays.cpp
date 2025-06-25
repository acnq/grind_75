/*
 * @lc app=leetcode.cn id=2040 lang=cpp
 * @lcpr version=30204
 *
 * [2040] 两个有序数组的第 K 小乘积
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
    // I. 二分 + 二分
    // 在乘积的取值区间上进行二分查找，令当前二分值为v,
    // 我们要找到<=v的乘积数目count, 如果count < k, 则二分值偏小，否则偏大
    // 找到<=v的乘积数目Count同样可以使用二分来解决，依次枚举nums1的元素x_1,
    // x_1 >= 0, 那么nums_2[j] * x_1递增，可以二分查找<=v的数目
    // x_1 < 0, 那么nums_2[j] * x_2递减，二分查找>v的数目t, <=v的乘积数目为n_2 - t
    // (n_2 = |nums_2|), tc: O(n_1 log (n _2) log C) C = 2 * 10 ^{10} + 1， 乘积的值域

    // II.
    // 类似于I, 但我们直接将nums_1和nums_2划分为值大于0或小于0的区间[0, pos_1), [pos_1, n_1);
    // [0, pos_2), [pos_2, n_2)， 以[0, pos_1)和[0, pos_2)的乘积为例，q(i, j) = nums_1[i] * nums_2[j]
    // q依i,j递减，从矩阵右上角遍历，初始化i_1 = 0, i_2 = pos_2 - 1
    // q(i_1, i_2) > v, 那么(i_1, i_2)所在行剩余元素>v, i_1++
    // q(i_1, i_2) <= v, 那么(i_1, i_2)所在列<=v, i_2--
public:
    // I.
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x1 >= 0 && nums2[mid] * x1 <= v || x1 < 0 && nums2[mid] * x1 > v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // I.
        // int n1 = nums1.size();
        // long long left = -1e10, right = 1e10;
        // while (left <= right) {
        //     long long mid = (left + right) / 2;
        //     long long count = 0;
        //     for (int i = 0; i < n1; i++) {
        //         count += f(nums2, nums1[i], mid);
        //     }
        //     if (count < k) {
        //         left = mid + 1;
        //     } else {
        //         right = mid - 1;
        //     }
        // }
        // return left;

        // II. 
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            for (int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2; ) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            for (int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            for (int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5]\n[3,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,0,3]\n[2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-2,-1,0,1,2]\n[-3,-1,2,4,5]\n3\n
// @lcpr case=end

 */


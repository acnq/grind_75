/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
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
    // 转化为求两个有序数组AB中第k小的数，k或者为(m + n) / 2或者为(m + n) / 2 + 1;
    // 比较A[k/2-1]和B[k/2-1], 因为二者之前至多分别有A[0:(k/2-2)],B[0:(k/2-2)]个元素
    // 各k/2 - 1个元素，选取二者中的较小值后，总共最多只有(k/2 - 1) + (k/2 - 1) <= k - 2个元素
    // 他就不能是第k小的元素
    // 归纳为三种情况：
    // 1. A[k/2-1] =< B[k/2-1]：比A[k/2-1]小的数最多k-2个，所以A[0:(k/2-1)]都不可能是第k个元，全部排除
    // 2. A[k/2-1] > B[k/2-1]: 排除B[0:(k/2-1)]
    // 这样比较之后排除k/2个元素，查找范围缩小一半，在新数组上继续二分，减小k, 排除所有不大于第k小的数
    // 特判的情况有3：
    //  1. A[k/2-1]或B[k/2-1]越界，就需要求越界数组的最后元素，这时必须根据排除数的个数（数组实际长度）排除，而非k=k/2
    //  2. 一个数组为空，则该数组全体被排除，直接返回另一个数组中第k小的元素
    //  3. k=1, 返回两个数组首项的较小值即可。
    // tc: O(log(m + n)); sc: O(1)

    // II. 数组分划
    // 还有高手？有的兄弟有的，我们有tc: O(log(min(m, n))); sc: O(1)的算法
    // 中位数的意义：把数组分划为两部分，其中一部分每个元素都小于另个部分
    // 假设我们把A划分成了两部分A1, A2, 长度分别为i, m-i, 同样B被划分为B1,B2, 长度j, n-j
    // A1,B1放一起，A2,B2放一起，分别命名为P1, P2,
    // 当len(A) + len(B)为偶数，则正确划分就是要保证
    //      len(P1) = len(P2) && max(P1) <= min(P2)
    //      此时，ans = (max(P1) + min(P2)) / 2
    // 当len(A) + len(B)为奇数，则正确划分就是要保证
    //      len(P1) = len(P2) + 1 && max(P1) <= min(P2)
    //      此时，ans = max(P1)
    // 那么如何确保这两个条件呢？
    // 对于长度，只需要i + j = m - i + n - j(m + n为偶数)，i + j = m - i + n - j + 1(m + n为奇数)
    //  整理后两式可统一为i + j = (m + n + 1) / 2 (整数除法)
    // 对于最值，定义A为较短的那一段，i.e. m <= n, \forall i \in [0, m], 这时j = (m + n + 1) / 2 - i \in [0, n] （长度条件）
    //  于是B[j - 1] \leq A[i] && A[i - 1] \leq B[j]就保证了前一部分的最小值<=后一部分的最大值 
    // A[-1]=B[-1]=-\infin, A[m]=B[n]=\infi， 不在前一部分对应负无穷，不会对P1的最大值产生影响，后一部分对应正无穷类似，不影响P2最小值
    // 为什么这就保证了呢？
    // 我们说明，找到i \in [0, m], s.t. B[j - 1] \leq A[i] && A[i - 1] \leq B[j] 
    // 等价于，找到最大i* \in [0, m], s.t. A[i* - 1] \leq B[j]
    // 显然i递增=>A[i-1]递增，B[j]递减（长度约束，j = (m + n + 1)/2 - i), 故最大值i*存在
    // i取到最大i*，则i* + 1不满足，i* + 1带入A[i* - 1] \leq B[j] 有A[i*] > B[j - 1]， 等价于条件的第二项。
    // 于是我们在[0, m]上二分搜索i即可，找到最大的A[i - 1] \leq B[j]的值
public:
    // I.
    int getKthElem(const vector<int>& A, const vector<int>& B, int k){
        int m = A.size();
        int n = B.size();
        int idx1 = 0, idx2 = 0;

        while (true)
        {
            if (idx1 == m)
            { // A全部被排除
                return B[idx2 + k - 1];
            }
            
            if (idx2 == n)
            { // B 全部被排除
                return A[idx1 + k - 1];
            }
            if (k == 1)
            {
                return min(A[idx1], B[idx2]);
            }
            
            int nIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int nIdx2 = min(idx2 + k / 2 - 1, n - 1);
            int pivot1 = A[nIdx1];
            int pivot2 = B[nIdx2];
            if (pivot1 <= pivot2)
            {
                k -= nIdx1 - idx1 + 1;
                idx1 = nIdx1 + 1;
            } else {
                k -= nIdx2 - idx2 + 1;
                idx2 = nIdx2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // I.
        // int totLen = nums1.size() + nums2.size();
        // if (totLen % 2 == 1)
        // {
        //     return getKthElem(nums1, nums2, (totLen + 1) / 2);
        // } else
        // {
        //     return (getKthElem(nums1, nums2, totLen / 2) + getKthElem(nums1, nums2, totLen / 2 + 1)) / 2.0;
        // }

        // II.
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
            // 确保A是短的那个
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int med1 = 0, med2 = 0;
        // med1: 前一部分最大值，med2: 后一部分最小值

        while (left <= right)
        { // 在left:right上二分搜索i
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j)
            {
                med1 = max(nums_im1, nums_jm1);
                med2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (med1 + med2) / 2.0 : med1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */


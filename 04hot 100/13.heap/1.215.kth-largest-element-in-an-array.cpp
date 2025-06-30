/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30204
 *
 * [215] 数组中的第K个最大元素
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
    // I. 基于快排的选择方案
    // 回忆快排：
    //  1. 分解：将数组a[l:r]划分为两部分a[l:(q-1)], a[(q+1):r], 
    //           互相交换，使得令前者每个部分<=a[q], 后者>=a[q]
    //  2. 递归：递归调用此过程，对两部分子数组继续排序
    //  3. 合并：因为子数组在分解时已经交换，所以不需要额外的合并
    // 我们发现，快排的每次分划一定可以确定一个元素的最终位置：主元a[q]在q
    // 所以，只要某次分划q为倒数第k个下标，就得答案，而另外两部分是否有序，我们不关心
    // 这样一来我们如此改进快排：
    //  划分得到的q正好是我们下标，就返回a[q]; 否则，如果q比目标小，我们递归右子区间，否则左子区间
    //  这叫做“快速选择算法”
    // 引入随机化之后，期望tc为O(n);sc:O(logn)[递归栈]

    // II. 基于堆排序的选择方案
    // 建立大根堆，然后做k-1次删除操作之后，堆顶就是答案
    // tc: O(n + klogn), sc: O(log n)
public:
    // I.
    // int quickSelect(vector<int>& nums, int l, int r, int k) {
    //     if (l == r)
    //     {
    //         return nums[k];
    //     }
    //     int partit = nums[l], i = l - 1, j = r + 1;
    //     while (i < j)
    //     {
    //         do
    //         {
    //             i++;
    //         } while (nums[i] < partit);
    //         do
    //         {
    //             j--;
    //         } while (nums[j] > partit);
    //         if (i < j)
    //         {
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    //     if (k <= j)
    //     {
    //         return quickSelect(nums, l, j, k);
    //     } else
    //     {
    //         return quickSelect(nums, j + 1, r, k);
    //     }
    // }

    // II.
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest])
        {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }
    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; i--)
        {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // I.
        // int n = nums.size();
        // return quickSelect(nums, 0, n - 1, n - k);

        // II.
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */


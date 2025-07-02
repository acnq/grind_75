/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=30204
 *
 * [658] 找到 K 个最接近的元素
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
    // I. 排序
    // 按照更接近的定义排序，a比b更接近x, a在前，然后返回前k个元素即可
    // tc: O(n logn); sc: O(logn)

    // II. 二分查找+双指针
    // 二分查找left, right, 使得[0, left]都<x, 后一部分[right, n - 1]都>=x
    // left, right指向的是各自部分最接近x的元素，
    // 所以我们可以通过比较left, right指向的元素获取整体最接近x的元素，
    // 若x - arr[left] <= arr[right] - x, 那么left--,否则right++。
    // 如果left, right已经越界，那么不考虑对应部分的元素，
    // 最后[left + 1, right - 1]元素就是我们所有要获得的结果。
    // tc: O(logn + k); sc: O(1)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // I.
        // sort(arr.begin(), arr.end(), [x](int a, int b)->bool{
        //     return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
        // });
        // sort(arr.begin(), arr.begin() + k);
        // return vector<int>(arr.begin(), arr.begin() + k);

        // II.
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--)
        {
            if (left < 0)
            {
                right++;
            } else if (right >= arr.size())
            {
                left--;
            } else if (x - arr[left] <= arr[right] - x)
            {
                left--;
            } else
            {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */


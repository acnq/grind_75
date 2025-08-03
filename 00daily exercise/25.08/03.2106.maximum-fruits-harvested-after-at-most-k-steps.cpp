/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 * @lcpr version=30204
 *
 * [2106] 摘水果
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
    // I. 贪心+二分查找
    // 转变为求从起点移动k步而实际在x轴移动的最大区间范围
    // 遵循贪心原则，因为水果最多摘一次，所以尽可能移动的更远收益更大
    // 1. 一直往一个方向移动K步骤；要么往一个方向移动x步，另一个方向移动k - x步
    // 2. x = 0： 一直往一个方向移动k步
    // 枚举x \in [0, k/2]求出移动区间，假设起点为startPos, 实际有两种
    // 1. 左移x步，右移k - x步，范围[startPos - x, startPos + k - 2x]
    // 2. 右移x步，左移k - x步，范围[startPos + 2x - k, startPos + x]
    // 现在我们已知了移动范围，二分查找包含水果数量即可，
    // 实际我们通过前缀和预处理。
    // tc：O(n + klogn) 前缀和O(n), 查询水果数量O(logn), 共要查询k次；sc: O(n)

    // II. 滑动窗口
    // 换个思路，假设已知区间[left, right], 从startPos出发，至少要几步才能遍历完呢？
    // 分三种情况：
    // startPos > right: 一直左移; 步数：startPos - left
    // startPos < left: 一直右移; 步数：right - startPos
    // left <= startPos <= right: 两种选择：
    //      - 一直左移到left, 然后右移到right, 步数：
    //          startPos - left + right - left
    //      - 一直右移到right, 然后左移到left, 步数：
    //          right - startPos + right - left
    // 三种情况都可以统一为：right - left + min(|right - startPos|, |startPos - left)
    // 令其为step(left, right) = right - left + min(|right - startPos|, |startPos - left)
    // 固定right, 减小left, 可以看到，left < startPos=> step(left - 1, right) < step(left, right)
    //                              left >= startPos => step(left - 1, right) = step(left, right)
    // i.e. step(left - 1, right) >= step(left, right)
    // step随着left减小只减不增，这就构成了滑动窗口
    // left = right = 0, 每次right右移
    // 计算当前[left, right]移动步数，假设step > k, 左移left, 直到step < k, s.t. left <= right
    //  这就获得了最小移动步数<=k且以right为终点的最长区间，计算出该区间覆盖的水果数目即可
    // 依次直到right达到终点。
    // tc: O(n); sc: O(1)
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // I.
        // int n = fruits.size();
        // vector<int> sum(n + 1);
        // vector<int> indices(n);

        // // 构造前缀和
        // for (int i = 0; i < n; i++) {
        //     sum[i + 1] = sum[i] + fruits[i][1];
        //     indices[i] =fruits[i][0];
        // }
        
        // int ans = 0;
        // for (int x = 0; x <= k / 2; x++) {
        //     /*左移x步， 右移k - x步*/
        //     int y = k - 2 * x;
        //     int left = startPos - x;
        //     int right = startPos + y;
        //     int start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
        //     int end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
        //     ans = max(ans, sum[end] - sum[start]);

        //     /*右移x步，左移k - x步*/
        //     y = k - 2 * x;
        //     left = startPos - y;
        //     right = startPos + x;
        //     start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
        //     end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
        //     ans = max(ans, sum[end] - sum[start]);
        // }
        // return ans;

        // II.
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        auto step = [&](int left, int right) -> int {
            if (fruits[right][0] <= startPos) {
                return startPos - fruits[left][0];
            } else if (fruits[left][0] >= startPos) {
                return fruits[right][0] - startPos;
            } else {
                return min(abs(startPos - fruits[right][0]), 
                    abs(startPos - fruits[left][0])) + \
                    fruits[right][0] - fruits[left][0];
            }
        };

        // 每次固定right
        while (right < n) {
            sum += fruits[right][1];
            // 移动左边界
            while (left <= right && step(left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,8],[6,3],[8,6]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,3],[6,4],[8,5]]\n3\n2\n
// @lcpr case=end

 */


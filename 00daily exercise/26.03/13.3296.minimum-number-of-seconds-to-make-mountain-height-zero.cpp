/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 * @lcpr version=30204
 *
 * [3296] 移山所需的最少秒数
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

private:
    static constexpr double eps = 1e-7;
public:
    // I. 二分
    // 显然,如果t秒满足题意,那么任何>t的秒数也可以,所以答案单调,我们二分查找
    // 假设当前我们猜测秒数为mid, 判断工人能否在mid秒内移动高度H = mountainHeight的山
    // 对于第i个工人,降低山k米高的时间为:
    // workerTimes[i]*(\sum_{i=1}^k i) = workerTimes[i]*k(k + 1)/2
    // i.e. mid秒内,第i个工人能够最多将山降低的高度为,满足下式
    // workerTimes[i] * k(k+1)/2 <= mid
    // 的最大整数k, 令 work = \floor{mid/workterTimes[i]}
    // k = \floor{(-1 + \sqrt{1 + 8*work})/2}
    // 计算所有k后相加,如果和>=H, 则mid秒内可以完成任务,然后二分查找即可
    // 查找的下界为1,上界为max(workerTimes)*H(H + 1)/2(最慢工人独自完成所需时间)
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1, r = static_cast<long long>(maxWorkerTimes) *mountainHeight * (mountainHeight + 1) / 2;
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = 0;
            for (int t: workerTimes) {
                long long work = mid / t;
                // 求最大的k s.t. 1+......+k <= work
                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                cnt += k;
            }
            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[2,1,1]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[3,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[1]\n
// @lcpr case=end

 */


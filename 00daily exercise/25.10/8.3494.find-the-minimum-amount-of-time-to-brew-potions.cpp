// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3494 lang=cpp
 * @lcpr version=30204
 *
 * [3494] 酿造药水需要的最少总时间
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

#include <numeric> // iota
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. DP
    // 因为巫师酿造的流水线不能暂停，所以一旦开始造第j瓶药水
    // 造完的时间是确定的，唯一可变的就是开始造药的时间
    // 不妨允许酿造第j瓶药水的过程不连续，（前j-1瓶连续)
    // 假设第i位处理完j药的时间为times[i][j]
    // 有：times[i][j] = max(times[i - 1][j], times[i][j - 1]) + skill[i] * mana[j]
    // 因此，我们需要反向遍历更新巫师处理第j瓶药水的完成时间即可
    // times我们使用滚动数组优化
    // tc: O(nm) sc； O(n)
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                // 先确定每个巫师的最晚结束时间
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            // 依次确定此药的最晚结束时间
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                // 据此倒推第一个巫师的开始时间
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=successfulPairs
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,5,2,4]\n[5,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[1,1,1]\n
// @lcpr case=end


// @lcpr case=start
// [1,2,3,4]\n[1,2]\n
// @lcpr case=end
 */


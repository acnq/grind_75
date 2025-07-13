/*
 * @lc app=leetcode.cn id=2410 lang=cpp
 * @lcpr version=30204
 *
 * [2410] 运动员和训练师的最大匹配数
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
    // I. 排序 + 双指针 + 贪心
    // 按照从小到大排序运动员，对于每个运动员选择可以匹配他的最小的训练师即可
    // 证明：
    // 假设m个运动员第i个能力值为players_i, 有n个训练师第i个能力为trainers_i
    // 两序列经过排序，有players_i <= players_{i+1}, trainers_j <= trainers_{j + 1}
    // 假设匹配完i-1个运动员之后，满足第i个运动员的能力值的最小训练师是第j个训练师，
    // i.e.: trainers_j 是剩下的训练师中满足players_i <= trainers_j的最小值，如果不将j匹配给i,
    // 则1. i < m 且 players_{i + 1} <= trainers_j, 那么将j匹配给i + 1, 最多将j + 1匹配给i, 结果不会更多
    //   2. j < n, 将j + 1匹配给i, 若players_{i + 1} <= trainers_j,将j匹配给i + 1, 同上，匹配结果不会更多
    //                            若players_{i + 1} > trainers_j, j无法匹配给任何运动员，剩下的训练师会少一个，导致匹配结果更少
    // 如是，我们证明了贪心的有效性。
    // 算法：从小到大排序players, tainers,
    // \forall players[i], 找到“未被匹配的最小元素j”, s.t. players[i] <= trainers[j]
    // 则i, j即可完成匹配，
    // tc: O(mlogm + nlogn) (两边排序)；sc: O(logm +logn) 
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size(), n = trainers.size();
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && players[i] > trainers[j]) {
                j++; 
                // 不满足的trainer直接跳过，他们即使强制匹配也不会增加count
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,7,9]\n[8,2,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[10]\n
// @lcpr case=end

 */


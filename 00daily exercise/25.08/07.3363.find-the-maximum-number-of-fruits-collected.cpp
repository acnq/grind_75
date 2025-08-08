/*
 * @lc app=leetcode.cn id=3363 lang=cpp
 * @lcpr version=30204
 *
 * [3363] 最多可收集的水果数目
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
    // 注意到左上角的小朋友从(0, 0)出发恰好移动n - 1次到达房间(n - 1, n - 1)
    // 说明此人走只能走主对角线
    // 于是我们只需要计算剩下两个朋友收集总数的最大值即可
    // 右上角出发的，不难发现他不能越过主对角线，否则回来浪费步数，n-1次移动无法到达右下角
    // 左下角的同理，由于三个人不能走进同一个房间，我们仅考虑其中一个，
    // 我们DP其中一条，然后另一半翻转复用。问题转化为
    // 右上角(0, n - 1)出发，不经过主对角线，
    // 走到最后一个收集水果的房间(n - 2, n - 1)所能收集到的水果总数
    // dp[i][j]表示一个小朋友到达房间(i, j)能收集到的最多水果数量
    // \forall 1 <= i < n - 1 \and 1 < j < n, 
    // dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j]
    // j始终i, j可以从max(n - 1 - i, i + 1)开始枚举
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        auto dp = [&]() -> int {
            vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; i++) {
                for (int j = max(n - 1 - i, i + 1); j < n; j++) {
                    int best = prev[j];
                    if (j - 1 >= 0) {
                        best = max(best, prev[j - 1]);
                    }
                    if (j + 1 < n) {
                        best = max(best, prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                swap(prev, curr);
            }
            return prev[n - 1];
        };

        ans += dp();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(fruits[j][i], fruits[i][j]);
            }
        }

        ans +=dp();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

 */


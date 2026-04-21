/*
 * @lc app=leetcode.cn id=1320 lang=cpp
 * @lcpr version=30204
 *
 * [1320] 二指输入的的最小距离
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
public:
    // I. DP
    // dp[i][l][r]: 输入字符串word的第i个字母后，左手位置为l, 右手位置为r
    // 达到该状态的最小距离，注意这里的距离对应字母编号（A->0, B->1)
    // 这样方便状态转移
    // 首先注意到，输入第i个字母之后，左右手至少有一个在word[i]位置
    // 为此我们分类讨论
    // word[i] == l: (左手在word[i]位置)
    //    我们进一步考虑word[i - 1]的位置
    //    如果左手在word[i - 1], 输入i时，左手从word[i-1]移动到word[i]
    //      dp[i][l = word[i]][r] = dp[i - 1][l0=word[i-1]][r] + dist(word[i - 1], word[i])
    //    如果右手在word[i - 1], 则右手不动, 记word[i-1]时左手的位置为l0
    //      dp[i][l=word[i]][r=word[i-1]]=dp[i-1][l0][r=word[i-1]] + dist(l0, word[i])
    // word[i] == r: (右手在word[i]位置)
    //      同理
    //      如果右手在word[i - 1]，
    //        dp[i][l][r=word[i]]=dp[i-1][l][r0=word[i-1]] + dist(word[i-1], word[i])
    //      如果左手在word[i - 1]
    //        dp[i][l=word[i-1]][r=word[i]]=dp[i-1][l=word[i-1]][r0] + dist(r0, word[i])
    // dp[0][l=word[0]][r] = dp[0][l][r=word[0]] = 0
    //
    // tc: $O(|\sigma|N)$, $N = |word|, |\sigma|=26$
    // sc: $O(|\sigma|^2N)$ 

    // II. DP + 空间优化
    // 利用左右手的对称性，我们只用一个数组来解决此问题
    // dp[i][op][rest]， op==0: 左手在word[i]的额位置，=1右手
    // rest: 不在word[i]位置的另一只手的位置
    // 我们继续优化，注意到dp[i][0][rest] == dp[i][1][rest]
    // 所以我们直接用 dp[i][rest]状态转移

    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minimumDistance(string word) {
        // I.
        // int n = word.size();
        // int dp[300][26][26];
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 26; j++) {
        //         fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
        //     }
        // }
        // for (int i = 0; i < 26; i++) {
        //     dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        // }

        // for (int i = 1; i < n; i++) {
        //     int cur = word[i] - 'A';
        //     int prev = word[i - 1] - 'A';
        //     int d = getDistance(prev, cur);
        //     for (int j = 0; j < 26; j++) {
        //         dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
        //         dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
        //         if (prev == j) {
        //             for (int k = 0; k < 26; k++) {
        //                 int d0 = getDistance(k, cur);
        //                 dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][k][j] + d0);
        //                 dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][k] + d0);
        //             }
        //         }
        //     }
        // }

        // int ans = INT_MAX >> 1;
        // for (int i = 0; i < 26; i++) {
        //     for (int j = 0; j < 26; j++) {
        //         ans = min(ans, dp[n - 1][i][j]);
        //     }
        // }
        // return ans;

        // II.
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX >> 1));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; k++) {
                        int d0 = getDistance(k, cur);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        int ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "CAKE"\n
// @lcpr case=end

// @lcpr case=start
// "HAPPY"\n
// @lcpr case=end

 */


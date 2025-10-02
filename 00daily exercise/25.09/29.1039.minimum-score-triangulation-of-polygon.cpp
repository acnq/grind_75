/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 * @lcpr version=30204
 *
 * [1039] 多边形三角剖分的最低得分
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
    // dp[i][j] (j >= i + 2)表示顶点i:j构成的凸多边形（j - i + 1边)
    // 进行三角剖分可得的最低分。若i+2=j, 则此为三角形，
    // 否则，假设i,j和另一顶点k(i < k < j)构成三角形，则△ijk将此多边形分成3份
    // 1. i:k构成凸k-i+1边型，k=i+1，这部分不存在
    // 2. ikj构成△
    // 3. k:j构成凸j-k+1边型，j=k+1,这部分不存在
    // 显然凸多边形的值就是这三部分值之和，遍历k来求得最小值即可
    // 我们用记忆化搜索实现
    // 答案为dp[0][n - 1]
    // tc: O(n^3), sc: O(n^2)
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int{
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;// 这样i,j可以唯一确定key
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1,4,1,5]\n
// @lcpr case=end

 */


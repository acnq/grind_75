// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=712 lang=cpp
 * @lcpr version=30204
 *
 * [712] 两个字符串的最小ASCII删除和
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
    // 纸笔推演了一下
    // 感觉可以这么搞
    // 令S[i, j]表示A[:i]和B[:j]的“删除ASCII和”
    // S[i, j] = min(S[i - 1, j] + A[i], S[i, j - 1] + B[j], S[i - 1, j - 1] + A[i] + B[j]); A[i] != B[j]
    // S[i, j] = min(S[i - 1, j] + A[i], S[i, j - 1] + B[j], S[i - 1, j - 1]); A[i] == B[j]
    // 和上一题一样，要用S[0][j], S[i][0]表示空串，所以S大小得是n + 1, m + 1;
    // i:竖，n s1; j:横，m s2;
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        int tmp = 0;
        for(int i = 0; i <= n; i++) {
            s[i][0] = tmp;
            tmp += (int)(s1[i]);
        }
        tmp = 0;
        for(int j = 0; j <= m; j++) {
            s[0][j] = tmp;
            tmp += (int)(s2[j]);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int tmp = min(s[i - 1][j] + s1[i - 1], s[i][j - 1] + s2[j - 1]);
                if(s1[i - 1] == s2[j - 1]) {
                    s[i][j] = min(tmp, s[i - 1][j - 1]);
                } else {
                    s[i][j] = min(tmp, s[i - 1][j - 1] + (int)(s1[i - 1] + s2[j - 1]));
                }
            }
        }
        return s[n][m];
        // 独立完成
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "delete"\n"leet"\n
// @lcpr case=end

 */


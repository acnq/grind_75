// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30204
 *
 * [115] 不同的子序列
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
    // 纸笔尝试了一下，有如下关系式
    // r(i, j): s[:i]包含t[:j]的数量（r for repeatition)
    // r(i, j) = r(i - 1, j); s[:i] != t[:j]
    // r(i, j) = r(i - 1, j) + r(i - 1, j - 1); s[:i] == t[:j]
    // t[:j-1]在s[:i-1]中出现的次数 + t[:j]在s[:i-1]中出现的次数，
    // 因为重复的部分或者包含t[j]或者不包含，必且仅取其一
    // r(i, j) = 0 (i < j)
    // 用0数组初始化，注意边界
    // r(0, j) = 0
    // r(i, 1)需要手动计算一下，=s[:i].count(t[0])
    // i:n, s, 竖; j:m,t，横
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> r(n + 1, vector<unsigned long long>(m + 1)); 
        // 测试集中有些样例很变态，甚至long long都要爆栈
        
        // init
        r[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = i + 1; j <= m; j++) {
                r[i][j] = 0;
            }
        }
        int tmp_cnt = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (s[i - 1] == t[0])
            {
                tmp_cnt++;
            }
            r[i][1] = tmp_cnt;
        }
        
        // dp
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                if (s[i - 1] != t[j - 1])
                {
                    r[i][j] = r[i - 1][j];
                } else {
                    r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
                }
            }
        }
        return r[n][m];
        // 终于独立做出来了困难题，太困难了，两个小时的推演TAT
    }
};
// @lc code=end



/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */


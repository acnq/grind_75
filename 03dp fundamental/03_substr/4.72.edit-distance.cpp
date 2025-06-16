// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30204
 *
 * [72] 编辑距离
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
    // I. dp
    // 根据答案
    // 我们需要这么思考，假设现在有字符串A, B
    // 只允许插入一个字符，那么A和B的距离最多为A和B[:-1]的距离+1
    // 只允许删除一个字符，那么A和B的距离最多为A[:-1]和B的距离+1
    // 允许修改字符，那么看A和B的最后一个字符，如果相同，那么AB的距离就最多为
    // A[:-1]和B[:-1]的距离，如果不等，那么最多为A[:-1]和B[:-1]的距离+1
    // 当然，我们可以考虑A和B的前面几位，但是上述的结论一定是“最多的”（上限）
    // 我们用DP[i][j]表示字符串A以i结尾的子串和B以j为结尾的子串之间的距离
    // 于是中间的字符操作也等价于某一步的末尾操作，
    // D[i][j] = min(D[i][j - 1], D[i - 1][j], D[i - 1][j - 1]) + 1; A[i] != B[j]
    // D[i][j] = min(D[i][j - 1] + 1, D[i - 1][j] + 1, D[i - 1][j - 1]); A[i] == B[j]
    // D[i][0] = i; D[0][j] = j; 
    // 需要从1开始标记，不然空字符串会缺少定义
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> D(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++)
        {
            D[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            D[0][j] = j;
        }
        
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    D[i][j] = min(min(D[i][j - 1] + 1, D[i - 1][j] + 1), D[i - 1][j - 1]);
                } else {
                    D[i][j] = min(min(D[i][j - 1], D[i - 1][j]), D[i - 1][j - 1]) + 1;
                }
                
            }
        }
        return D[n][m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    // 感觉不是标准的DP, 
    // dp[i]: 以i为结尾的字符串能否字典化
    // 枚举j < i: dp[i] = 存在j:(dp[j] && s[j+1:i] \in Dict)
public:
    bool check(string s, vector<string> wordDict) {
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
        {
            return true;
        } else {
            return false;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n + 1, false);
        // 这里必须把dp(i): 设置成"s[0:i-1]是否可字典化", 
        // i.e. 以i-1结尾的串能否字典化
        // 不然初始化会很麻烦
        dp[0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && check(s.substr(j, i - j), wordDict))
                {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */


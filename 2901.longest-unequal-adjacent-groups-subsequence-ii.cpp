// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2901 lang=cpp
 * @lcpr version=30204
 *
 * [2901] 最长相邻不相等子序列 II
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
    // I. 2900 类似的贪心算法不好使了
    // II. DP
    // dp[i]: 以下标i结尾的最长子序列的长度
    // 符合要求的子序列如果j在i之后
    // 一定有：groups[i] != groups[j] j > i
    // HammingDist(words[i], words[j]),
    // 此时j可以添加到i之后，dp[j] = dp[i] + 1;
    // 所以递推式如下：
    // dp[j] = max(dp[j], dp[i] + 1) if (groups[i] != groups[j] && HammingDist(words[i], word[j]) = 1)
    // 对于i, 枚举所有i之前的下标，可求得i为结尾的最长子序列的长度，
    // 依次求得每个下标i的dp[i]即可求得[0:n-1]中最长子序列的长度
    // 记prev[i]为下标i结尾的最长子序列中i的上一个下标，
    // 当找到[0:n]中最长子序列对应的下标i*的，沿着i*往前即可找到整个序列的下标，收集这些元素并反转即答案。

public:
    int HammingDist(string& str1, string& str2) {
        if(str1.size() != str2.size()) {
            return -1;
        } 
        int n = str1.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(str1[i] != str2[i]) {
                cnt++;
            }
        }

        return cnt;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(groups[i] != groups[j] && HammingDist(words[i], words[j]) == 1) {
                    // dp[i] = max(dp[i], dp[j] + 1);
                    // prev[i] = j;
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        int longest_subseq_len = 0, longest_subseq_idx;
        for(int i = 0; i < n; i++) {
            if(dp[i] > longest_subseq_len) {
                longest_subseq_len = dp[i];
                longest_subseq_idx = i;
            }
        }
        
        vector<string> ans;
        int cur_idx = longest_subseq_idx;
        while(prev[cur_idx] != -1) {
            ans.push_back(words[cur_idx]);
            cur_idx = prev[cur_idx];
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
        
        // 官方题解
        // int n = groups.size();
        // vector<int> dp(n, 1);
        // vector<int> prev(n, -1);
        // int maxIndex = 0;
        // for(int i = 1; i < n; i++) {
        //     for(int j = 0; j < i; j++) {
        //         if(check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
        //             dp[i] = dp[j] + 1;
        //             prev[i] = j;
        //         }
        //     }

        //     if(dp[i] > dp[maxIndex]) {
        //         maxIndex = i;
        //     }
        // }

        // vector<string> ans;
        // for(int i = maxIndex; i >= 0; i = prev[i]) {
        //     ans.emplace_back(words[i]);
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
    }

    bool check(string& s1, string& s2) {
        if(s1.size() != s2.size()) {
            return false;
        }

        int diff = 0;
        for(int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if(diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getWordsInLongestSubsequence
// paramTypes= ["string[]","number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// ["bab","dab","cab"]\n[1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// 4\n["a","b","c","d"]\n[1,2,3,4]\n
// @lcpr case=end


// @lcpr case=start
// ["ac","caa","cda","ba"]\n[3,1,2,3]\n
// @lcpr case=end


// @lcpr case=start
// ["cdb","cdd","cd","dcc","cca","cda","ca","cc","bcc"]\n[8,5,9,5,2,7,4,7,3]\n
// @lcpr case=end
 */


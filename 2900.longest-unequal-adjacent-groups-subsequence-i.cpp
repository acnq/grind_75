// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2900 lang=cpp
 * @lcpr version=30204
 *
 * [2900] 最长相邻不相等子序列 I
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
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // int n = groups.size();
        // if (n == 1)
        // {
        //     return words;
        // }
        
        // vector<int> idx;
        // vector<int> val;
        
        
        // for (int i = 1; i < n; i++)
        // {
        //     if (groups[i] != groups[i - 1])
        //     {
        //         idx.push_back(i - 1);
        //         val.push_back(groups[i - 1]);
        //     } else {
        //         continue;
        //     }
            
        // }
        // if (idx.empty())
        // {
        //     vector<string> res;
        //     res.push_back(words[0]);
        //     return res;
        // }
        
        // if (groups[n - 1] != val[idx.size() - 1])
        // {
        //     idx.push_back(n - 1);
        // }
        
        // vector<string> res;
        // for (int i = 0; i < idx.size(); i++)
        // {
        //     res.push_back(words[idx[i]]);
        // }
        // return res;

        // II.
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || groups[i] != groups[i - 1])
            {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getLongestSubsequence
// paramTypes= ["string[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// ["e","a","b"]\n[0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c","d"]\n[1,0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// ["o","cfy","en"]\n[1,0,0]\n
// @lcpr case=end


 */


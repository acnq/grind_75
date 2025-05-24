/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=30204
 *
 * [1768] 交替合并字符串
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
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()) {
            res += word1[i];
            res += word2[j];
            i++;
            j++;
        }
        if (i < word1.size())
        {
            while (i < word1.size())
            {
                res += word1[i];
                i++;
            }
        }

        if (j < word2.size())
        {
            while (j < word2.size())
            {
                res += word2[j];
                j++;
            }          
        }
        
        return res;
        
        // 更好的写法：
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) {
                res.push_back(word1[i]);
                ++i;
            }
            if (j < word2.size()) {
                res.push_back(word2[j]);
                ++j;
            }
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */


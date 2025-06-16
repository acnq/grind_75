/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 * @lcpr version=30204
 *
 * [2942] 查找包含给定字符的单词
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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        // 2025.5.24; 秒杀
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            string tmp;
            tmp.push_back(x);
            string word = words[i];
            if (word.find(tmp) != string::npos)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["leet","code"]\n"e"\n
// @lcpr case=end

// @lcpr case=start
// ["abc","bcd","aaaa","cbc"]\n"a"\n
// @lcpr case=end

// @lcpr case=start
// ["abc","bcd","aaaa","cbc"]\n"z"\n
// @lcpr case=end

 */


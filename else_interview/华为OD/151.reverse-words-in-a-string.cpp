// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
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
    string reverseWords(string s) {
        vector<string> v;
        string ans;
        for(int i = 0; i < s.size();) {
            while(i < s.size() && !isalpha(s[i]) && !isdigit(s[i])) {
                i++;
            }
            string word;
            while((isalpha(s[i]) || isdigit(s[i])) && i < s.size()) {
                word.push_back(s[i]);
                i++;
            }
            if(word != "") {
                v.push_back(word);
            }
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            ans += v[i];
            if (i != v.size() - 1) {
                ans += " ";
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */


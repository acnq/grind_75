/*
 * @lc app=leetcode.cn id=3121 lang=cpp
 * @lcpr version=30204
 *
 * [3121] 统计特殊字母的数量 II
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
    int numberOfSpecialChars(string word) {
        // O. 不难，20min一遍过
        // unordered_map<char, vector<int>> hash;
        // for (int i = 0; i < word.size(); i++) {
        //     hash[word[i]].push_back(i);
        // }
        // int ans = 0;
        // for (char ch = 'a'; ch <= 'z'; ch++) {
        //     if (hash.count(ch) && hash.count(ch - 'a' + 'A')) {
        //         vector<int> lower = hash[ch];
        //         vector<int> upper = hash[ch - 'a' + 'A'];
        //         int lower_ = *max_element(lower.begin(), lower.end());
        //         int upper_ = *min_element(upper.begin(), upper.end());
        //         if (lower_ < upper_) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // I. 标答
        // tc: O(n + |\sigma|) |\sigma|=26; sc: O(|\sigma|)
        // sc比我的写法小一点
        vector<int> lastLow(26, -1), firstUp(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i]) {
                ans++;
            }
        }
        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "aaAbcBC"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "AbBCab"\n
// @lcpr case=end

 */


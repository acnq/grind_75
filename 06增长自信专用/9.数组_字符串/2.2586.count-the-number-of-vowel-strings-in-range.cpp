/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 * @lcpr version=30204
 *
 * [2586] 统计范围内的元音字符串数
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
    // O.
    bool isVowelString(string s) {
        int n = s.size();
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            if (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u') {
                return true;
            }
        }
        return false;
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        // O.
        int ans = 0;
        for(int i = left; i <= right; i++) {
            if (isVowelString(words[i])) {
                ans++;
            }
        }
        return ans;

        // I.
        // 官方用unordered_map做
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            const string& word = words[i];
            if (vowels.count(word[0]) && vowels.count(word.back()))
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["are","amy","u"]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// ["hey","aeo","mu","ooo","artro"]\n1\n4\n
// @lcpr case=end

 */


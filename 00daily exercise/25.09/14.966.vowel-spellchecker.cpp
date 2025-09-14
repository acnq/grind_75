/*
 * @lc app=leetcode.cn id=966 lang=cpp
 * @lcpr version=30204
 *
 * [966] 元音拼写检查器
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
    // 1. 哈希表
    // 所有3种情况，都可以用哈希表来查询
private:
    unordered_set<string> words_perfect;
    unordered_map<string, string> words_cap;
    unordered_map<string, string> words_vow;

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string devowel(string word) {
        string ans;
        for (char c: word) {
            ans += isVowel(c) ? '*': c;
        }
        return ans;
    }

    string solve(string query) {
        if (words_perfect.count(query)) {
            return query;
        }

        string queryL;
        for (char c: query) {
            queryL += tolower(c);
        }
        if (words_cap.count(queryL)) {
            return words_cap[queryL];
        }

        string queryLV = devowel(queryL);
        if (words_vow.count(queryLV)) {
            return words_vow[queryLV];
        }
        return "";
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string word: wordlist) {
            words_perfect.insert(word);
            string wordlow;
            for (char c: word) {
                wordlow += tolower(c);
            }
            if (!words_cap.count(wordlow)) {
                words_cap[wordlow] = word;
            }
            string wordlowDV = devowel(wordlow);
            if (!words_vow.count(wordlowDV)) {
                words_vow[wordlowDV] = word;
            }
        }

        vector<string> ans;
        for (string query: queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["KiTe","kite","hare","Hare"]\n["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]\n
// @lcpr case=end

// @lcpr case=start
// ["yellow"]\n["YellOw"]\n
// @lcpr case=end

 */


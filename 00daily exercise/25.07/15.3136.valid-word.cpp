// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3136 lang=cpp
 * @lcpr version=30204
 *
 * [3136] 有效单词
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
    bool isVowel(char c) {
        c = tolower(c);
        switch (c) {
            case 'a':
                return true;
                break;
            case 'e':
                return true;
                break;
            case 'i':
                return true;
                break;
            case 'o':
                return true;
                break;
            case 'u':
                return true;
                break;
            default:
                return false;
                break;
        }
    }

    bool isValid(string word) {
        int vowel_cnt = 0, cosnt_cnt = 0;
        if (word.size() < 3) {
            return false;
        }
        for (int i = 0; i < word.size(); i++) {
            if (!isalnum(word[i])) {
                return false;
            } else if(isVowel(word[i])) {
                vowel_cnt++;
            } else if (isalpha(word[i]) && !isVowel(word[i])) {
                cosnt_cnt++;
            }
        }
        if (vowel_cnt > 0 && cosnt_cnt > 0) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=isValid
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "234Adas"\n
// @lcpr case=end

// @lcpr case=start
// "b3"\n
// @lcpr case=end

// @lcpr case=start
// "a3$e"\n
// @lcpr case=end

 */


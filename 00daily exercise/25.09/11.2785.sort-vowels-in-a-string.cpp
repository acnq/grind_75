// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2785 lang=cpp
 * @lcpr version=30204
 *
 * [2785] 将字符串中的元音字母排序
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
    bool isvowel(char ch) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char v: vowels) {
            if (ch == v) {
                return true;
            }
        }
        return false;
    }
    string sortVowels(string s) {
        string t = "";
        vector<char> tmp;
        for (char ch: s) {
            if (isvowel(ch)) {
                tmp.push_back(ch);
            }
        }
        sort(tmp.begin(), tmp.end());
        int i = 0;
        for (char ch: s) {
            if(isvowel(ch)) {
                t += tmp[i];
                i++;
            } else {
                t += ch;
            }
        }
        return t;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=sortVowels
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "lEetcOde"\n
// @lcpr case=end

// @lcpr case=start
// "lYmpH"\n
// @lcpr case=end

 */


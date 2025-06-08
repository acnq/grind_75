// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30204
 *
 * [58] 最后一个单词的长度
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
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while(i >= 0 && s[i] == ' ') {
            i--;
        }
        int j = i;
        while(j >= 0 && s[j] != ' ') {
            j--;
        }
        int res = i - j;
        return res;
        // 6min a.c. 
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end


// @lcpr case=start
// "a"\n
// @lcpr case=end
 */


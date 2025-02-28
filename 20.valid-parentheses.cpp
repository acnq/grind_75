// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> leftParanth;
        for(char ch: s) {
            if((ch == '(') || (ch == '[') || (ch == '{')){
                leftParanth.push(ch);
            } else if(ch == ')') {
                if((leftParanth.empty()) && (leftParanth.top() != '(')) {
                    return false;
                } else {
                    leftParanth.pop();
                }
            } else if(ch == ']') {
                if((leftParanth.empty()) && (leftParanth.top() != '[')) {
                    return false;
                } else {
                    leftParanth.pop();
                }
            } else if(ch == '}') {
                if((leftParanth.empty()) && (leftParanth.top() != '{')) {
                    return false;
                } else {
                    leftParanth.pop();
                }
            }
        }
        return leftParanth.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */


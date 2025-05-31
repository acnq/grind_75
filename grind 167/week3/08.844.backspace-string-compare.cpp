
/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=30204
 *
 * [844] 比较含退格的字符串
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
    string backspaceValue(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '#') {
                stk.push(s[i]);
            } else {
                if(!stk.empty()) {
                    stk.pop();
                } else {
                    continue;
                }
            }
        }
        if(stk.empty()) {
            return "";
        }
        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        if(backspaceValue(s) == backspaceValue(t)) {
            return true;
        } else {
            return false;
        }
        // 还可以使用双指针法，
        // 观察，一个字符会被会被删去只和后面有没有#有关，和前面无关
        // 因此，我们逆序遍历，保存目前为止遇到的#数量delNum
        // 遇到普通字符且delNum不为0，则需要删去字符，同时delNum--
        int i = s.length() - 1, j = t.length() - 1;
        int delNumS = 0, delNumT = 0;
        
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    delNumS++;
                    i--;
                } else if (delNumS > 0) {
                    delNumS--;
                    i--;
                } else {
                    break;
                }
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    delNumT++;
                    j--;
                } else if (delNumT > 0) {
                    delNumT--;
                    j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0) {
                if(s[i] != t[j]) {
                    return false;
                }
            } else {
                if(i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--;
            j--;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */


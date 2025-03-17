/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30204
 *
 * [8] 字符串转换整数 (atoi)
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
class Automaton
{
private:
public:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c))
        {
            return 0;
        }
        if (c == '+' || c == '-')
        {
            return 1;
        }
        if (isdigit(c))
        {
            return 2;
        }
        return 3;
    }

    int sign = 1;
    long long ans = 0;
    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long) INT_MIN);
        } else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }        
    }
};

class Solution {
    // 自动机
    // state / symbol    ''     +/-     number       other
    // start             start  signed  in_number    end
    // signed            end    end     in_number    end
    // in_number         end    end     in_number    end
    // end               end    end     end          end
public:
    int myAtoi(string s) {
        Automaton automaton;
        for (char c : s)
        {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */


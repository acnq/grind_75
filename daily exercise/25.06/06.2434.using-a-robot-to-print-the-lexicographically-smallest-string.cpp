/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 * @lcpr version=30204
 *
 * [2434] 使用机器人打印字典序最小的字符串
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
    // I. 贪心栈
    // 相当于给了个入栈序列s，要求出栈序列字典序最小
    // 我们得考虑栈顶元素c和字符串s中剩余字符中最小的字符minChar
    //  1. c < minChar, 那么得将栈顶元素出栈，才能保证出栈序列字典序最小
    //  2. c > minChar, 需要保留栈顶元素，并入栈直到minChaar才能保证出栈序列小
    //  3. c = minChar, 也必须先出栈在走2, 这样可以得到两个连续的最小char，
    //          否则先按2走再出栈，这两个字符就不连续不如先出栈小
public:
    string robotWithString(string s) {
        unordered_map<char, int> cnt;
        for(char c: s) {
            cnt[c]++;
        }

        stack<int> stk;
        string res;
        char minChar = 'a';
        for(char c: s) {
            stk.emplace(c);
            cnt[c]--;
            while (minChar != 'z' && cnt[minChar] == 0)
            {
                minChar++;
            }
            while (!stk.empty() && stk.top() <= minChar)
            {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "zza"\n
// @lcpr case=end

// @lcpr case=start
// "bac"\n
// @lcpr case=end

// @lcpr case=start
// "bdda"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
    // I. 滑动窗口
    // 用r,l 控制窗口在s上滑动
    // 右移r不断扩张窗口，当窗口包含t全部所需字符之后，
    // 收缩l, 直到得到最小窗口

    // 如何判断包含全部字符？
    // 用哈希表表示t中所有字符以及他们的个数
    // 再用一个哈希表动态维护窗口中所有字符以及他们的个数
    // 这个动态表包含t哈希表中所有字符且出现数量不少于t哈希表中对应个数
    // 则窗口可行

public:
    unordered_map<char, int> ori, cnt;
    bool check() {
        for(const auto& p: ori) {
            if (cnt[p.first] < p.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(const auto& c: t) {
            ori[c]++;
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;
        while (r < int(s.size()))
        {
            if (ori.find(s[++r]) != ori.end())
            {
                cnt[s[r]]++;
            }
            while (check() && l <= r)
            {
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end())
                {
                    cnt[s[l]]--;
                }
                l++;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
public:
    bool mapASmallerB(unordered_map<char, int> a, unordered_map<char, int> b) {
        if (a == b)
        {
            return false;
        }
        
        if (a.size() < b.size())
        {
            return true;
        }
        if (a.empty())
        {
            return true;
        }
        
        for(auto it = a.begin(); it != a.end(); it++) {
            if (it->second < b[it->first])
            {
                return true;
            }
        }
        return false;
    }
    unordered_map<char, int> ori, cnt;
    bool check() {
        for(const auto &p: ori) {
            if (cnt[p.first] < p.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        // 看了眼提示
        // r, l控制s上的滑窗，r右移不断吞入字符，t内的字符全部吞入后
        // 右移l, 确保在滑窗包含所有字符的情况下尽可能小，
        // 如果已经达到本地极小值，记录当前极值，右移一步l, 重复第一行，
        // 直到r走到尾部，
        // if (s.size() < t.size()) {
        //     return "";
        // }

        // string ans = s;
        // int left = 0, right = 0;
        // int n = s.size(), m = t.size();
        // unordered_map<char, int> tstats, sstats;
        // for (int i = 0; i < t.size(); i++)
        // {
        //     tstats[t[i]]++;
        // }
        
        // string cur = "";
        // while (left < n + 1 && right < n + 1)
        // {
        //     while (right < n && mapASmallerB(sstats, tstats) )
        //     {
        //         if (tstats.count(s[right]) > 0 && tstats[s[right]] > 0)
        //         {
        //             sstats[s[right]]++;
        //         }
        //         right++;
        //     }
        //     while (left < n && (tstats.count(s[left]) <= 0 || tstats[s[left]] <= 0))
        //     {
        //         left++;
        //     }
        //     if (!mapASmallerB(sstats, tstats))
        //     {
        //         cur = s.substr(left, right - left);
        //         if (cur.length() < ans.length())
        //         {
        //             ans = cur;
        //         }
        //     }
        //     sstats[s[left]]--;
        //     left++;
        // }
        // if (cur == "")
        // {
        //     return "";
        // } else {
        //     return ans;
        // }
        // 上述方法已经感觉已经优化到O(N + M)了，
        // 但还是超时了（正确性没有问题）
        // 感觉是调用substr太多了

        for(const auto& c: t) {
            ori[c]++;
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;
        while (r < int(s.size()))
        {
            r++;
            if (ori.find(s[r]) != ori.end())
            { // 右移r
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
        return ansL == -1 ? string() : s.substr((ansL, len));
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
// "ab"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"A"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "bba"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaaaaaaaaabbbbbcdd"\n"abcdd"\n
// @lcpr case=end
 */


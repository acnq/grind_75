/*
 * @lc app=leetcode.cn id=2014 lang=cpp
 * @lcpr version=30204
 *
 * [2014] 重复 K 次的最长子序列
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
    // 本题没有官方题解，下面是ylb的答案
    // I. bfs
    // 统计字符串中每个字符出现的次数，将出现次数>=k的字符从小到大
    // 存入一个列表cs中，然后用bfs来枚举所有可能的子序列
    // 定义队列q, 初始时将空串放入队列中，然后从队列中取出字符串cur
    // 尝试将每个字符c \in cs添加到cur的末尾，形成新串nxt,
    // 如若nxt是一个重复k次的子序列，则将其加入答案，然后nxt入列
    // check(t, k)用来判断t是否是s的一个重复k次的子序列
    // 使用两个指针来遍历s,t; 如果能找到t的所有字符并都能重复k次，就返回true
    
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        auto check = [&](const string& t, int k) -> bool {
            int i = 0;
            for (char c: s) {
                if (c == t[i]) {
                    i++;
                    if (i == t.size()) {
                        if (--k == 0) {
                            return true;
                        }
                        i = 0;
                    }
                }
            }
            return false;
        };

        int cnt[26] = {};
        for (char c: s) {
            cnt[c - 'a']++;
        }
        vector<char> cs;
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c - 'a'] >= k) {
                cs.push_back(c);
            }
        }

        queue<string> q;
        q.push("");
        string ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (char c: cs) {
                string nxt = cur + c;
                if (check(nxt, k)) {
                    ans = nxt;
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "letsleetcode"\n2\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n2\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n2\n
// @lcpr case=end

 */


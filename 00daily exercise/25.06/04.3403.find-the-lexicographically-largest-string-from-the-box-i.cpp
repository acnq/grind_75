/*
 * @lc app=leetcode.cn id=3403 lang=cpp
 * @lcpr version=30204
 *
 * [3403] 从盒子中找出字典序最大的字符串 I
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
    // I. 暴力可解
    // 1. numFriendes = 1, 返回word即可
    // 2. 否则，我们注意到显然的结论：对于每个字符串开头i, 一定是最长的字符串字典序最大
    // 那么什么限制了字符串的长度呢，有两种可能，应该表述为min(n - numFriends + 1, n - i)
    // 第一项表示切分成numFriends，每段最大的长度
    // 这时我们枚举子串即可。
    // （感觉可以自己想出来，解析看早了）

    // II. 双指针
    // numFriends > 1, 找到字典序最大的后缀串的左端点i,
    // 取出以i为左端点，长度为min(n - numFriends + 1, n - i)的分割字符串s_i即为答案
    // 反证法，假设sj > si;
    //  i. 如果si是后缀串（i.e. n - numFriends + 1 >= n - i), 那么s_j > s_i与s_i是最大后缀串直接矛盾word[j:-1]才是最大的
    //  ii. 如果si不是（i.e. n - numFriends + 1 < n - i), 找到s_j和s_i第一不同位置，s_j对应的字符要更大
    //      那么同样word[j:-1]是一个更大的后缀，再次矛盾
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n)
        {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k])
            {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k])
            {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }

    string answerString(string word, int numFriends) {
        // int n = word.size();
        // string ans = "";
        // if (numFriends == 1)
        // {
        //     return word;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     ans = max(ans, word.substr(i, min(n - numFriends + 1, n - i)));
        // }
        // return ans;
        // string 内建的顺序就是字典序
        if (numFriends == 1)
        {
            return word;
        }
        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "dbca"\n2\n
// @lcpr case=end

// @lcpr case=start
// "gggg"\n4\n
// @lcpr case=end

 */


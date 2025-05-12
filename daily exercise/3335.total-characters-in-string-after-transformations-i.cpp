// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 * @lcpr version=30204
 *
 * [3335] 字符串转换后的长度 I
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
    // I. 暴力模拟
    // 超时

    // II. 递推法
    // f(i, c): i次转化后字符c的数量，c \in [0, 26), 对应a-z
    // f(0, c)：c在给定的字符串s中出现的次数
    //  f(i, c) <- f(i - 1, c):
    //     若c = 0, 对应a, 可以从z转换来，所以f(i, 0) = f(i - 1, 25)
    //     若从= 1, 对应b, 可以从z或者a转换来：f(i, 1) = f(i - 1, 25) + f(i - 1, 0)
    //     若c >= 2, 只能从上一个字符转化来：f(i, c) = f(i - 1, c - 1)

    // 依次可以从f(1, c) 递推到f(t, c), 最终res = \sum_{c = 0}^25f(t, c)
    // 因为f(i, c) 只依赖于 f(i - 1, c), 我们用两个一位数组代替整个二维数组f递推
    // nxt := f(i, c); cnt := f(i - 1, c) 
public:
    int mod = 1e9 + 7;
    string transformatn(string s) {
        string res;
        for(char ch: s) {
            if (ch == 'z')
            {
                res += 'a';
                res += 'b';
            } else {
                char new_ch = ch + 1;
                res += new_ch;
            }
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t) {
        // 暴力模拟
        // string str = s;
        // for (int i = 0; i < t; i++)
        // {
        //     // transform s
        //     str = transformatn(str);
        // }
        // return str.size() % mod;

        // II. dp
        vector<int> cnt(26);
        for(char ch: s) {
            cnt[ch - 'a']++;
        }
        for (int i = 0; i < t; i++)
        {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; i++)
            {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=lengthAfterTransformations
// paramTypes= ["string","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "abcyy"\n2\n
// @lcpr case=end

// @lcpr case=start
// "azbk"\n1\n
// @lcpr case=end

 */


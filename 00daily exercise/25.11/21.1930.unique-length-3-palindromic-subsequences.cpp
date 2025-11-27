// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 * @lcpr version=30204
 *
 * [1930] 长度为 3 的不同回文子序列
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
#include <stdio.h>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 枚举两侧：
    // 枚举回文序列两侧的字符种类，对于每种字符
    // 如果他在s中出现，我们记录他首次出现的下标l和末次的r
    // 以该字符为两侧的回文序列，中间字符在s[l+1,r-1]中选取
    // 总数为s[l+1:r-1]中的字符种数量
    // 遍历s[l+1:r-1], 用哈希统计种类数即可
    // tc: O(n|S| + |S|^2), |S|字符集大小，sc: O(|S|)
    // II. 枚举中间
    // 遍历到s[i]时，以s[i]为中间的回文子序列即是s[0:i-1]和s[i+1:n-1]的公共字符种数
    // 我们用32位整数表现子串包含的字符：
    // 如果该整数从低到高第 i 个二进制位为 1，那么代表该子串含有字典序为 i 的小写英文字母
    // 遍历子串我们仅需要按位或来维护该整数
    // 用2个32位整数维护数组pre, suf
    // pre[i]: s[0:i-1]包含的字符种类
    // suf[i]: s[i+1:n-1]包含的字符种类
    // 则s[i]为中间字符的回文子序列，两则字符的种类对应状态为
    // pre[i] & suf[i]
    // tc: O(n + |S|), sc:O(|S|)
public:
    int countPalindromicSubsequence(string s) {
        // I.
        // int n = s.size();
        // int res = 0;
        // // 枚举两侧字符
        // for (char ch = 'a'; ch <= 'z'; ch++) {
        //     int l = 0, r = n - 1;
        //     // 寻找首次出现的下标
        //     while (l < n && s[l] != ch) {
        //         l++;
        //     }
        //     // 寻找最后一次出现的下标
        //     while (r >= 0 && s[r] != ch) {
        //         r--;
        //     }
        //     if (r - l < 2) {
        //         // 该字符未出现两次
        //         continue;
        //     }
        //     // 哈希统计s[l+1:r-1]子串字符数量
        //     unordered_set<char> charset;
        //     for (int k = l + 1; k < r; k++) {
        //         charset.insert(s[k]);
        //     }
        //     res += charset.size();
        // }
        // return res;
        // II. 
        int n = s.size();
        int res = 0;
        // 前后缀字符状态数组
        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; i++) {
            // 前缀 s[0:i-1] 包含的字符种类
            pre[i] = (i ? pre[i - 1] : 0) | (1 << (s[i] - 'a'));
        }
        for (int i = n - 1; i >= 0; i--) {
            // 后缀 s[i+1:n-1]包含的字符种类
            suf[i] = (i != n - 1 ? suf[i + 1] : 0) | (1 << (s[i] - 'a'));
        }
        // 回文子序列的状态数组
        vector<int> ans(26);
        for (int i = 1; i < n - 1; i++) {
            ans[s[i] - 'a'] |= (pre[i - 1] & suf[i + 1]);
        }
        // 更新答案
        for (int i = 0; i < 26; i++) {
            res += __builtin_popcount(ans[i]); // 计算ans[i]中1的个数即可
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countPalindromicSubsequence
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "aabca"\n
// @lcpr case=end

// @lcpr case=start
// "adc"\n
// @lcpr case=end

// @lcpr case=start
// "bbcbaba"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3714 lang=cpp
 * @lcpr version=30204
 *
 * [3714] 最长的平衡子串 I
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
    // 注意只包含三种字母"abc"
    // I. 枚举+前缀和+哈希表
    // 我们仅仅考虑三种情况的题解即可：
    // 1. 求解仅包含一种字符的最长平衡子串
    // 2. 求解仅包含两种字符的最长平衡子串
    // 3. ...      三种 ... 
    // 1: 最简单，从左向右遍历字符串s, 维护变量last表示连续多少个字符与当前字符相同（包括当前）
    //    假设遍历到i, i>0 && s[i] = s[i - 1], last++; 否则last置1
    // 2: 首先枚举两种字符（可能是(a, b), (b, c), (a, c)），以(a, b)为例
    //    字符串会被字符c分割成若干子串，接下来我们将每个子串视作独立的字符串处理
    //    我们使用数组S_a, S_b分别统计前缀（分割后子串的前缀）中a,b的个数，
    //    S_a[i]: 字符串前i个字符有多少个a, 若子串s[i:j]中字符a,b个数相等，应有：
    //    S_a[j] - S_a[i - 1] = S_b[j] - S_b[i - 1]
    //    移项：S_a[j] - S_b[j] = S_a[i - 1] - S_b[i - 1]
    //    所以我们从小到大枚举j, 找到令上式相等的最小i即可，若存在，用j-i+1更新答案
    //    用哈希表记录每个S_a[i] - S_b[i]最早出现的位置，加快查询
    // 3: 同理设S_a, S_b, S_c, s[i:j]平衡，则：
    //    S_a[j] - S_b[j] = S_a[i - 1] - S_b[i - 1], 且
    //    S_b[j] - S_c[j] = S_b[i - 1] - S_c[i - 1]
    //    用哈希表记录每个二元组(S_a[i] - S_b[i], S_b[i] - S_c[i])最早出现的位置即可。
    // tc: O(n), sc: O(n)
public:
    int case2Helper(string& s, char x, char y) {
        int n = s.size();
        int res = 0; 
        unordered_map<int, int> h;
        for (int i = 0; i < n; i++) {
            if (s[i] != x && s[i] != y) {
                continue;
            }

            h.clear();
            // 分割后的子串开头，两种字符出现次数之差为0,
            // 需要提前存放到哈希表中
            h[0] = i - 1;
            int diff = 0;
            while (i < n && (s[i] == x || s[i] == y)) {
                diff += (s[i] == x) ? 1: -1;
                if (h.find(diff) != h.end()) { // h.contains(diff)
                    res = max(res, i - h[diff]);
                } else {
                    h[diff] = i;
                }
                i++;
            }
        }
        return res;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        // 情况1：仅包含一种字符
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                last++;
            } else {
                last = 1;
            }
            res = max(res, last);
        }

        // 情况2：包含2种字符
        res = max(res, case2Helper(s, 'a', 'b'));
        res = max(res, case2Helper(s, 'b', 'c'));
        res = max(res, case2Helper(s, 'a', 'c'));

        // 情况3：包含3种字符
        // 将二元组压缩为长整型，方便作为键存放至哈希表
        // 由于前缀和只差可能为负数，统一+n
        auto getId = [&](int x, int y) -> long long {
            return 1ll * (x + n) << 32 | (y + n);
        };

        // 字符串开头，位置为-1的地方，键值对为getId(0, 0)
        unordered_map<long long, int> h = {{getId(0, 0), -1}};
        int pre[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            pre[s[i] - 'a']++;
            long long id = getId(pre[1] - pre[0], pre[1] - pre[2]);
            if (h.find(id) != h.end()) {
                res = max(res, i - h[id]);
            } else {
                h[id] = i;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3713 lang=cpp
 * @lcpr version=30204
 *
 * [3713] 最长的平衡子串 I
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
    // I. 枚举
    // 枚举每个子串，然后找出最长平衡子串即可
    // 枚举左端点i, 然后枚举子串右端点j(i <= j < n)
    // 枚举右端点过程中，使用哈希表cnt统计每个字符出现次数
    // 遍历cnt, 判断当前子串[i, j]是否由个数相同的不同字符组成，是则更新
    // tc: O(C * n^2) (C: 字符集大小，本题中为26), sc: O(C)
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        vector<int> cnt(26);

        for (int i = 0; i < n; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;
                for (auto x: cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = max(res, j - i + 1);
                }
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
// "zzabccy"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

 */


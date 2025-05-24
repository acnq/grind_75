/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
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
    // 滑动窗口
    // 用哈希表判断是否有重复字符
    // 左指针右移的时候，移除字符
    // 右指针右移，则添加字符
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char> occ;
        // int n = s.size();
        // // 右指针，初始化为-1，相当于在字符串左边界之左侧
        // int rk = -1, ans = 0;
        // // 枚举左指针，初始值也为-1
        // for (int i = 0; i < n; i++)
        // {
        //     if (i != 0)
        //     {
        //         // 左指针右移一格，移除一个字符
        //         occ.erase(s[i - 1]);
        //     }
        //     while (rk + 1 < n && !occ.count(s[rk + 1]))
        //     {
        //         // 不断右移右指针
        //         occ.insert(s[rk + 1]);
        //         rk++;
        //     }
        //     // 第i到rk是一个极长无重复子串
        //     ans = max(ans, rk - i + 1);
        // }
        // return ans;
        // 使用模板
        // for(int l = 0, r = 0; r < n; r++) {
        //     //当前考虑元素
        //     while (l <= r && check())
        //     {
        //         // [l, r]不符合提议
        //         // 扩展左边界
        //     }
        //     // [l, r]不符合提议，统计相关信息
        // }
        unordered_set<char> occ;
        int n = s.size();
        int res = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            // 每一轮右端点都扩充一个
            char ch = s[right];
            while (occ.count(ch))
            {
                // occ 中有ch, 缩短左边界，出元素
                occ.erase(s[left]);
                left++;
            }
            occ.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */


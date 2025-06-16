// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
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
    // 方法还挺多
    // I. 横向扫描
    // LCP(S_1, ..., S_n): S_1,..., S_n的最长公共前缀
    // 可以用横向滚动的方法加速：
    // LCP(S_1, ..., S_n) = LCP(LCP(LCP(S_1, S_2), S_3),... S_n)
    // tc: O(mn)

    // II. 纵向扫描
    // 和我的想法一样，但是这里的写法比我好，提早return
    // tc: O(mn)

    // III. 分治法
    // LCP(S_1, ..., S_n) = LCP(LCP(S_1, ..., S_k), LCP(S_{k + 1}, ..., S_n))
    // 于是问题LCP(S_i, ..., S_j)总可以分解为LCP(S_i, ..., S_{mid})和LCP(S_{mid + 1}, ..., S_j)
    // tc: T(n) = 2 * T(n / 2) + O(m) => T(n) = O(mn)
    // sc: O(m logn)

    // IV. 二分查找
    // 显然最长公共子前缀的长度不会超过字符串数组中最短字符串的长度
    // minLen: 字符串数组中最短字符串的长度，我们直接在[0, minLen]的范围内通过二分查找得到LCP.
    // 每次取查找范围的中间值mid, 判断每个字符串的长度为mid的前缀是否相同
    // 倘若相同，则LCP的长度一定>=mid, 否则<, 于是查找范围立刻缩小一半
    // tc: O(mnlogm)

public:
    // I.
    string longestCommonPrefix(const string& str1, const string& str2) {
        int len = min(str1.size(), str2.size());
        int idx = 0;
        while(idx < len && str1[idx] == str2[idx]) {
            idx++;
        }
        return str1.substr(0, idx);
    }

    // III.
    string longestCommonPrefix(const vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        } else {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    string commonPrefix(const string& lcpLeft, const string lcpRight) {
        int minLen = min(lcpLeft.size(), lcpRight.size());
        for(int i = 0; i < minLen; i++) {
            if(lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minLen);
    }

    // IV.
    bool isCommonPrefix(const vector<string>& strs, int len) {
        string str0 = strs[0].substr(0, len);
        int cnt = strs.size();
        for(int i = 1; i < cnt; i++) {
            string str = strs[i];
            for(int j = 0; j < len; j++) {
                if(str0[j] != str[j]) {
                    return false;
                }
            }
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        // string ans;
        // int n = strs.size(), m = strs[0].size();
        // if(n == 1) {
        //     return strs[0];
        // }

        // bool flag = true;
        // for(int i = 0; i < m && flag; i++) {
        //     for(int j = 1; j < n; j++) {
        //         if(i >= strs[j].size() || strs[j][i] != strs[0][i]) {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag) {
        //         ans += strs[0][i];
        //     }
        // }
        // return ans;
        // 12min, if(flag)那步想了想

        // I. 
        // string prefix = strs[0];
        // int cnt = strs.size();
        // for(int i = 1; i < cnt; i++) {
        //     prefix = longestCommonPrefix(prefix, strs[i]);
        //     if(!prefix.size()) {
        //         break;
        //     }
        // }
        // return prefix;

        // II.
        // int len = strs[0].size();
        // int cnt = strs.size();
        // for(int i = 0; i < len; i++) {
        //     char c = strs[0][i];
        //     for(int j = 1; j < cnt; j++) {
        //         if(i == strs[j].size() || strs[j][i] != c) {
        //             return strs[0].substr(0, i); // 早return
        //         }
        //     }
        // }
        // return strs[0];

        // III.
        // return longestCommonPrefix(strs, 0, strs.size() - 1);

        // IV.
        int minLen = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {
            return s.size() < t.size();
        }) ->size();
        int low = 0, high = minLen;
        while(low < high) {
            int mid = (high - low + 1) / 2 + low;
            if(isCommonPrefix(strs, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3614 lang=cpp
 * @lcpr version=30204
 *
 * [3614] 用特殊操作处理字符串 II
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
    // I. 反推
    // 因为字符串长度扩展到10^5，直接模拟计算字符串result计算代价过大
    // 我们从构造result的4条规则入手，反推最终的k在result中对应的位置
    // k如果超过result的下标索引，则返回'.', 
    // 首先模拟result的长度len, k + 1 > len: retun '.'
    // 然后我们开始倒推构造k,注意要倒序遍历，
    // 同时维护k和len, 且每一步都满足k + 1 <= len
    // 1. 如果字符是*, k位置不变，但是len+1, 补上删掉的最后字符
    // 2. 如果是#，k + 1 >\ceil{len/2}, k在复制的那一半，所以执行前
    //    k在k - \floor{len/2}出，若k + 1 <= \ceil{len/2}, 
    //    k不变.
    //    两种情况len都应该更新为len/2, （撤销result的复制）
    // 3. 如果是%，k变为len - k - 1, len不变
    // 4. 如果是字符，且k + 1 = len, 则当前k对应的就是答案，
    //              若k + 1 < len, len--, 删除最后一个字符
    // 如果s中只有操作，没有字符，则必有k + 1 <= len, 此算法会直接返回.
    // 如果s中有前导无效操作，是的result在某段时间空串，注意到
    // 我们倒序遍历，所以k也一定会在前导操作之前就返回，
    // tc: O(n), sc: O(1)
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (auto c: s) {
            if (c == '*') {
                if (len) {
                    len--;
                }
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                continue;
            } else {
                len++;
            }
        }
        if (k + 1 > len) {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '#') {
                if (k + 1 > (len + 1) / 2) {
                    k -= len / 2;
                }
                len = len / 2;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else {
                if (k + 1 == len) {
                    return s[i];
                } else {
                    len--;
                }
            }
        }
        return '.';
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a#b%*"\n1\n
// @lcpr case=end

// @lcpr case=start
// "cd%#*#"\n3\n
// @lcpr case=end

// @lcpr case=start
// "z*#"\n0\n
// @lcpr case=end

 */


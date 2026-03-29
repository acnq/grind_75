/*
 * @lc app=leetcode.cn id=2840 lang=cpp
 * @lcpr version=30204
 *
 * [2840] 判断通过操作能否让字符串相等 II
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
    // I. 哈希
    // 显然,被交换的字符下标的奇偶性必然相等;
    // 所以对于给定字符串,将字符按照下标奇偶性划分为两个集合,
    // 这两个集合内部可以任意交换顺序,
    // 所以我们只消验证s1,s2在偶数下标集合和奇数下标集合上字符集相等(种类数量一致)即可
    // 我们同时遍历s1和s2,对s1中当前下标字符在对应集合的频次+1,s2则-1
    // 检验两个集合的元素是否全部归0,是则相等,否则不等
    //
    // tc: O(n), sc: O(1)
public:
    bool checkStrings(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdba"\n"cabdab"\n
// @lcpr case=end

// @lcpr case=start
// "abe"\n"bea"\n
// @lcpr case=end

 */


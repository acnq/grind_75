// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3120 lang=cpp
 * @lcpr version=30204
 *
 * [3120] 统计特殊字母的数量 I
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
public:
    int numberOfSpecialChars(string word) {
        // 一开始想错了，花了点时间，10min
        // int spec = 0;
        // unordered_map<char, int> seen;
        // for (char ch : word) {
        //     seen[ch]++;
        // }
        // for (auto [ch, cnt]: seen) {
        //     if ((seen[toupper(ch)] != 0) && (seen[tolower(ch)] != 0)){
        //         spec++;
        //     }
        // }
        // return spec / 2;

        // I. 标准答案写法: 用set就行了，不需要map
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numberOfSpecialChars
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "aaAbcBC"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "abBCab"\n
// @lcpr case=end

// @lcpr case=start
// "AA"\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=696 lang=cpp
 * @lcpr version=30204
 *
 * [696] 计数二进制子串
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
    // O. 又看答案了，这个技法太巧妙了QAQ
    // 将s转化成连续字符个数统计的数组cnts
    // e.g. s = "00110011", cnts = [2, 2, 2,2]
    // 那么我们发现，假设cnts中相邻的两个数值为u，v
    // 那么总有一个长度为min(u, v)的子串可以加入到答案中
    // 所以答案只需我们遍历cnt即可, 15min写完
    // 答案写法为I. tc: O(n), sc: O(n)
    // II
    // 由于我们在counts的每个位置i实际上只关心i-1的counts值，
    // 所以我们用一个变量last来维护当前记录的前一个位置，省去counts的空间
public:
    // I
    int countBinarySubstrings(string s) {
        // O.
        // vector<int> cnts;
        // int cnt = 1, res = 0;
        // for (int i = 0; i < s.size() - 1; i++) {
        //     if (s[i] == s[i + 1]) {
        //         cnt++;
        //     } else {
        //         cnts.push_back(cnt);
        //         cnt = 1;
        //     }
        // }
        // cnts.push_back(cnt);
        // for (int i = 0; i < cnts.size() - 1; i++) {
        //     res += min(cnts[i], cnts[i + 1]);
        // }
        // return res;
        
        // I.
        // vector<int> counts;
        // int ptr = 0, n = s.size();
        // while (ptr < n) {
        //     char c = s[ptr];
        //     int count = 0;
        //     while (ptr < n && s[ptr] == c) {
        //         ptr++;
        //         count++;
        //     }
        //     counts.push_back(count);
        // }
        // int ans = 0;
        // for (int i = 1; i < counts.size(); i++) {
        //     ans += min(counts[i], counts[i - 1]);
        // }
        // return ans;

        // II.
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ptr++;
                count++;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "00110011"\n
// @lcpr case=end

// @lcpr case=start
// "10101"\n
// @lcpr case=end

 */


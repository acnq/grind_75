/*
 * @lc app=leetcode.cn id=401 lang=cpp
 * @lcpr version=30204
 *
 * [401] 二进制手表
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

#include <bit>
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
    // O. 看答案了TAT，当时看到题目完全蒙了
    // 需要一点逆向思维，反向枚举：分别枚举小时数和分钟数（都不多）
    // 然后统计二者二进制表达式中1的个数，
    // 如果加起来和为turnedOn, 则加入答案，
    // I. 答案写法: tc = sc = O(1)
    // II. 二进制枚举
    // 枚举2^10 = 1024种开关灯组合，高4位为小时，低6位为分钟
    // 若枚举所得的小时分钟在合理范围内，而且1个数为turnedOn则加入答案
    // tc = sc = O(1)
public:
    int popcount(int n) {
        int cnt = 0;
        // count 1 in n under 2bit repr
        while(n > 0) {
            if (n % 2 == 1) {
                cnt++;
            }
            n /= 2;
        }
        return cnt;
    }
    string formath(int n) {
        return to_string(n);
    }
    string formatm(int m) {
        if (m > 9) {
            return to_string(m);
        }  else {
            return "0" + to_string(m);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        // O.
        // vector<string> res;
        // for (int h = 0; h < 12; h++) {
        //     for (int m = 0; m < 60; m++) {
        //         if(popcount(h) + popcount(m) == turnedOn) {
        //             res.push_back(formath(h) + ":" + formatm(m));
        //         }
        //     }
        // }
        // return res;
        // I.
        // vector<string> ans;
        // for (int h = 0; h < 12; h++) {
        //     for (int m = 0; m < 60; m++) {
        //         if (popcount(h) + popcount(m) == turnedOn) {
        //             ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
        //         }
        //     }
        // }
        // II. 
        vector<string> ans;
        for (int i = 0; i < 1024; i++) {
            int h = i >> 6, m = i & 63; // 位运算取高4位和低6位
            if (h < 12 && m < 60 && popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */


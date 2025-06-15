// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1432 lang=cpp
 * @lcpr version=30204
 *
 * [1432] 改变一个整数能得到的最大差值
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

#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
    // 感觉一个贪心的策略是：
    // 求max则把第一个不是9的数字变成9（都是则不动）
    // 求min则考虑第一位是不是1，不是则变成1，是则从第二位开始看，不是0的变成0（都是则不动)
    // 这里的问题在于111的话要单独考虑，因为这样的化第二位开始看会变成100，但1要改则全改，又不能改成0
    // 所以
    // 其实统一的解决方案是如果第一位是1，那么第一位不能改，以后看到1都要和看到0一样直接跳过

    // I. 枚举
    // 由于x, y \in [0, 9], 所以最多只有10 * 10 = 100，
    // 双重循环
public:
    bool all1(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '1') {
                return false;
            }
        }
        return true;
    }
    int maxDiff(int num) {
        // string s = to_string(num);
        // int n = s.size();
        // // get max
        // char modigi = 0;
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == '9') {
        //         continue;
        //     } else {
        //         modigi = s[i];
        //         break;
        //     }
        // }
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == modigi) {
        //         s[i] = '9';
        //     }
        // }
        // int mx = stoi(s);

        // // get min
        // int mn = 0;
        // char modigi2 = 0;
        // string s2 = to_string(num);
        // if(all1(s2)) {
        //     mn = stoi(s2);
        //     return mx - mn;
        // } else if(s2[0] != '1' || n == 1) {
        //     modigi2 = s2[0];
        //     // mn = stoi(s2);
        //     for(int i = 0; i < n; i++) {
        //         if(s2[i] == modigi2) {
        //             s2[i] = '1';
        //         }
        //     }
        // } else {
        //     for(int i = 1; i < n; i++) {
        //         if(s2[i] == '0' || s2[i] == '1') {
        //             continue;
        //         } else {
        //             modigi2 = s2[i];
        //             break;
        //         }
        //     }
        // }
        // for(int i = 1; i < n; i++) {
        //     if(s2[i] == modigi2) {
        //         s2[i] = '0';
        //     }
        // }

        
        // mn = stoi(s2);       
        // int ans = mx - mn;
        // return ans;
        // 太繁琐了，感觉断断续续做了一个多小时，TAT

        // I.
        // auto change = [&](int x, int y) {
        //     string num_s = to_string(num);
        //     for(char& digit: num_s) {
        //         if (digit - '0' == x) {
        //             digit = '0' + y;
        //         }
        //     }
        //     return num_s;
        // };

        // int min_num = num;
        // int max_num = num;
        // for(int x = 0; x < 10; x++) {
        //     for(int y = 0; y < 10; y++) {
        //         string res = change(x, y);
        //         // 有否前导0
        //         if(res[0] != '0') {
        //             int res_i = stoi(res);
        //             min_num = min(min_num, res_i);
        //             max_num = max(max_num, res_i);
        //         }
        //     }// 这样如果有前导0就相当于直接枚举下一个
        // }
        // return max_num - min_num;
        // O(d^2 \log(num)) d=10;

        // II. 贪心
        auto replace = [](string& s, char x, char y) {
            for(char& digit: s) {
                if(digit == x) {
                    digit = y;
                }
            }
        };

        string min_num = to_string(num);
        string max_num = to_string(num);
        // 最高位换成9
        for(char digit: max_num) {
            if(digit != '9') {
                replace(max_num, digit, '9');
                break;
            }
        }
        // 最高位换成1
        // 或者找到一个与最高位不相等的高维替换成0
        for(int i = 0; i < min_num.size(); i++) {
            char digit = min_num[i];
            if (i == 0) {
                if (digit != '1') {
                    replace(min_num, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != min_num[0]) {
                    replace(min_num, digit, '0');
                    break;
                }
            }
        }

        return stoi(max_num) - stoi(min_num);
        // 思路一样的，但感觉官方的写法也没有简单多少。
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxDiff
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 555\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 123456\n
// @lcpr case=end

// @lcpr case=start
// 10000\n
// @lcpr case=end

// @lcpr case=start
// 9288\n
// @lcpr case=end


// @lcpr case=start
// 111\n
// @lcpr case=end



// @lcpr case=start
// 1101057\n
// @lcpr case=end
 */


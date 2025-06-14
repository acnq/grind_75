// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2566 lang=cpp
 * @lcpr version=30204
 *
 * [2566] 替换一个数字后的最大差值
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

#include <string> // 加上bitset才能有to_string
// @lcpr-template-end
// @lc code=start
class Solution {
    // 感觉最大的数字一定是把第一个不是9的数字改成9
    // 最小的数一定是把第一位改为0
public:
    int minMaxDifference(int num) {
        // vector<int> digits1, digits2;
        // while(num > 0) {
        //     int digit = num % 10;
        //     digits1.push_back(digit);
        //     digits2.push_back(digit);
        //     num = num / 10;
        // }
        // reverse(digits1.begin(), digits1.end());
        // reverse(digits2.begin(), digits2.end());
        // // get maximu
        // int i = 0;
        // while(i < digits1.size() && digits1[i] == 9) {
        //     i++;
        // }

        // if(i != digits1.size()) {
        //     int modig = digits1[i];
        //     for(int j = i; j < digits1.size(); j++) {
        //         if (digits1[j] == modig) {
        //             digits1[j] = 9;
        //         }
        //     }
        // } 
        
        // int mx = 0;
        // for(int j = 0; j < digits1.size(); j++) {
        //     mx *= 10;
        //     mx += digits1[j];
        // } 

        // // get minimum
        // int midigit = digits2[0];
        // for(int j = 0; j < digits2.size(); j++) {
        //     if(digits2[j] == midigit) {
        //         digits2[j] = 0;
        //     }
        // }
        // int mn = 0;
        // for(int j = 0; j < digits2.size(); j++) {
        //     mn *= 10;
        //     mn += digits2[j];
        // }
        // return mx - mn;
        // 感觉写的有点繁琐，21'6"

        // 官方写法
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
        // 主要使用库函数加速了一下，思路一样的
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minMaxDifference
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 11891\n
// @lcpr case=end

// @lcpr case=start
// 90\n
// @lcpr case=end

// @lcpr case=start
// 99999999\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30204
 *
 * [67] 二进制求和
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
public:
    string addBinary(string a, string b) {
        // 这个方案有些数字会突破存储限制
        // long long 也不行
        // long long a_int = stoll(a, nullptr, 2);
        // long long b_int = stoll(b, nullptr, 2);
        // long long res_int = a_int + b_int;
        // if (res_int == 0)
        // {
        //     return "0";
        // } else {
        //     string res;
        //     while (res_int)
        //     {
        //         if (res_int % 2 == 1)
        //         {
        //             res.append(1, '1');
        //         } else {
        //             res.append(1, '0');
        //         }
                
        //         res_int /= 2;
        //     }
            
        //     reverse(res.begin(), res.end());
        //     return res;
        // }
        // string ans;
        // int carry = 0;
        // int N = max(a.size(), b.size());
        // 变体(也会超过long long限制)
        // long long x = stoll(a, nullptr, 2);
        // long long y = stoll(b, nullptr, 2);
        // while (y)
        // {
        //     long long ans = x ^ y;
        //     long long carry = (x & y) << 1;
        //     x = ans;
        //     y = carry;
        // }
        // if(x == 0 && y == 0) return "0";
        // return bitset<64>(x).to_string().substr(bitset<64>(x).to_string().find('1'));


        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());
        // // 这里不reverse，下面i从小端开始加会有问题：i的初始值很难确定
        // for (int i = 0; i < N; i++)
        // {
        //     if (i > a.size() - 1)
        //     {
        //         if (carry == 1)
        //         {
        //             if (b[i] == '1')
        //             {
        //                 ans.push_back('0');
        //                 carry = 1;
        //             } else {
        //                 ans.push_back('1');
        //                 carry = 0;
        //             }
        //         } else
        //         {
        //             ans.push_back(b[i]);
        //         }
        //     } else if (i > b.size() - 1)
        //     {
        //         if (carry == 1)
        //         {
        //             if (a[i] == '1')
        //             {
        //                 ans.push_back('0');
        //                 carry = 1;
        //             } else {
        //                 ans.push_back('1');
        //                 carry = 0;
        //             }
        //         } else
        //         {
        //             ans.push_back(a[i]);
        //         }
        //     } else {
        //         if (carry == 1)
        //         {
        //             if (a[i] == '0')
        //             {
        //                 if (b[i] == '0')
        //                 {// 1 + 0 + 0 = 1
        //                     ans.push_back('1');
        //                     carry = 0;
        //                 } else { //b[i] == '1'
        //                     // 1 + 1 + 0 = 10
        //                     ans.push_back('0');
        //                     // carry = 1;
        //                 }
        //             } else { // a[i] == '1'
        //                 if (b[i] == '0')
        //                 {// 1 + 1 + 0 = 10
        //                     ans.push_back('0');
        //                     // carry = 1;
        //                 } else { // b[i] == '1'
        //                     // 1 + 1 + 1 = 11
        //                     ans.push_back('1');
        //                     // carry = 1;
        //                 }
        //             }
        //         } else { // carry = 0
        //             if (a[i] == '0')
        //             {
        //                 if (b[i] == '0')
        //                 {// 0 + 0 + 0 = 0
        //                     ans.push_back('0');
        //                     carry = 0;
        //                 } else { //b[i] == '1'
        //                     // 0 + 1 + 0 = 1
        //                     ans.push_back('1');
        //                     // carry = 0;
        //                 }
        //             } else { // a[i] == '1'
        //                 if (b[i] == '0')
        //                 {// 0 + 1 + 0 = 1
        //                     ans.push_back('1');
        //                     // carry = 0;
        //                 } else { // b[i] == '1'
        //                     // 0 + 1 + 1 = 10
        //                     ans.push_back('0');
        //                     carry = 1;
        //                 }
        //             }
        //         }
                
        //     }
        // }
        // if (carry)
        // {
        //     ans.push_back('1');
        // }
        
        // reverse(ans.begin(), ans.end());
        // return ans;

        // 化简一下
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int N = max(a.size(), b.size());
        int carry = 0;

        for (int i = 0; i < N; i++)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1': '0');
            carry /= 2;
        }
        
        if (carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */


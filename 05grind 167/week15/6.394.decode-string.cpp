/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30204
 *
 * [394] 字符串解码
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

#include <string> // stoi
// @lcpr-template-end
// @lc code=start
class Solution {
    // 注意看实例2， 可以有[]嵌套的情况，
    // I. 栈
    // 把数位，字符，括号看做独立的token
    // 1. 当前字符为数位，解析出数字入栈
    // 2.          左括号，直接入栈
    // 3.          右括号，开始出栈，一直到左括号出栈，出栈的序列拼成字符串
    //                    然后取出栈顶数字，重复这个数构造字符串后入栈
    // 最终答案就是将栈中的元素从底到顶拼接起来
    // 我们用不定长数组来模拟栈操作，方便自底到顶遍历

    // II. 递归
    // 思考这样的巴克斯范式BNF:
    // string -> digits[string]string | alpha string | e
    // digits -> digit digits | digit
    // alpha -> a|...|z|A|...|Z
    // digit -> 0|.....|9
    // 这是LL(1)文法，从左向右分析，最左推导，一符号前瞻
public:
    // I.
    // string getDigits(string& s, size_t& ptr) {
    //     string ret = "";
    //     while (isdigit(s[ptr]))
    //     {
    //         ret.push_back(s[ptr]);
    //         ptr++;
    //     }
    //     return ret;
    // }

    // string getString(vector<string>& v) {
    //     string ret;
    //     for (const auto& s: v) {
    //         ret += s;
    //     }
    //     return ret;
    // }

    // II.
    string src;
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr]))
        {
            ret = ret * 10 + src[ptr] - '0';
            ptr++;
        }
        return ret;
    }
    string getString() {
        if (ptr == src.size() || src[ptr] == ']')
        {
            // string->eps
            return "";
        }
        char cur = src[ptr];
        int rept = 1;
        string ret;

        if (isdigit(cur))
        {
            // string -> digits [string] string
            // 解析digits
            rept = getDigits();
            // 过滤左括号
            ptr++;
            // 解析string
            string str = getString();
            // 过滤右括号
            ptr++;
            // 构造字符串
            while (rept--)
            {
                ret += str;
            }
        } else if (isalpha(cur))
        {
            // string -> char string
            // 解析char
            ret = string(1, src[ptr]);
            ptr++;
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        // I.
        // vector<string> stk; // 不定长数组模拟栈
        // size_t ptr = 0;

        // while (ptr < s.size())
        // {
        //     char cur = s[ptr];
        //     if (isdigit(cur))
        //     {
        //         // 获取所有数位并入栈
        //         string digits = getDigits(s, ptr);
        //         stk.push_back(digits);
        //     } else if (isalpha(cur) || cur == '[')
        //     {
        //         // 获取一个字母并入栈
        //         stk.push_back(string(1, s[ptr]));
        //         ptr++;
        //     } else {
        //         // 遇到']'开始出栈
        //         ptr++;
        //         vector<string> sub; // 需要是vector<string>
        //         // 因为有3[4[a]5[b]]这种情况，括号内可能对应多组string
        //         while (stk.back() != "[")
        //         {
        //             sub.push_back(stk.back());
        //             stk.pop_back();
        //         }
        //         reverse(sub.begin(), sub.end());
        //         // 左括号出栈
        //         stk.pop_back();
        //         // 取出栈顶数字
        //         int rept = stoi(stk.back());
        //         stk.pop_back();
        //         string t, o = getString(sub);
        //         // 构造字符串
        //         while (rept--)
        //         {
        //             t += o;
        //         }
        //         stk.push_back(t);
        //     }
        // }
        // return getString(stk);

        // II.
        src = s;
        ptr = 0;
        return getString();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */


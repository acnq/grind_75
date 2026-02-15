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
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 模拟：
    // 列竖式，n = max{|a|, |b|}, 循环n次，用carry表示进位
    // 记录当前位置两个位为a_i, b_i, 每一位答案为(carry + a_i + b_i) % 2;
    // carry = \floor{(carry + a_i + b_i) / 2}, 重复直到a,b每一位计算完毕，
    // 如果carry最高位不为0，则最高位要添加到末尾
    // 注意为了对其各个位置，我们要反转这两个字符串。
    // tc: O(n), sc: O(1)

    // II. 位运算：
    // a, b转换成整型数字x,y, 分别保存结果和进位
    // 进位不为0时：
    //  1. 计算当前x,y的无进位加法结果：answer = x ^ y
    //  2. 计算当前x,y的进位：carry = (x & y) << 1
    //  3. 完成本次循环，更新x = answer, y = carry
    // 返回x的二进制形式
    // tc: O(|a| + |b| + X * max(|a| + |b|)), 字符串化为数字要O(|a| + |b|), X：位运算用时
    // sc: O(|a| + |b|)
public:
    string addBinary(string a, string b) {
        // I.
        // string ans;
        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());

        // int n = max(a.size(), b.size()), carry = 0;
        // for (size_t i = 0; i < n; i++) {
        //     carry += i < a.size() ? (a.at(i) == '1') : 0;
        //     carry += i < b.size() ? (b.at(i) == '1') : 0;
        //     ans.push_back((carry % 2) ? '1': '0');
        //     carry /= 2;
        // }

        // if (carry) {
        //     ans.push_back('1');
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;

        // II.
        string result = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
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


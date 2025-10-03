/*
 * @lc app=leetcode.cn id=166 lang=cpp
 * @lcpr version=30204
 *
 * [166] 分数到小数
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
    // I. 长除法
    // 如果除法的结果是整数，则只需记得将结果转化为字符串即可
    // 如果不能，则模拟竖式除法，首先确定正负（此时分子分母都不为0）
    // 然后计算绝对值，首先计算整数部分：
    // 1. 如果结果是复数，则将负号拼接到结果中，否则直接到2；
    // 2. 整数拼接到结果中；
    // 3. 小数点拼接到结果中
    // 然后计算小数部分：
    // 每次余数*10，计算下一位数字，得到新的余数。
    // 1. 余数为0，则结果有限，拼接小数部分即可
    // 2. 找到循环节，则将其开始和结束为止加上括号，然后将其拼接到结果
    // 如何判断循环节？如果某一位的余数在之前已经出现过了，就找到了循环节
    // 为此，只需要使用哈希表存储每个余数在小数部分第一次出现的下标
    // 假设计算小数部分第i位之前，余数为re_i, 第i位之后，余数为re_{i+1}
    // 如果有j,k s.t. j <= k, 且re_j = re_{k+1}, 则j-k位是循环节
    // tc = sc = O(l)
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorl = numerator;
        long denominatorl = denominator;
        if (numeratorl % denominatorl == 0) {
            return to_string(numeratorl / denominatorl);
        }
        string ans;
        if (numeratorl < 0 ^ denominatorl < 0) {
            ans.push_back('-');
        }

        // 整数部分
        numeratorl = abs(numeratorl);
        denominatorl = abs(denominatorl);
        long integerPart = numeratorl / denominatorl;
        ans += to_string(integerPart);
        ans.push_back('.');

        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorl % denominatorl;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorl);
            remainder %= denominatorl;
            index++;
        }
        if (remainder != 0) {
            // 有循环节
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        ans += fractionPart;

        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n333\n
// @lcpr case=end

 */


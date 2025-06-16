// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
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
    // 不会要实现99乘法表叭，太繁琐了，直接看答案叭TAT
    // I. 加法
    // 我们设定num_1为被乘数，num_2为乘数，
    // 模拟竖式，但每次都只把乘数的每一位与被乘数相乘
    // 然后补零累加即得结果
    // tc: O(mn + n^2), 计算乘积mn, 相加操作n^2, sc: O(m + n)

    // II. 乘法
    // 我们思考nums1和nums2的长度m和n, 则二者乘积的长度为m + n - 1或者m + n;
    // 创建长度为m + n 的数组ansArr用于存储，任意i, j; num1[i] * num2[j]结果必然累加到
    // ansArr[i + j + 1]上，如果此项>=10, 进位部分要加到ansArr[i + j];
    // 这样就不用累加的部分了，tc: O(mn), sc: O(m + n)
public:
    // I.
    string addStrings(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c: ans) {
            c += '0';
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        // I.
        // if (num1 == "0" || num2 == "0") {
        //     return "0";
        // }
        // string ans = "0";
        // int m = num1.size(), n = num2.size();
        // for (int i = n - 1; i >= 0; i--) {
        //     string curr;
        //     int add = 0;
        //     for (int j = n - 1; j > i; j--) {
        //         curr.push_back(0);
        //     }
        //     int y = num2.at(i) - '0';
        //     for (int j = m - 1; j >= 0; j--) {
        //         int x = num1.at(j) - '0';
        //         int prod = x * y + add;
        //         curr.push_back(prod % 10); // + '0' 统一放到最后了
        //         add = prod / 10;
        //     }
        //     while (add != 0) {
        //         curr.push_back(add % 10);
        //         add /= 10;
        //     }
        //     reverse(curr.begin(), curr.end());
        //     for (auto& c : curr) {
        //         c += '0';
        //     }
        //     ans = addStrings(ans, curr);
        // }
        // return ans;

        // II.
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y; // 进位在下一个循环处理
            }
        }
        for(int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto& c: ans) {
            c += '0';
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */


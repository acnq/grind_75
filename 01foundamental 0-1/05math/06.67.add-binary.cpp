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
    // I. 模拟
    // 每一位的答案是（carry + a_i + b_i) mod 2;
    // 下一位的进位为\floor{(carry + a_i + b_i) / 2}
    // 这样就不用分类讨论了
public:
    // long long mystoi(string binary) {
    //     long long ans = 0;
    //     int n = binary.size();
    //     for(int i = 0; i < n; i++) {
    //         ans *= 2;
    //         ans += ((binary[i] == '1') ? 1 : 0);
    //     }
    //     return ans;
    // }; 同样不行，还是会溢出

    string addBinary(string a, string b) {
        // int numa = stoi(a, 0, 2); // 这个不行，a和b都有可能out_of_range
        // int numb = stoi(b, 0, 2);
        // 只能模拟加法
        // long long numa = mystoi(a);
        // long long numb = mystoi(b);
        // long long res = numa + numb;
        // if(res == 0) {
        //     return "0";
        // }
        // string ans = "";
        // while(res > 0) {
        //     ans += ((res % 2 == 1) ? '1' : '0');
        //     res /= 2;
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        // string ans = "";
        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());
        // int na = a.size(), nb = b.size();
        // int carry = 0, n = min(na, nb);
        // for(int i = 0; i < n; i++) {
        //     if(a[i] == '0' || b[i] == '0') {
        //         // 感觉要讨论的情况太多了，看答案吧。。。
        //     }
        // }
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for(size_t i = 0; i < n; i++) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
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


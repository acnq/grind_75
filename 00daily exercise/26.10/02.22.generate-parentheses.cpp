/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    // I. 直接递归生成所有序列，然后遍历判断是否有效即可
    // tc: O(2^(2n) * n); sc: O(n);

    // II. 回溯
    // 通过跟踪目前为止遇到的左右括号数目来回溯：
    // 1. 如果左括号数目不大于n, 我们可以放一个左括号
    // 2. 如果右括号数目小于左括号数目，我们可以放一个右括号
    // tc: O(4^n/sqrt(n))[第n个卡特兰数]; sc: O(n)

    // III. 按括号长度递归
    // 每个括号序列可以表示为(a)b, a/b为一个可空的合法括号序列
    // generate(n)返回所有可能的长度为2 * n的括号序列，那么我们要：
    // 1. 枚举第一个'('对应的')'的位置2i + 1；
    // (显然第一个左括号和它对应的右括号应该隔2i个字符，i.e. i对括号)
    // i <= n - 1;
    // 2. 递归调用generate(i) 计算a的所有可能性；
    // 3. 递归调用generate(n - i - 1), 计算b的所有可能性；
    // 4. 拼接a/b
    // generate(i)的结果应当储存起来以方便重复计算
    // tc = sc = O(4^n/sqrt(n))
public:
    // I.
    // bool valid(const string& str) {
    //     int balance = 0;
    //     for (char c : str) {
    //         if (c == '(') {
    //             balance++;
    //         } else {
    //             balance--;
    //         }
    //         if (balance < 0)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // 
    // void generate_all(string& current, int n, vector<string>& res) {
    //     if (n == current.size()) {
    //         if (valid(current)) {
    //             res.push_back(current);
    //         }
    //         return;
    //     }
    //     current += '(';
    //     generate_all(current, n, res);
    //     current.pop_back();
    //     current += ')';
    //     generate_all(current, n, res);
    //     current.pop_back();
    // }

    // II. 
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if  (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
    
    // III.
    // shared_ptr<vector<string>> cache[100] = {nullptr};
    // shared_ptr<vector<string>> generate(int n) {
    //     if (cache[n] != nullptr) {
    //         return cache[n];
    //     }
    //     if (n == 0) {
    //         cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
    //     } else {
    //         auto result = shared_ptr<vector<string>>(new vector<string>);
    //         for (int i = 0; i != n; i++) {
    //             auto lefts = generate(i);
    //             auto rights = generate(n - i - 1);
    //             for (const string& left: *lefts){
    //                 for (const string& right: *rights) {
    //                     result->push_back("(" + left + ")" + right);
    //                 }
    //             }
    //         }
    //         cache[n] = result;
    //     }
    //     return cache[n];
    // }
    
    vector<string> generateParenthesis(int n) {
        // I.
        // vector<string> result;
        // string current;
        // generate_all(current, n * 2, result);
        // return result;

        // II.
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;

        // III.
        // return *generate(n);

    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


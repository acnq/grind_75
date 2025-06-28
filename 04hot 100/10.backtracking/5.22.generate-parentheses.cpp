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
    // I. 暴力法
    // 我们直接生成所有可能的()字符的序列，一一检查是否有效
    // 递归生成，长度为i的序列就是长度为i-1的序列后加一个(或)，总共2^(2n)种
    // 用balance判断序列是否符合，balance表示每个位置左括号减去右括号的数量
    // 如果任意位置balance < 0则无效，结束时balance != 0也无效，否则有效。
    // tc: O(2^(2n) * n); sc: O(n)

    // II. 回溯法
    // 我们没必要每次添加再验证，而是只在验证有效时添加，
    // 通过跟踪目前为止左括号和右括号的数目来实现，如果左括号数目不大于n, 可添加左括号
    // 如果右括号数目小于左括号数目，可以添加右括号
    // tc: O(Cat(n) * n) = O(4^n / sqrt(n)), sc: O(n)

    // III. 按长度递归
    // 每个序列都可以概括为'(a)b', a, b分别为一个合法的序列（可空）
    // 定义generate(n), 返回所有可能的括号序列 
    //  1. 枚举与第一个'('对应的')'的位置2i + 1;
    //  2. 递归调用所有generate(i)即可计算所有a;
    //  3. 递归调用所有generate(n - i - 1)即可计算所有b
    //  4. 遍历a, b的可能性，即可得多所有长度为2n的括号序列
public:
    // I.
    bool valid(const string& str) {
        int balance = 0;
        for (char c: str) {
            if (c == '(')
            {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0)
            {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string& cur, int n, vector<string>& res) {
        if (n == cur.size())
        {
            if (valid(cur))
            {
                res.push_back(cur);
            }
            return;
        }
        cur += '(';
        generate_all(cur, n, res);
        cur.pop_back();
        cur += ')';
        generate_all(cur, n, res);
        cur.pop_back();
    }

    // II.
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        // open: 左括号数目，close: 右括号数目
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }

        if (open < n)
        {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open)
        {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

    // III.
    shared_ptr<vector<string>> cache[100] = {nullptr};
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr)
        {
            return cache[n];
        }
        if (n == 0)
        {
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        } else {
            auto res = shared_ptr<vector<string>> (new vector<string>);
            for (int i = 0; i != n; i++)
            {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left: *lefts) {
                    for (const string& right: *rights) {
                        res->push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = res;
        }
        return cache[n];        
    }

    vector<string> generateParenthesis(int n) {
        // I.
        // vector<string> res;
        // string cur;
        // generate_all(cur, n * 2, res);
        // return res;

        // II.
        // vector<string> res;
        // string cur;
        // backtrack(res, cur, 0, 0, n);
        // return res;

        // III.
        return *generate(n);
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


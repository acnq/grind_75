/*
 * @lc app=leetcode.cn id=301 lang=cpp
 * @lcpr version=30204
 *
 * [301] 删除无效的括号
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
    // I. 回溯 + 剪枝
    // 我们尝试所有可能的去掉非法括号的方案并找出最少者
    // 首先利用括号匹配规则求出s最少需要去掉的左右括号数目：
    // lrmv和rrmv, （这只需要一次遍历即可，维护未匹配的左括号数目
    // 遇到左括号，lrmv++, 遇到右括号判断lrmv是否为0，否lrmv--,
    // 是rrmv++) 
    // 然后我们尝试在s中去掉如此数量的左右括号
    // 简则剩余字符串是否能够匹配，用回溯法尝试所有可能得方案
    // 我们用剪枝技巧加速：
    // 1. 每去掉一个括号，更新lrmv/rrmv, 如果剩余未尝试的s长度
    //     小于lrmv+rrmv, 则停止搜索，该去除的括号甚至大于字符串长度
    //     一定出现错误删除；
    // 2. lrmv=rrmv=0, 说明删除数量满足要求，我们直接检测s是否有效
    // 我们最终还要去重，方法如下：
    // 搜索时，如果遇到连续相同的括号只需搜索一次，例如((((),
    // 去掉四个连续左括号的任何一个，生成结果一样，我们只需去掉一个
    // 直接进行下一轮搜索即可
    // tc: O(n * 2^n), sc: O(n^2)

    // II. BFS
    // BFS每一轮删除字符串中的一个括号，直到出现合法匹配为止
    // 注意我们保存上一轮搜索的结果，然后对这些结果的每个字符串尝试
    // 所有可能删除一个括号的方法，进入下一轮搜索，
    // 保存时我们用哈希表去重
    // 注意到我们轮转次数就是最少的删除括号个数，所以一旦有符合，
    // 直接返回此次搜索范围内所有符合条件的括号序列，一定都是删除最少的
    // tc：O(n * 2^n), sc: O(n * C_n^(n/2))

    // III. 太复杂且收益不高，略
public:
    // O.
    inline bool isValid(const string& str) {
        int cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
    // I.
    // vector<string> res;
    // void helper(string str, int start, int lrmv, int rrmv) {
    //     if (lrmv == 0 && rrmv == 0) {
    //         // 完成符合数目的删除，需要判断是否合法
    //         if (isValid(str)) {
    //             res.push_back(str);
    //         }
    //         return;
    //     }
    //     for (int i = start; i < str.size(); i++) {
    //         if (i != start && str[i] == str[i - 1]) {
    //             continue; // 去重
    //         }
    //         // 如果剩余字符无法满足删去的数目要求，直接返回
    //         if (lrmv + rrmv > str.size() - i) {
    //             return;
    //         }
    //         // 尝试去掉一个左括号
    //         if (lrmv > 0 && str[i] == '(') {
    //             helper(str.substr(0, i) + str.substr(i + 1), i, lrmv - 1, rrmv);
    //         }
    //         // 尝试去掉一个右括号
    //         if (rrmv > 0 && str[i] == ')') {
    //             helper(str.substr(0, i) + str.substr(i + 1), i, lrmv, rrmv - 1);
    //         }
    //     }
    // }
    
    vector<string> removeInvalidParentheses(string s) {
        // I.
        // int lrmv = 0; // Left paranthese need to ReMoVe,
        // int rrmv = 0; // Right paranthese need to ReMoVe,
        // 
        // for (char c: s) {
        //     if (c == '(') {
        //         lrmv++;
        //     } else if (c == ')') {
        //         if (lrmv == 0) {
        //             rrmv++;
        //         } else {
        //             lrmv--;
        //         }
        //     }
        // }
        //
        // helper(s, 0, lrmv, rrmv); // 回溯部分
        // return res;
    
        // II.
        // vector<string> ans;
        // unordered_set<string> curSet; // 去重
        //
        // curSet.insert(s);
        // while (true) {
        //     for (auto& str: curSet) {
        //         if (isValid(str)) {
        //             ans.emplace_back(str);
        //         }
        //     }
        //     if (ans.size() > 0) {
        //         return ans;
        //     }
        //     unordered_set<string> nextSet;
        //     for (auto& str: curSet) {
        //         for (int i = 0; i < str.size(); i++) {
        //             if (i > 0 && str[i] == str[i - 1]) {
        //                 continue;
        //             }
        //             if (str[i] == '(' || str[i] == ')') {
        //                 nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
        //             }
        //         }
        //     }
        //     curSet = nextSet;
        // }
    
    
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()())()"\n
// @lcpr case=end

// @lcpr case=start
// "(a)())()"\n
// @lcpr case=end

// @lcpr case=start
// ")("\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3093 lang=cpp
 * @lcpr version=30204
 *
 * [3093] 最长公共后缀查询
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

// I.
class Trie {
private:
    static constexpr int N = 500010, M = 26;
    // wordsContainer[i].length <= 5 * 10^5
    int tot_;
    int tr_[N][M];      // Trie结构：tr_[p][c]: 结点p通过c走到的下一个节点编号
    // 本质上是状态转移矩阵
    int min_len_[N];    // 该节点子树最短字符串的长度
    int idx_[N];        // 该最短字符串的编号
public:
    Trie(): tot_(0) {
        for (int i = 0; i < N; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
    }
    void clear() {
        for (int i = 0; i <= tot_; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
        tot_ = 0;
    }
    void insert(const string& s, int idx) {
        // 插入字符串s, 记录他的编号idx
        int p = 0;
        if (min_len_[p] > s.length()) {
            // 维护最小编号
            min_len_[p] = s.length();
            idx_[p] = idx;
        }
        for (auto& ch: s) {
            int c = ch - 'a';
            if (tr_[p][c] == 0) {
                tot_++;
                tr_[p][c] = tot_;
            }
            p = tr_[p][c];
            if (min_len_[p] > s.length()) {
                min_len_[p] = s.length();
                idx_[p] = idx;
            }
        }
    }

    int query(const string& s) {
        int p = 0;
        for (auto& ch: s) {
            int c = ch - 'a';
            if (tr_[p][c] != 0) {
                p = tr_[p][c];
            } else {
                break;
            }
        }
        return idx_[p]; // 返回历史最短的那个字符串
    }
};

Trie tr;

class Solution {
    // I. 字典树
    // 我们只要将每个字符串倒序插入字典树，就可以把问题转化为
    // 前缀字典树问题，
    // 只需要额外记录所有插入的字符串中，经过树节点
    // 长度最小的那个字符串的下标，
    // 以便查询是次后缀在哪个最短的字符串中出现即可
    // tc: O(N + M), sc: O(N)
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        tr.clear();
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        for (int i = 0; i < n; i++) {
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            tr.insert(s, i);
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            string s = wordsQuery[i];
            reverse(s.begin(), s.end());
            res[i] = tr.query(s);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcd","bcd","xbcd"]\n["cd","bcd","xyz"]\n
// @lcpr case=end

// @lcpr case=start
// ["abcdefgh","poiuygh","ghghgh"]\n["gh","acbfgh","acbfegh"]\n
// @lcpr case=end

 */


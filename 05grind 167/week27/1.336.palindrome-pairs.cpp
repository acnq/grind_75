/*
 * @lc app=leetcode.cn id=336 lang=cpp
 * @lcpr version=30204
 *
 * [336] 回文对
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

// 双指针判断是否回文，
bool IsPalindrome(const string& s, int i, int j) {
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// 字典树
struct Node
{
    Node* children[26];
    vector<int> words; // 当前节点包含完整单词的序号
    vector<int> suffixs; // 当前节点之后部分字符串能构成回文串的序号

    Node() {
        memset(children, 0, sizeof(children));
    }
};

class Solution {
    // I. 字典树
    // 对于字符串A和B, A+B存在两种情况，A1+A2+B, A1和B回文，A2自回文
    // A+B1+B2: 保证A和B2回文，B2自回文。
    // 具体思路：逆序单词构建字典树，同时判断当前字符串是否回文，是则加入suffix清单
    // 正序遍历单词，按照每个字母通过字典树判断是否回文，考虑上面讨论的两种情况累加
    // 因为起始节点不同，所以直接加入结果即可，不存在重复。
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node* root = new Node();
        int n = words.size(); // 基于逆序构建字典树
        for (int i = 0; i < n; i++)
        {
            // 反序
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());

            Node* cur = root;
            int nj = revWord.size();
            // 当前单词就可以构成回文串，则插入到suffix里面
            if (IsPalindrome(revWord, 0, nj - 1))
            {
                cur->suffixs.push_back(i);
            }
            for (int j = 0; j < nj; j++)
            {
                int c = revWord[j] - 'a';
                if (cur->children[c] == nullptr)
                {
                    cur->children[c] = new Node();
                }
                cur = cur->children[c];
                // 判断后续j+1:n部分是否可以构成回文串
                if (IsPalindrome(revWord, j + 1, nj - 1))
                {
                    cur->suffixs.push_back(i);
                }
            }
            // 表示这个节点对应于单词i的结束
            cur->words.push_back(i);
        }
        vector<vector<int>> res;
        // 再次正序遍历获取回文串对
        for (int i = 0; i < n; i++)
        {
            Node* cur = root;
            int j = 0;
            int nj = words[i].size();
            for ( ; j < nj; j++)
            {
                // 判断后续是否已经是回文，如果是则A1 + A2 + B
                if (IsPalindrome(words[i], j, nj - 1))
                {
                    // 排除自己的序号
                    for (int k: cur->words) {
                        if (k != i)
                        {
                            res.push_back({i, k});
                        }
                    }
                }
                
                // 找下一个节点，如果找不到则失败，则break
                int c = words[i][j] - 'a';
                if (cur->children[c] == nullptr)
                {
                    break;
                }
                cur = cur->children[c];
            }
            
            // 这里只考虑完全遍历完成的情况，构建A+B1+B2构建回文串
            if (j == nj)
            {
                for (int k: cur->suffixs) {
                    if (k != i)
                    {
                        res.push_back({i, k});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcd","dcba","lls","s","sssll"]\n
// @lcpr case=end

// @lcpr case=start
// ["bat","tab","cat"]\n
// @lcpr case=end

// @lcpr case=start
// ["a",""]\n
// @lcpr case=end

 */


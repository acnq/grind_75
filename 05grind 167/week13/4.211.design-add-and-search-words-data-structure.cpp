/*
 * @lc app=leetcode.cn id=211 lang=cpp
 * @lcpr version=30204
 *
 * [211] 添加与搜索单词 - 数据结构设计
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

struct TrieNode
{
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c: word) {
        if (node->child[c - 'a'] == nullptr)
        {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}
class WordDictionary {
    // I. 字典树
    // 对于搜索单词，如果当前字符是字母，则判断当前字符对应的子节点是否存在
    //                                若有，则移动到子节点，没有，则返回false
    //              如果当前字符是., 需要对所有非空子节点点继续搜索下一个字符
    //                              只要存在一个非空子节点可以搜索到给定单词，返回true。
    // tc: 添加O(|S|), 搜索O(|\sigma|^|S|), |S|: 添加/搜索单词长度，|\sigma|字符集长度=26
    // sc: O(|T|*|\sigma|), |T|所有添加单词的长度之和，|\sigma|=26
private:
    TrieNode* trie;

public:
    bool dfs(const string& word, int idx, TrieNode* node) {
        if (idx == word.size())
        {
            return node->isEnd;
        }
        char ch = word[idx];
        if (ch >= 'a' && ch <= 'z')
        {
            TrieNode* child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, idx + 1, child))
            {
                return true;
            }
        } else if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                TrieNode* child = node->child[i];
                if (child != nullptr && dfs(word, idx + 1, child))
                {
                    return true;
                }
            }
        }
        return false;
    }

    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(trie, word);
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end



/*
// @lcpr case=start
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"][[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]\n
// @lcpr case=end

 */


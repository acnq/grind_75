/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30204
 *
 * [208] 实现 Trie (前缀树)
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
class Trie {
public:
    // 有根树
    // 每个节点需要有：
    //      1. 指向子节点的指针数组children, children[0] 对应 a
    //      2. 布尔子段 isEnd。

    vector<Trie*> children;
    bool isEnd;

    // 插入字符串：
    // 当前字符对应的子节点：
    //      1. 对应的子节点存在：沿指针移到子节点，继续处理下一字符
    //      2. 对应的子节点不存在：创建新的子节点，记录在children数组对应的位置上，
    //          然后，沿指针移动到子节点，继续搜索下一个字符
    // 重复直到处理完最后一个字符

    // 查找字符串：
    // 查找前缀，对于当前字符对应的子节点：
    //      1. 对应的子节点存在：沿指针移动，继续搜索下一个字符
    //      2. 对应的子节点不存在：不包含该前缀，返回空指针
    // 重复直到最后一个字符，或者返回空指针
    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

    Trie(): children(26), isEnd(false) {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end




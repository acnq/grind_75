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
    // I. 字典树
    // 每个结点要包含如下子段：
    // 1. 指向子节点的指针数组children, 长度26， children[0]对应a,
    // 2. 布尔字段isEnd, 表示该节点是否为字符串的结尾。
    // 注意字符串对应的是一串路径，而不是某个节点

    // 插入：
    // 子节点存在：沿着指针移动到子节点继续处理下一个字符即可，
    // 子节点不存在：创建新子节点，记录在children数组的对应位置上，然后沿指针移动，继续下一个字符。
    // 重复直到处理到字符串的最后一个字符即可

    // 查找
    // 子节点存在：沿着指针下移继续搜索即可
    // 子节点不存在：说明不包含此前缀，返回空指针。
    // 重复步骤，直到返回空指针或者到了前缀末尾，返回存在该前缀
    // 如果前缀末尾对应的节点isEnd为真，则存在该字符串。
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch: prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
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




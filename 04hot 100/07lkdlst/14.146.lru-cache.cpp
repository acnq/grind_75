/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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

struct DLinkedNode{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    // I. 哈希+双向链表
    // 双向链表按照使用的顺序存储键值对，头部是最近使用，尾部是最久使用
    // 哈希表通过缓存数据的键映射到双向链表中的位置
    // 首先要用哈希表定位，找出缓存项在双向链表中的位置，随后将其移动到头部
    // 这样get和put都仅需要O(1) [移动头部分为删除该节点和在头部添加两步，都是O(1)]
    // 注意要用伪头部和伪尾部来标记界限，
    // 
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // key 存在则要先定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // key不存在，则创建新节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加哈希表
            cache[key] = node;
            // 添加到头部
            addToHead(node);
            size++;
            if (size > capacity) {
                // 如果超出容量，删除尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中更对应的项
                cache.erase(removed->key);
                // 删除
                delete removed;
                size--;
            }
        } else {
            // key 存在，则哈希定位，再修改value, 再移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end




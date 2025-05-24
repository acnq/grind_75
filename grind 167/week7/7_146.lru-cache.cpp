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

struct DLinkedNode
{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    // I. 哈希表+双向链表
    // 双向链表使用顺序存储存储键值对，靠近头的最近使用，尾部最久未使用
    // 哈希表：缓存数据的键映射到其在双向链表的位置
    // get: key不存在，返回-1
    //      key存在，key对应的节点是最近被使用，通过哈希表定位到位置，并移动到头部，返回其值
    // put: key存在，与get类似，对应节点值更新为Value，并将该节点移动到头部
    //      key不存在，使用key-value创建一个新节点，头部添加该节点，并将key和该几点添加到哈希表中
    //                  还要判断是否超出容两，如果超出，则删除尾部节点，并删除哈希表中对应的项
public:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int _size;
    int _capacity;

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

    LRUCache(int capacity): _capacity(capacity), _size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key))
        {
            return -1;
        }
        // 如果key存在，先通过哈希表定位，再移动到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key))
        {
            // 若key不存在，创建新节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加到双向链表头部
            addToHead(node);
            _size++;
            if (_size > _capacity)
            {
                // 超出容两，删除双向链表尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                _size--;
            }
        } else {
            // 如果key存在，先通过哈希表定位，在修改Value, 最后移到头部
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




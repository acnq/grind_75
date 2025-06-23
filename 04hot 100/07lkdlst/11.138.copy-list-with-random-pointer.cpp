/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30204
 *
 * [138] 随机链表的复制
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    // I. 回溯 + 哈希
    // 普通链表可以顺序复制，但是因为这个链表里面有随机指针，
    // 所以当我们拷贝节点，“当前节点随机指针的所指”可能还没创建
    // 考虑回溯法，让每个拷贝操作互相独立，每个节点拷贝完成后，进行“后继结点
    // 和“随机指针的所指”的拷贝，然后将新创建的两个节点的指针返回，赋值给当前节点
    // 这样的问题在于随机指针所指向的节点可能重复，但我们不能重复创建
    // 为此，我们使用哈希表记录每个节点对应的新节点创建情况。
    // 如果发现已经拷贝过，直接从哈希表中取出拷贝的节点指针即可

    // II. 迭代 + 节点拆分
    // 一个省去哈希表的空间的技巧
    // 我们直接给原链表复制出一个拷贝节点：A->B->C => A->A'->B->B'->C->C'
    // 这样可以直接对每个拷贝节点S'找到随机指针应当指向的节点
    // 最后只需要将所有拷贝节点S'拆分下来即可。
public:
    // I.
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        // if (head == nullptr) {
        //     return nullptr;
        // }
        // if (!cachedNode.count(head)) {
        //     Node* headNew = new Node(head->val);
        //     cachedNode[head] = headNew;
        //     headNew->next = copyRandomList(head->next);
        //     headNew->random = copyRandomList(head->random);
        // }    
        // return cachedNode[head];

        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next ) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */


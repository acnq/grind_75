/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    // I. 模拟
    // 理论上不涉及复杂的算法，但是很容易写出过于冗长的代码
    // 首先把链表节点按照k个一组分组，这可以使用一个指针head依次指向每组的头结点
    // 只要这个指针每次向前移动k步，直至到达结尾，每个分组，首先判断长度是否>=k,
    // 是则翻转，否则不翻转。注意通常翻转链表不难，但对于子链表，除了翻转自身外，
    // 还需要将子链表的（新）头部与上一个子链表链接，再把（新）尾部与下一个子链表链接。
    // 为此，在反转链表的时候，不仅需要子链表的头结点head, 还需要head的上一个节点pre, 以便接回
    // 头链表加个dummyHead以免特判
    // pre还有另一个好处，就是前k个节点翻转之后，链表的头结点会变化，而如果分组节点数量少于k，又不会翻转
    // 所以用第k个结点返回并不可靠，但是pre的next一定是正确的头结点。
public:
    // I.
    // 翻转子链表，并且返回新的“头”和“尾”。
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;

        while (head) {
            ListNode* tail = pre;
            // 首先要查看剩余部分长度是否>=k
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummyHead->next; // 总长度都比k小
                }
            }
            ListNode* nxt = tail->next;
            tie(head, tail) = myReverse(head, tail);

            // 接回原链表
            pre->next = head;
            tail->next = nxt;
            pre = tail;
            head = tail->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */


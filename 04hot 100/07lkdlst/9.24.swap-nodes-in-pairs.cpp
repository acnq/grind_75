/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    // I. 递归
    // 看了眼提示做出来了，
    // sc/tc: O(n)

    // II. 迭代
    // 还是创建dummyHead, tmp表示当前到达的节点，初始是tmp=dummyHead
    // 每次交换tmp之后的两个节点，如果不到两个，则不再需要交换，直接返回
    // 否则，获取tmp后面的两个节点node1和node2
    // 具体操作如下：
    // tmp.next = node2, node1.next = node2.next, node2.next = node1

public:
    ListNode* swapPairs(ListNode* head) {
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }
        // ListNode* rest = swapPairs(head->next->next);
        // ListNode* p = head->next;
        // p->next = head;
        // head->next = rest;
        // return p;
        // 5min

        // II.
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* tmp = dummyHead;
        while (tmp->next != nullptr && tmp->next->next != nullptr)
        {
            ListNode* node1 = tmp->next;
            ListNode* node2 = tmp->next->next;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


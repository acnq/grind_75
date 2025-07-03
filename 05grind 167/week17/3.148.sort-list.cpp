/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30204
 *
 * [148] 排序链表
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
    // O(n log n)可以考虑归并排序，因为链表的归并比较容易实现
    // I. 自顶向下
    // 1. 找到中点，拆分为两个子链表，
    // 2. 对两个子链表分别排序
    // 3. 合并两个有序链表
    // 此处我们首先通过递归实现。
    // tc: O(n logn), sc: O(log n)

    // II. 自底向上
    // 首先求得链表长度len, 然后拆分成子链表合并
    // 1. sublen:=每次需要排序的子链表的长度，初始为1
    // 2. 每次将链表拆分成若干个长度为sublen的子链表，每两个一组合并
    //    合并后得到若干长度为sublen * 2的有序子链表，
    // 3. sublen 加倍，重复第二步，直到有序子链表长度>=len, 排序完毕


public:
    // I. && II.
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tmp = dummyHead, *tmp1 = head1, *tmp2 = head2;
        while (tmp1 != nullptr && tmp2 != nullptr) {
            if (tmp1->val <= tmp2->val) {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1 != nullptr) {
            tmp->next = tmp1;
        } else if (tmp2 != nullptr) {
            tmp->next = tmp2;
        }
        return dummyHead->next;
    }

    // I.
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* sortList(ListNode* head) {
        // I.
        // return sortList(head, nullptr);

        // II.
        if (head == nullptr) {
            return head;
        }
        int len = 0;
        ListNode* node = head;
        while (node != nullptr) {
            len++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLen = 1; subLen < len; subLen <<= 1) {
            ListNode* prev = dummyHead, *cur = dummyHead->next;
            while (cur != nullptr) {
                ListNode* head1 = cur;
                for (int i = 1; i < subLen && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < subLen && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* next = nullptr;
                if (cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1, head2); 
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                cur = next;
            } 
        }
        return dummyHead->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


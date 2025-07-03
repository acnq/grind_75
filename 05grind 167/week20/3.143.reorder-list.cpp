/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30204
 *
 * [143] 重排链表
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
    int val; ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // I. 线性表
    // 直接用支持随机访问的数组存储这个链表来做
    // sc/tc: O(n)

    // II. 寻找链表中点+链表逆序+合并链表
    // 原链表的右半段反转和左半段交错合并即得到答案，
    // 3步：1.找到原链表中点；2.右半链表翻转；3. 两链表合并
    // （注意两链表长度差不过1，可以直接合并）
    // tc: O(n); sc: O(1)
public:
    // II.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            ListNode* nextTemp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextTemp;
        }
        return pre;
    }
    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }

    void reorderList(ListNode* head) {
        // I.
        // if (head == nullptr)
        // {
        //     return;
        // }
        // vector<ListNode*> vec;
        // ListNode* node = head;

        // while (node != nullptr)
        // {
        //     vec.emplace_back(node);
        //     node = node->next;
        // }
        // int i = 0, j = vec.size() - 1;
        // while (i < j)
        // {
        //     vec[i]->next = vec[j];
        //     i++;
        //     if (i == j)
        //     {
        //         break;
        //     }
        //     vec[j]->next = vec[i];
        //     j--;
        // }
        // vec[i]->next = nullptr;

        // II.
        if (head == nullptr)
        {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */


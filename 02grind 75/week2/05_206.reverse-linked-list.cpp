// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30204
 *
 * [206] 反转链表
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
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 这种说法有错误
        // 因为q->next改变之后，p没法获得链表中下一个元素
        // 必须存储q->next
        // ListNode* p = head;
        // while (p != nullptr && p->next != nullptr)
        // {
        //     ListNode* q = p->next;
        //     q->next = p;
        //     p = q;
        // }
        // return p;
        // 需要至少两个在移动的指针
        // 快慢指针
        // ListNode* cur = head;
        // ListNode* prev = nullptr; 
        // while (cur != nullptr)
        // {
        //     ListNode* next = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = next;
        // }
        // return prev;
        // 递归版本
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        } else {
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


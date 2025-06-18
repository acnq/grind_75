// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* nxt): val(val), next(nxt) {}
};

class Solution {
    // 可以使用哑节点，这样就不用单独处理头结点了
    // I. 计算长度
    // 我的方法，但是加了哑结点
    // tc: O(L); sc: O(1)

    // II. 栈
    // 一次入栈，弹出的第n个节点就是需要删除的节点，
    // 下一个就是待删除节点的前驱结点
    // tc/sc: O(L)

    // III. 双指针
    // 设计两个指针，first永远比second超前n个节点
    // 那么first指向末尾，second就指向待删除节点
    // 同样适用dummyhead，让second指向待删除节点的前一个便于操作
     // tc: O(L); sc: O(1)
public:
    int getLen(ListNode* head) {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* cur = head;
        // int sz = 0;
        // while (cur != nullptr)
        // {
        //     cur = cur->next;
        //     sz++;
        // }
        
        // ListNode* prev = head;
        // cur = head;
        // for (int i = 0; i < sz - n - 1; i++)
        // {
        //     prev = prev->next;
        // }
        // if (prev != head && prev != nullptr)
        // {
        //     prev->next = prev->next->next;
        // } else if (prev == head)
        // {
        //     if(sz - n == 0) {
        //         head = head->next;
        //     } else {
        //         head->next = head->next->next;
        //     }
        // }
        // return head;
        // 12min

        // I.
        // ListNode* dummy = new ListNode(0, head);
        // int len = getLen(head);
        // ListNode* cur = dummy;
        // for (int i = 1; i < len - n + 1; i++)
        // {
        //     cur = cur->next;
        // }
        // cur->next = cur->next->next;
        // ListNode* ans = dummy->next;
        // delete dummy;
        // return ans;

        // II.
        // ListNode* dummy = new ListNode(0, head);
        // stack<ListNode*> stk;
        // ListNode* cur = dummy;
        // while (cur)
        // {
        //     stk.push(cur);
        //     cur = cur->next;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     stk.pop();
        // }
        // ListNode* prev = stk.top();
        // prev->next = prev->next->next;
        // ListNode* ans = dummy->next;
        // delete dummy;
        // return ans;

        // III.
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; i++)
        {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */


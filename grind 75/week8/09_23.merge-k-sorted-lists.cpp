/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
    ListNode(int x, ListNode* next): val(x), next(next) {}
};


// 前置知识：
// 合并两个列表，可以在O(n) TC和O(1) SC的限制中完成合并
// algo:
//  1. head: 保存合并之后链表的头部，设置为虚拟头
//  2. tail: 记录下一个插入位置的前一个位置，aPtr, bPtr来记录a, b未合并的第一位
//  3. aPtr, bPtr不空，则取val较小的合并，如果aPtr为空，bPtr整个合并即可；bPtr为空同理
//  4. 调整tail->next, 在后移tail和(aPtr或者bPtr)

class Solution {
    // I, 顺序合并

    // II. 分治合并
    // k个列表配对并合并同一对中的链表
    // k->k/2->k/4->......
    // 重复过程直到完成

    // III. 优先队列
    // 维护每个链表没有被合并的元素的最前面一个
    // k个链表最多有k个满足这样条件的元素
    // 选择val最小的元素合并到答案
public:
    // I. / II.
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b))
        {
            return a ? a : b;
        }
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr: bPtr);
        return head.next;
    }

    // II.
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
        {
            return lists[l];
        }
        if (l > r)
        {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    // III.
    struct Status
    {
        int val;
        ListNode* ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        } // 重载<可以将下文的最大堆转化为最小堆
    };

    priority_queue<Status> q;
    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode* ans = nullptr;
        // for (size_t i = 0; i < lists.size(); i++)
        // {
        //     ans = mergeTwoLists(ans, lists[i]);
        // }
        // return ans;

        // II. 
        // return merge(lists, 0, lists.size() - 1);
        
        for(auto node: lists) {
            if (node)
            {
                q.push({node->val, node});
            }
        }
        ListNode head, *tail = &head;
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next)
            {
                q.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */


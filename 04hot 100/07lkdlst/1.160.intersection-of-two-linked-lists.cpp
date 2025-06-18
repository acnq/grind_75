/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    // I. 哈希
    // 遍历headA的时候把每个结点放到哈希表中，再遍历headB
    // 查看B链表中的节点是否在A中即可。
    // tc: O(m + n), sc: O(m)

    // II. 双指针
    // 首先判断二者是否为空，有一为空，则肯定不再会相交
    // 都为空，创建pA和pB, 
    // 1. pA不空，下移，pB不空，也下移
    // 2. pA空，移动到headB, pB空，移到headA
    // 3. pA和pB指向同一个节点的时候，返回此节点，如果都为空，则返回空节点
    // 必要性是显然的
    // tc: O(m + n) [不变]；sc: O(1) (大大下降)

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // ListNode* curA = headA, *curB = headB;
        // while (curA != nullptr)
        // {
        //     curB = headB;
        //     while (curB != nullptr)
        //     {
        //         if (curA == curB)
        //         {
        //             return curA;
        //         }
        //         curB = curB->next;
        //     }
        //     curA = curA->next;
        // }
        // return NULL;
        // 13'36", sc: O(mn)，有点暴力

        // I.
        // unordered_set<ListNode*> visited;
        // ListNode* tmp = headA;
        // while (tmp != nullptr)
        // {
        //     visited.insert(tmp);
        //     tmp = tmp->next;
        // }
        // tmp = headB;
        // while (tmp != nullptr)
        // {
        //     if (visited.count(tmp))
        //     {
        //         return tmp;
        //     }
        //     tmp = tmp->next;
        // }
        // return nullptr;
        
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode* pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */


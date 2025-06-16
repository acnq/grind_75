// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30204
 *
 * [21] 合并两个有序链表
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
    // I. 递归
    // list1[0] + merge(list1[1:], list2); list1[0] < list2[0]
    // list2[0] + merge(list1, list2[1:]); else

    // II. 迭代
    // 我的写法，但是官方写的比较简洁一点
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if (list1 == nullptr) {
        //     return list2;
        // } 
        // if (list2 == nullptr) {
        //     return list1;
        // }
        // ListNode* cur1 = list1, *cur2 = list2;
        // ListNode* ansHead = (ListNode*)malloc(sizeof(ListNode)), *ansCur = ansHead;
        // while(cur1 != nullptr && cur2 != nullptr) {
        //     if (cur1->val < cur2->val) {
        //         ansCur->next = cur1;
        //         ansCur = ansCur->next;
        //         cur1 = cur1->next;
        //     } else {
        //         ansCur->next = cur2;
        //         ansCur = ansCur->next;
        //         cur2 = cur2->next;
        //     }
        // }
        // if (cur1 != nullptr) {
        //     ansCur->next = cur1;
        // }
        // if (cur2 != nullptr) {
        //     ansCur->next = cur2;
        // }
        // return ansHead->next;

        // I.
        // if (list1 == nullptr) {
        //     return list2;
        // } else if (list2 == nullptr) {
        //     return list1;
        // } else if (list1->val < list2->val) {
        //     list1->next = mergeTwoLists(list1->next, list2);
        //     return list1;
        // } else {
        //     list2->next = mergeTwoLists(list1, list2->next);
        //     return list2;
        // }

        // II.
        ListNode* preHead = new ListNode(-1); // 善用new
        ListNode* prev = preHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next; // 不用另立cur, 本来list1的头就用不着
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next; // 这一步写在最后
        }
        // l1和l2最多只有一个还没被合并完，
        // 直接将链表末尾指向那个就可以了
        prev->next = list1 == nullptr ? list2 : list1;
        return preHead->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */


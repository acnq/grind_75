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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        } 
        if(list2 == nullptr) {
            return list1;
        }
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(-1);
        ListNode* res = head;

        while(cur1 != nullptr) {
            while(cur2 != nullptr) {
                if(cur1->val < cur2->val) {
                    ListNode* rescur = new ListNode(cur1->val);
                    res->next = rescur;
                    res = res->next;
                    cur1 = cur1->next;
                } else if(cur1->val > cur2->val) {
                    ListNode* rescur = new ListNode(cur2->val);
                    res->next = rescur;
                    res = res->next;
                    cur2 = cur2->next;
                } else { // cur1->val == cur2->val
                    ListNode* rescur1 = new ListNode(cur1->val);
                    ListNode* rescur2 = new ListNode(cur2->val);
                    res->next = rescur1;
                    res = res->next;
                    res->next = rescur2;
                    res = res->next;
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
            }
            res->next = cur1;
            break;
        }

        return head->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */


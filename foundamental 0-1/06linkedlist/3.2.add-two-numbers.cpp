// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
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
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // I. 模拟
    // 算法几乎是一样的，但是写法上有改进
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* ansHead = new ListNode(0), *ansCur = ansHead;
        // int carry = 0;
        // while(l1 != nullptr && l2 != nullptr) {
        //     int sum = carry + l1->val + l2->val;
        //     int digits = sum % 10;
        //     carry = sum / 10;
        //     ListNode* cur = new ListNode(digits);
        //     ansCur->next = cur;
        //     ansCur = ansCur->next;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // while (l1 != nullptr) {
        //     int sum = carry + l1->val;
        //     int digits = sum % 10;
        //     carry = sum / 10;
        //     ListNode* cur = new ListNode(digits);
        //     ansCur->next = cur;
        //     ansCur = ansCur->next;
        //     l1 = l1->next;
        // }
        // while (l2 != nullptr) {
        //     int sum = carry + l2->val;
        //     int digits = sum % 10;
        //     carry = sum / 10;
        //     ListNode* cur = new ListNode(digits);
        //     ansCur->next = cur;
        //     ansCur = ansCur->next;
        //     l2 = l2->next;
        // }
        // if (carry) {
        //     ListNode* cur = new ListNode(carry);
        //     ansCur->next = cur;
        //     ansCur = ansCur->next;
        // }

        // return ansHead->next;
        // 第一道几乎秒杀的中等题，21min

        ListNode* head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10); // 相当于初始化
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */


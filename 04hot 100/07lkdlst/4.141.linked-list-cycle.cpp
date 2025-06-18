/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30204
 *
 * [141] 环形链表
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
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    // I. 哈希表
    // 我的方法
    // sc: O(N), tc: O(N)

    // II. 快慢指针
    // Floyd 龟兔赛跑法
    // 如果有环，那么快指针一定能和慢指针相遇，因为要套一圈
    // 如果没有，那么就不会了
public:
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> visited;
        // ListNode* cur = head;
        // while (cur != nullptr)
        // {
        //     if (visited.count(cur) == 0)
        //     {
        //         visited.insert(cur);
        //         cur = cur->next;
        //     } else
        //     {
        //         return true;
        //     }
        // }
        // return false;

        // II.
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */


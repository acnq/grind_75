/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] 环形链表 II
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
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    // I. 哈希表
    // 我的方法，过于显然，
    // tc: O(n); sc: O(n)

    // II. 快慢指针
    // 我们假设fast的指针一次后移两位，slow一位
    // 显然他们不一定相遇于环的第一个节点, 我们使用一些数学计算
    // 假设环外长a, slow进入环后，走过b和fast相遇，此时fast走完n圈, 环总长b + c
    // fast走过：a + n(b + c) + b = a + (n + 1)b + nc
    // 有方程：a + (n + 1)b + nc = 2(a + b)
    // i.e. a = c + (n - 1)(b + c)
    // 所以，slow和fast相遇之后，额外使用ptr指向头部，和slow相同速度移动
    // 最终他们会在入环点相遇
    // tc: O(2n) = O(n); sc: O(3) = O(1).
public:
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode*> visited;
        // ListNode* cur = head;
        // while (cur != nullptr)
        // {
        //     if (visited.count(cur) > 0)
        //     {
        //         return cur;
        //     } else
        //     {
        //         visited.insert(cur);
        //         cur = cur->next;
        //     }
        // }
        // return NULL;
        // 5min

        // II.
        ListNode* slow = head, *fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode* ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
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


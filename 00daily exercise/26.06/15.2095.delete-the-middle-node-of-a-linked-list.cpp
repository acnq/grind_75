/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 * @lcpr version=30204
 *
 * [2095] 删除链表的中间节点
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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // I. 快慢指针
    // 我们使用和上题类似的快慢指针思想，找到中间元素
    // 注意为了保持删除节点之后剩余结构的完整性，我们还需要
    // pre指向slow的前一个节点，通过它才能将slow删除
    // 注意到如果只有一个节点，那么pre将变成空指针，因为我们需要特判
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr; // 仅包含一个元素的链表
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast&& fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,7,1,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end

 */


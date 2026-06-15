/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 * @lcpr version=30204
 *
 * [2130] 链表最大孪生和
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
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // I. 快慢指针 + 反转链表
    // 我们先用快慢指针找到链表的中点
    // 然后将后半部分链表翻转
    // 之后我们计算i和i + n/2个节点的和即可
    // tc: O(n), sc: O(1)
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转
        ListNode* last = slow->next;
        while(last->next) {
            ListNode* cur = last->next;
            last->next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
        }
        int ans = 0;
        ListNode* x = head;
        ListNode* y = slow->next;
        while (y) {
            ans = max(ans, x->val + y->val);
            x = x->next;
            y = y->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */


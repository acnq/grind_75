/*
 * @lc app=leetcode.cn id=328 lang=cpp
 * @lcpr version=30204
 *
 * [328] 奇偶链表
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
    int val; ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // I. 分离合并
    // odd, even分别指向奇节点和偶节点，初始odd=head, even=evenHead=head.next
    // 更新奇节点，奇节点的后一节点指向偶节点的后一节点，odd.next = even.next, 
    // 然后odd = odd.next， odd变为even的后一节点
    // 偶节点同理，even.next = odd.next, even = even.next
    // even为空或者even.next为空时，odd指向最后一个奇节点，
    // 最后odd.next = evenHead，让偶链表接到奇链表之后，头结点依旧是head
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,5,6,4,7]\n
// @lcpr case=end

 */


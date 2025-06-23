// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // I. 顺序合并
    // ans维护合并的链表，第i次循环把第i个链表和ans合并
    // tc: O(k^2 n), sc: O(1)

    // II. 分治合并
    // k个链表配对并且将同一对的合并
    // tc: O(kn * logk), sc: O(log k)

    // III. 优先队列
    // 维护当前每个链表没有被合并的元素的最前面一个
    // 每次从这（最多）k个元素中选取val最小的元素合并到答案中
    // tc: O(kn * logk), sc: O(k)

public:
    // I & II.
    ListNode* merge2(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    // II.
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        return merge2(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    // III.
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // I. 
        // ListNode *ans = nullptr;
        // for (size_t i = 0; i < lists.size(); i++) {
        //     ans = merge2(ans, lists[i]);
        // }
        // return ans;

        // II.
        // return merge(lists, 0, lists.size() - 1);

        // III.
        for (auto node: lists) {
            if (node) {
                q.push({node->val, node});
            }
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) {
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


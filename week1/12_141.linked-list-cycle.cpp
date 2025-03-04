// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> mem;       
        // ListNode* p = head;

        // if (head == nullptr)
        // {
        //     return false;
        // }
        
        // while (p->next != nullptr)
        // {
        //     if (mem.count(p) != 0)
        //     {
        //         return true;
        //     }
        //     mem.insert(p);
        //     p = p->next;
        // }
        // return false;
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode* tutle = head;
        ListNode* rabbit = head->next;

        while (tutle != rabbit)
        {
            if (tutle->next != nullptr && rabbit->next != nullptr && rabbit->next->next == nullptr)
            {
                tutle = tutle->next;
                rabbit = rabbit->next->next;
            } else {
                return false;
            }
        }
        return true
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


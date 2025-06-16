/*
 * @lc app=leetcode.cn id=876 lang=cpp
 * @lcpr version=30204
 *
 * [876] 链表的中间结点
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
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public: 
    ListNode* middleNode(ListNode* head) {
        // 这个可以AC
        // ListNode* fast = head;
        // ListNode* slow = head;
        // while (fast->next != nullptr)
        // {
        //     if (fast->next != nullptr && fast->next->next == nullptr)
        //     {
        //         fast = fast->next;
        //         slow = slow->next;
        //     } else if (fast->next->next != nullptr)
        //     {
        //         fast = fast->next->next;
        //         slow = slow->next;
        //     }
        // }
        // return slow;
        // 数组：
        // vector<ListNode*> arr = {head};
        // while (arr.back() ->next != NULL)
        // {
        //     arr.push_back(arr.back() -> next);
        // }
        // return arr[arr.size() / 2];
        // 二次遍历
        ListNode* cur = head;
        int cnt = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            cnt++;
        }
        int k = 0;
        cur = head;
        while (k < cnt / 2)
        {
            k++;
            cur = cur->next;
        }
        return cur;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

 */


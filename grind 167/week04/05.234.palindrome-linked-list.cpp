// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30204
 *
 * [234] 回文链表
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

#include <cmath>
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    // 直觉上感觉可以转化成回文数来做, 因为listNode.val <= 9
    // 不行，哪怕unsigned long long都不够长
    // 干脆转化成双向链表算了，也是O(N) - 并不，加上的第二指针sc会有O(N)
    // 感觉这些同事限制sc和tc的题目都超难
    // 看了眼提示，好像可以有个非常平易的方法：翻转后半部分链表，然后比较
    // 其实思路和之前想到的双向链表差不多
    // 另外，再看一眼题目，发现sc/tc的限制是“进阶"其实根本不用一开始就想出来/笑

    // I. 复制到数组
    // 不管进阶，我们简单的用数组+双指针搞定
    // sc/tc: O(n)

    // II. 递归
    // 递归可以遍历节点，注意遍历的过程可以自动形成堆栈，
    // 函数栈最高点是链表的尾部
    // 于是我们可以用一个递归外的变量frontPtr指向链表头部
    // 于是就可以比较，sc/tc: O(n), 因为递归形成了堆栈帧

    // III. 后半部分反转链表
    // 记得最后要恢复链表
public:
    // II.
    ListNode* frontPointer;
    bool recursiveCheck(ListNode* curr) {
        if(curr != nullptr) {
            if(!recursiveCheck(curr->next)) {
                return false;
            }
            if (curr->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    // III.
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // unsigned long long num = 0;
        // if(head == nullptr || head ->next == nullptr) {
        //     return true;
        // }
        
        // while(head -> next) {
        //     num += head->val;
        //     head = head->next;
        //     num *= 10;
        // }
        // num += head->val;

        // int len = 0;
        // int numcpy = num;
        // while(numcpy) {
        //     len++;
        //     numcpy /= 10;
        // }

        // while(num > 0) {
        //     int init = num / ((int) pow(10, len - 1));
        //     int termi = num % 10;
        //     if(init != termi) {
        //         return false;
        //     }
        //     num -= init * (int) (pow(10, len - 1));
        //     num = num / 10;
        //     len -= 2;
        // }
        // return true;
        // 不行，哪怕unsigned long long 都不够长

        // 快慢指针取中点
        // ListNode* cur = head;
        // ListNode* fast = cur, *slow = cur;
        // while(fast) {
        //     if(fast ->next && fast->next->next) {
        //         fast = fast->next->next;
        //         slow = slow->next;
        //     } else  {
        //         fast = fast->next; // 都直接接地即可，下一轮直接跳出循环
        //     }
        // }
        // // 后半段翻转
        // ListNode* latter = slow->next;
        // ListNode* latter_cur = latter, *latter_prev = slow;
        // latter_prev->next = nullptr;
        // while(latter_cur) { // 最后一步正是需要latter_next指向null来翻转尾
        //     ListNode* latter_next = latter_cur->next;
        //     latter_cur->next = latter_prev;
        //     latter_prev = latter_cur;
        //     latter_cur = latter_next;
        // }
        // // 此时pre指向新头（旧的尾部），并且新尾和前半段的尾是连在一起的
        // while(cur && latter_prev && cur != latter_prev) {
        //     if(cur->val == latter_prev->val) {
        //         cur = cur->next;
        //         latter_prev = latter_prev->next;
        //     } else {
        //         return false;
        //     }
        // }
        // return true;
        // 共计40-50分钟，

        // I.
        // vector<int> vals;
        // while(head != nullptr) {
        //     vals.emplace_back(head->val);
        //     head = head->next;
        // }
        // for(int i = 0, j = (int)vals.size() - 1; i < j; i++, j--) {
        //     if(vals[i] != vals[j]) {
        //         return false;
        //     }
        // }
        // return true;

        // II.
        // frontPointer = head;
        // return recursiveCheck(head);

        // III.
        if(head == nullptr && head->next == nullptr) {
            return true;
        }
        // 找到前半部分链表的尾结点并反转后半部分
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd);

        // 判断回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while(result && p2 != nullptr) {
            if(p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [8,0,7,1,7,7,9,7,5,2,9,1,7,3,7,0,6,5,1,7,7,9,3,8,1,5,7,7,8,4,0,9,3,7,3,4,5,7,4,8,8,5,8,9,8,5,8,8,4,7,5,4,3,7,3,9,0,4,8,7,7,5,1,8,3,9,7,7,1,5,6,0,7,3,7,1,9,2,5,7,9,7,7,1,7,0,8]\n
// @lcpr case=end

 */


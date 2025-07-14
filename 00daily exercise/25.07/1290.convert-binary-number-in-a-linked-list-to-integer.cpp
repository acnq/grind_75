// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 * @lcpr version=30204
 *
 * [1290] 二进制链表转整数
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

#include <cmath> // pow
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
    int val; ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        //I.
        // int res = 0;
        // vector<int> digits;
        // ListNode* cur = head;
        // while(cur != nullptr) {
        //     cout << cur->val << "\t";
        //     digits.push_back(cur->val);
        //     cur = cur->next;
            
        // }
        // cout << endl;
        // int n = digits.size();
        // for (int i = 0; i < n; i++) {
        //     if(digits[i] == 1) {
        //         res += (int)pow(2, n - i - 1);
        //     }
        // }
        // return res;

        // II.
        // 我们没必要知道总长度n, 只要保持原则：
        // 每读到一个节点，都把已读到的节点*2
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getDecimalValue
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30204
 *
 * [100] 相同的树
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    // I. DFS
    // 如我所想，递归法，本质上是深搜。
    
    // II. BFS.
    // 需要两个队列，初始根节点入对，每次各取出一个节点, 
    // 首先比较二者的值，若不相同则一定不同
    //  若相同，判断子节点是否为空，如果只有一个左/右节点为空，则二者也不同
    //  若子节点的置空情况相同，将非空子节点分别加入队列，注意顺序，这里规定先左后右，
    // 搜索结束时看队列情况，只有一个为空，则结构也不同
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(p == nullptr || q == nullptr) {
        //     return (p == nullptr && q == nullptr) ? true : false;
        // }
        // if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val)) {
        //     return true;
        // } else {
        //     return false;
        // }
        // 递归秒杀，4min
        if(p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            auto node1 = q1.front();
            q1.pop();
            auto node2 = q2.front();
            q2.pop();
            if(node1->val != node2->val) {
                return false;
            }
            auto left1 = node1->left, right1 = node1->right;
            auto left2 = node2->left, right2 = node2->right;
            if((left1 == nullptr) ^ (left2 == nullptr)) {
                return false;
            }
            if((right1 == nullptr) ^ (right2 == nullptr)) {
                return false;
            }
            if(left1 != nullptr) q1.push(left1);
            if(right1 != nullptr) q1.push(right1);
            if(left2 != nullptr) q2.push(left2);
            if(right2 != nullptr) q2.push(right2);
        }
        return q1.empty() && q2.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */


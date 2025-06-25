// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    // I. 迭代
    // 直接冲比较难得迭代写法
    // 关键是cur重定向为栈顶的时机，这是在穷竭左节点之后
    // 保持指向栈顶，如果有右节点，则不是让他入栈，而是把cur指向他
    // 把他作为新的根节点，重复穷竭左节点的操作。

    // II. 递归
    // 比较简单。

    // III. Morris 遍历
    // 维持一个predecessor变量：左子树中序遍历到cur的最后一个节点，即cur在中序遍历的前驱
    // 这样sc可下降至O(1)，做法如下
    // cur无左子，
    //  cur入列，
    //  cur = cur->right;
    // cur有左子, 找到predc：
    //  predc 右子为空：右子指向cur, cur = cur->left;
    //  predc 右子不为空（已经遍历cur的左子树）：predc右子置空；cur入列；cur = cur->right;
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) { // 不要忘记此递归出口
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // 失败的写法
        // stack<TreeNode*> stk;
        // vector<int> res;
        // stk.push(root);
        // TreeNode* cur = stk.top();
        // while(!stk.empty()) {
        //     cur = stk.top();
        //     while (cur != nullptr && cur->left != nullptr) {
        //         cur = cur->left;
        //         stk.push(cur);
        //     }
            
        //     res.push_back(cur->val);
        //     stk.pop();
        //     // if (cur->right != nullptr) {
        //     //     stk.push(cur->right);
        //     // }
        //     cur = cur->right;
        // }
        // return res;

        // I.
        // 看了答案之后试图写对
        // stack<TreeNode*> stk;
        // vector<int> res;
        // TreeNode* cur = root;
        // while(cur != nullptr || (!stk.empty())) {
        //     while (cur != nullptr) {
        //         stk.push(cur);
        //         cur = cur->left;
        //     }
            
        //     cur = stk.top();
        //     res.push_back(cur->val);
        //     stk.pop();
        //     // if (cur->right != nullptr) {
        //     //     stk.push(cur->right);
        //     // }
        //     cur = cur->right;
        // }
        // return res;

        // II.
        // vector<int> res;
        // inorder(root, res);
        // return res;

        // III.
        vector<int> res;
        TreeNode* pre = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // pre就是当前root左走一步，然后一直右走直到遇到空针为止
                pre = root->left;
                while (pre->right != nullptr && pre->right != root) {
                    pre = pre->right;
                }
                // pre 右指针指向root, 继续遍历左子树
                if (pre->right == nullptr) {
                    pre->right = root;
                    root = root->left;
                } else {
                    // 否则左子树访问完，断开连接
                    res.push_back(root->val);
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                // 无左子，直接访问右子
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


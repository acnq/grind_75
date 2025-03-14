/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
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


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // bool isBST(TreeNode* root, long long lower, long long upper) {
    //     if (root == nullptr)
    //     {
    //         return true;
    //     }
    //     if (root->val <= lower || root->val >= upper)
    //     {
    //         return false;
    //     }
    //     return isBST(root->left, lower, root->val) && isBST(root->right, root->val, upper);
        
    // }

    bool isValidBST(TreeNode* root) {
        // I. 递归
        // return isBST(root, LONG_MIN, LONG_MAX);

        // II. 中序遍历
        // 注意不需要遍历完成再比较大小，遍历的过程中
        // 检查当前节点的值是否大于前一个中序遍历节点即可
        stack<TreeNode*> stack; // 中序遍历辅助栈
        long long inorder = (long long) INT_MIN - 1;

        while (!stack.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 中序遍历得到的节点值小于等于前一个inorder
            // 则不是BST
            if (root->val <= inorder)
            {
                return false;
            }
            inorder = root->val;
            root = root->right;    
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */


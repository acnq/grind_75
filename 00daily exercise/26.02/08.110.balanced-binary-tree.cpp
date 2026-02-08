/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
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
    // I. 自顶向下递归
    // height(p): 二叉树任意结点的高度
    // height(p) = { 0                      p 空
    //             { max(height(p.left), height(p.right)) + 1 P非空
    // 当前节点首先计算左右子树节点的高度，如果高度差不超过1，
    // 再分别递归遍历左右子节点，判断左子树和右子树是否平衡
    // tc: O(n^2), sc: O(n)

    // II 自底向上递归：
    // 先递归判断左右子树是否平衡，再判断当前节点为根的子树是否平衡
    // 如果平衡，则返回高度，否则返回-1，一旦一棵子树不平衡，整个二叉树必然不平衡
    // tc: O(n), sc: O(n)
public:
    // I.
    // int height(TreeNode* root) {
    //     if (root == NULL) {
    //         return 0;
    //     } else {
    //         return max(height(root->left), height(root->right)) + 1;
    //     }
    // }

    // II.
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        // I.
        // if (root == NULL) {
        //     return true;
        // } else {
        //     return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        // }
        return height(root) >= 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


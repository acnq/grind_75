/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution {
    // I. 递归
    // 关键是递归的判断条件

    // II. 迭代
    // 每次只需要把两个结点的左右子节点按照相反的顺序入队即可。

public:
    // I.
    bool Symmetric2Tree(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr || tree2 == nullptr) {
            return tree1 == nullptr && tree2 == nullptr;
        }
        if (tree1->val == tree2->val) { 
            if (Symmetric2Tree(tree1->left, tree2->right) && Symmetric2Tree(tree1->right, tree2->left)) {
                // 难的是上面一步判断条件
                return true;
            }
        }
        return false;
    }

    // II.
    bool check(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) {
                return false;
            }
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->right);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        // if (root == nullptr) {
        //     return true;
        // } else {
        //     return Symmetric2Tree(root->left, root->right);
        // }
        // 看提示写出来了递归

        // II.
        return check(root, root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */


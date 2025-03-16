/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // I. 递归
    // f_x: x节点的子树是否包含p,q, f_{叶}=false
    // (f_lson && f_rson) || ((x = p || x = q) && (f_lson || f_rson))
    // lson, rson 为x的左子树和右子树
    // II. 存储父节点
    //  用哈希表存储所有节点的父节点
    // 1. 根节点开始遍历，哈希表记录父节点指针
    // 2. 从p节点不断往它祖先移动，记录已经访问国的祖先节点
    // 3. 从q节点不断往它祖先移动，如果有祖先已经被访问过，这就是LCA节点
public:
    // TreeNode* ans;
    // bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == nullptr)
    //     {
    //         return false;
    //     }
    //     bool lson = dfs(root->left, p, q);
    //     bool rson = dfs(root->right, p, q);
    //     if ((lson && rson) || (( root->val == p->val || root->val == q->val) && (lson || rson)))
    //     {
    //         ans = root;
    //     }
    //     return lson || rson || (root->val == p->val || root->val == q->val);
    // }
    unordered_map<int, TreeNode*> pa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left != nullptr)
        {
            pa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr)
        {
            pa[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs(root, p, q);
        // return ans;
        pa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr)
        {
            vis[p->val] = true;
            p = pa[p->val];
        }
        while (q != nullptr)
        {
            if (vis[q->val])
            {
                return q;
            }
            q = pa[q->val];
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */


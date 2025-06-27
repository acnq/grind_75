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

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    // 感觉树根本没有按照搜索树的规范排序。。。完全不知道咋搞
    // I. 递归
    // 必须遍历整个二叉树，f_x: x为根的子树是否包含p或者q
    // 最近公共祖先x* := (f_l && f_r) || ((x* = p || x* = q) && (f_l || f_r))
    // l, r: x*的左子和右子，只要自底向上从叶节点更新，那么最先找到的一定是深度最大的祖先
    // 即最近公共祖先

    // II. 哈希存储父节点
    // 1. 遍历整个二叉树，记录每个节点的父节点指针
    // 2. p开始向祖先移动，记录已经访问过的祖先节点
    // 3. q开始向祖先移动，遇到第一个已经访问过的祖先节点就是p,q的LCA
    // 第二个写法其实可以想到，可惜了。

public:

    // I.
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if ((l && r) || ((root->val == p->val || root->val == q->val) && (l || r))) {
            ans = root;
        }
        return l || r || (root->val == p->val || root->val == q->val); 
    }

    // II. 
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // I.
        // dfs(root, p, q);
        // return ans;

        // II.
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) {
                return q;
            }
            q = fa[q->val];
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


/*
 * @lc app=leetcode.cn id=863 lang=cpp
 * @lcpr version=30204
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
    // I. DFS + 哈希表
    // 最直接的想法不是分类讨论，而是直接把target当做根节点，然后深搜所有距离k的节点
    // 那么不是只能找到子节点了么？为此，我们可以直接先遍历一遍树，用哈希表记录每个节点的父节点
    // 这样深搜的时候加上父节点向上搜索的过程，就可以完成任务，
    // 有条件node.val所有值均不同，所以哈希表的键可以用结点值代替，
    // 此外，为避免DFS访问重复，递归时额外传入来源节点from, 比较目标和来源是否相同，不同才递归。
public:
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;

    void findParents(TreeNode* node) {
        if (node->left != nullptr)
        {
            parents[node->left->val] = node;
            findParents(node->left);
        }
        if (node->right != nullptr)
        {
            parents[node->right->val] = node;
            findParents(node->right);
        }
    }

    void findAns(TreeNode* node, TreeNode* from, int depth, int k) {
        if (node == nullptr)
        {
            return;
        }
        if (depth == k)
        {
            ans.push_back(node->val);
            return;
        }
        if (node->left != from)
        {
            findAns(node->left, node, depth + 1, k);
        }
        if (node->right != from)
        {
            findAns(node->right, node, depth + 1, k);
        }
        if (parents[node->val] != from)
        {
            findAns(parents[node->val], node, depth + 1, k);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root);
        findAns(target, nullptr, 0, k);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n3\n
// @lcpr case=end

 */


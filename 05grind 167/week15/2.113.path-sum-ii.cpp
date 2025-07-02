/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=30204
 *
 * [113] 路径总和 II
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

struct TreeNode
{
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // I. BFS
    // 遍历这棵树，到叶节点且此时路径和恰为目标和时，我们就找到一条满足条件的路径
    // 使用哈希表记录树中每个节点的父节点以节省空间。
    // tc: O(N^2); sc: O(N)

    // II. DFS
    // 枚举每条根节点到叶节点的路径即可
    // tc: O(N^2); sc: O(N)

public:
    // I.
    // vector<vector<int>> ret;
    // unordered_map<TreeNode*, TreeNode*> parent;

    // void getPath(TreeNode* node) {
    //     vector<int> tmp;
    //     while (node != nullptr)
    //     {
    //         tmp.emplace_back(node->val);
    //         node = parent[node];
    //     }
    //     reverse(tmp.begin(), tmp.end());
    //     ret.emplace_back(tmp);
    // }

    // II. 
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr)
        {
            return;
        }
        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            ret.emplace_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // I.
        // if (root == nullptr)
        // {
        //     return ret;
        // }
        // queue<TreeNode*> nodeq;
        // queue<int> sumq;
        // nodeq.emplace(root);
        // sumq.emplace(0);

        // while (!nodeq.empty())
        // {
        //     TreeNode* node = nodeq.front();
        //     nodeq.pop();
        //     int rec = sumq.front() + node->val;
        //     sumq.pop();

        //     if (node->left == nullptr && node->right == nullptr)
        //     {
        //         if (rec == targetSum)
        //         {
        //             getPath(node);
        //         }
        //     } else
        //     {
        //         if (node->left != nullptr)
        //         {
        //             parent[node->left] = node;
        //             nodeq.emplace(node->left);
        //             sumq.emplace(rec);
        //         }
        //         if (node->right != nullptr)
        //         {
        //             parent[node->right] = node;
        //             nodeq.emplace(node->right);
        //             sumq.emplace(rec);
        //         }
        //     }
        // }
        // return ret;

        // II.
        dfs(root, targetSum);
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */


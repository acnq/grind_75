/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30204
 *
 * [95] 不同的二叉搜索树 II
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
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
    // I. 回溯
    // def generateTrees(start, end), 返回序列[start, end]能生成的所有可行BST
    // 枚举i \in [start, end]; 递归调用 generateTrees(start, i - 1); generateTrees(i + 1, end)
    // start > end; 返回空节点
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end)
        {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        // 枚举可行节点
        for (int i = start; i <= end; i++)
        {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            // 获得所有可行的右子树
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left: leftTrees) {
                for (auto& right: rightTrees) {
                    TreeNode* curTree = new TreeNode(i);
                    curTree->left = left;
                    curTree->right = right;
                    allTrees.emplace_back(curTree);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n)
        {
            return {};
        }
        return generateTrees(1, n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


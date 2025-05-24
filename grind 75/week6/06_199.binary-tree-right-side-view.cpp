/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30204
 *
 * [199] 二叉树的右视图
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
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // DFS:
    // 总是先访问右子树，这样每一层见到的第一个节点一定是最右边的
    // 用一个容器存储每个深度访问的第一结点，就能得到最终结果

    // BFS:
    // 层级遍历，最右边的结点一定是最后被遍历到的
    // 只保留每个深度最后访问的节点，
    // 和上文相比，除了将栈改成队列，除去rightmost_value_depth检查外
    // 并无改动
public:
    vector<int> rightSideView(TreeNode* root) {
        // unordered_map<int, int> rightmost_value_depth;
        // int max_depth = -1;

        // stack<TreeNode*> nodeStack;
        // stack<int> depthStack;
        // nodeStack.push(root);
        // depthStack.push(0);

        // while (!nodeStack.empty())
        // {
        //     TreeNode* node = nodeStack.top();
        //     nodeStack.pop();
        //     int depth = depthStack.top();
        //     depthStack.pop();

        //     if (node != NULL)
        //     {
        //         // 维护二叉树的最大深度
        //         max_depth = max(max_depth, depth);

        //         // 不存在对应深度的结点则插入
        //         if (rightmost_value_depth.find(depth) == rightmost_value_depth.end())
        //         {
        //             rightmost_value_depth[depth] = node->val;
        //         }
                
        //         nodeStack.push(node->left);
        //         nodeStack.push(node->right);
        //         depthStack.push(depth + 1);
        //         depthStack.push(depth + 1);
        //     }
        // }
        
        // vector<int> right_view;
        // for (int depth = 0; depth <= max_depth; depth++)
        // {
        //     right_view.push_back(rightmost_value_depth[depth]);
        // }
        
        // return right_view;

        unordered_map<int, int> rightmost_value_depth;
        int max_depth = -1;

        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();

            if (node != nullptr)
            {
                // 维护二叉树最大深度
                max_depth = max(max_depth, depth);

                // 每一层最后一个访问到的结点才是我们的答案
                // 只需要更新深度即可
                rightmost_value_depth[depth] = node->val;

                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }
        
        vector<int> rightview;
        for (int depth = 0; depth <= max_depth; depth++)
        {
            rightview.push_back(rightmost_value_depth[depth]);
        }
        
        return rightview;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


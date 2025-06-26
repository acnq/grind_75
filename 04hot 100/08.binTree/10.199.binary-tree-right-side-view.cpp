// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    // I. DFS
    // 总是先访问右子树，那么对于每层而言，第一个见到的节点一定是最右边的节点
    // 这需要我们额外记录节点所在的层
    // II. BFS
    // 每层保留最后遇到的节点

    // 官方题解写的很冗杂，感觉还是我自己写的代码简明一点
    // 而且复杂度都是一样的
public:
    vector<int> rightSideView(TreeNode* root) {
        // 感觉可以用层序遍历来解决
        // 抽取每层最后一个感觉就可以
        // if (root == nullptr) {
        //     return {};
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // vector<int> ans;
        // while (!q.empty()) {
        //     int sz = q.size();
        //     while (sz > 0) {
        //         TreeNode* cur = q.front();
        //         q.pop();
        //         if (sz == 1) {
        //             ans.push_back(cur->val);
        //         }
        //         sz--;
        //         if (cur->left != nullptr) {
        //             q.push(cur->left);
        //         }
        //         if (cur->right != nullptr) {
        //             q.push(cur->right);
        //         }
        //     }
        // }
        // return ans;
        // 改自己之前写的代码，18min
        // 还是要背一下层序遍历和中序遍历的定式，主要感觉也不复杂，就细节太多

        // I.
        // unordered_map<int, int> rightmostValueAtDepth;
        // int max_depth = -1;

        // stack<TreeNode*> nodeStack;
        // stack<int> depthStack;
        // nodeStack.push(root);
        // depthStack.push(0);

        // while (!nodeStack.empty()) {
        //     TreeNode* node = nodeStack.top();
        //     nodeStack.pop();
        //     int depth = depthStack.top();
        //     depthStack.pop();

        //     if (node != NULL) {
        //         // 维护二叉树的最大深度
        //         max_depth = max(max_depth, depth);

        //         // 如果不存在对应深度的节点我们才记录
        //         if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()) {
        //             rightmostValueAtDepth[depth] = node->val;
        //         }

        //         nodeStack.push(node->left);
        //         nodeStack.push(node->right);
        //         depthStack.push(depth + 1);
        //         depthStack.push(depth + 1);
        //     }        
        // }

        // vector<int> rightView;
        // for (int depth = 0; depth <= max_depth; depth++) {
        //     rightView.push_back(rightmostValueAtDepth[depth]);
        // }
        // return rightView;

        // II.
        unordered_map<int, int> rightmostValueAtDepth;
        int max_depth = -1;

        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();

            if (node != NULL) {
                max_depth = max(max_depth, depth);

                //  由于每一层最后一个访问到的节点才是我们要的答案，
                // 因此不断更新对应深度的信息即可
                rightmostValueAtDepth[depth] = node->val;

                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }

        vector<int> rightView;
        for (int depth = 0; depth <= max_depth; depth++) {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }
        return rightView;
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


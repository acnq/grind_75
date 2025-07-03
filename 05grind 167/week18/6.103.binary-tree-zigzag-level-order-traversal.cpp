/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=30204
 *
 * [103] 二叉树的锯齿形层序遍历
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
    // T102题层序遍历的变种，规定根节点为0层，如果当前层数是偶数，
    // 从左至右输出当前层的结点值，否则，从右至左输出当前层的结点值
    // 对树进行层序遍历时，用队列维护当前层的所有元素，队列不为空时
    // 求得当前队列的长度size, 每次从队列中取出size个元素拓展，然后进行下一次迭代
    // 锯齿形可以利用双端队列的数据结构来维护顺序
    // 对当前层节点维护变量isOrderLeft记录是从左至右还是从右至左的
    //      1. 如果从左至右，每次将被遍历的元素插入至双端队列的末尾
    //      2. 如果从右至左，每次将被遍历的元素插入至双端队列的头部
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        
        queue<TreeNode*> nodeq;
        nodeq.push(root);
        bool isOrderLeft = true;

        while (!nodeq.empty())
        {
            deque<int> levelList;
            int size = nodeq.size();
            for (int i = 0; i < size; i++)
            {
                auto node = nodeq.front();
                nodeq.pop();
                if (isOrderLeft)
                {
                    levelList.push_back(node->val);
                } else
                {
                    levelList.push_front(node->val);
                }
                if (node->left)
                {
                    nodeq.push(node->left);
                }
                if (node->right)
                {
                    nodeq.push(node->right);
                }
            }
            ans.push_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


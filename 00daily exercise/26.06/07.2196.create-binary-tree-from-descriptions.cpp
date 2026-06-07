/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 * @lcpr version=30204
 *
 * [2196] 根据描述创建二叉树
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
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // I. 哈希
    // 用哈希nodes维持数值到对应节点的映射
    // 遍历数组创建二叉树，遍历到[p, c, left], 判断nodes是否存在
    // p 与 c对应的树节点，没有则新建一个数值为对应值的节点
    // 随后，根据left的真假将p对应的节点的左/右子节点设为c对应的节点
    // 之后我们就重建了目标二叉树
    // 那么怎么获取根呢？
    // 用哈希表isRoot维护数值与是否为根节点的映射
    // 遍历时isRoot[c]设为false, p在isRoot中不存在，则说明p暂无父节点
    // 暂时将isRoot[p]设为true, 因为树的结构是从输入确保的
    // 所以最终遍历完成，有且仅有一个在isRoot中的数值为true,
    // tc = sc =  O(n)
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> isRoot;        // 数值对应的节点是否为根节点的哈希表
        unordered_map<int, TreeNode*> nodes;    // 数值与对应节点的哈希表
        for (const auto& d: descriptions) {
            int p = d[0]; // parent
            int c = d[1]; // child
            bool left = d[2]; // isLeft
            if (!isRoot.count(p)) {
                isRoot[p] = true;
            }
            isRoot[c] = false;
            // 创建或更新的节点
            if (!nodes.count(p)) {
                nodes[p] = new TreeNode(p);
            }
            if (!nodes.count(c)) {
                nodes[c] = new TreeNode(c);
            }
            if (left) {
                nodes[p]->left = nodes[c];
            } else {
                nodes[p]->right = nodes[c];
            }
        }

        // 寻找根节点
        int root = -1;
        for (const auto& [val, r]: isRoot) {
            if (r) {
                root = val;
                break;
            }
        }
        return nodes[root];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[2,3,0],[3,4,1]]\n
// @lcpr case=end

 */


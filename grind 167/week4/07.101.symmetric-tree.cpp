// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    // 感觉最直接的想法是中序遍历看看能不能回文
    // 递归不好想，因为首先对称树的左右子树不一定是对称的（例1）
    // 其次即便左右子树相等，母树也不一定是对称的(例2)
    // 这个也不对，[2,2,1,2,2], 左右可以排列成不对称的
    // tat, 不会了
    // 瞄了眼提示: 思考一下，两棵树对称等价于什么：
    // 左子树和右子树对称且右子树和左子树对称才可以
    // 感觉关键是把问题转化为两棵树的比较

    // I. 指针递归
    // 左子树与右子树对称我们用指针来搞定, 和我的思路一样

    // II. 迭代：
    // 递归的迭代化可以用队列实现，每次提取两个节点并比较，
    // 然后将左右子节点按相反的顺序插入队列
public:
    bool isSymmetric2Tr(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr) {
            return (root1 == nullptr) && (root2 == nullptr) ? true : false;
        }
        if(root1->val != root2->val) {
            return false;
        } else {
            return isSymmetric2Tr(root1->left, root2->right) && isSymmetric2Tr(root1->right, root2->left);
        }
    }

    // II.
    bool check(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u); q.push(v);
        while(!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u -> val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left); // 注意这里入队的方式，比较上文的递归方案
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        // if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        //     return true;
        // } else {
        //     return isSymmetric2Tr(root->left, root->right);
        // }
        return check(root, root);
    }
    // 知道思路之后9min
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,2,null,2]\n
// @lcpr case=end

 */


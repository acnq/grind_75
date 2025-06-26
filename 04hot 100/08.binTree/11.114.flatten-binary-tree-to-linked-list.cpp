// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30204
 *
 * [114] 二叉树展开为链表
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
    // I. 前序遍历
    // 递归的写法和我的几乎一样，补充个迭代的写法叭

    // II. 同步遍历和展开
    // I.的方法需要两遍的原因在于对左子树遍历的时候，右子树的信息直接丢失了
    // 为此，我们对前序遍历的迭代方案稍作修改：我们在进入左子树之前，首先把左右子树的信息存入栈中
    // 每次出栈的当前节点先获得其子节点，如果不空，依次将右节点和左节点入栈（注意顺序）
    // 注意因为我们还是维护了一个栈，所以虽然是原地算法，但是sc依旧是O(n);

    // III. 寻找前驱结点
    // 先序遍历找到当前节点的后继很容易（cur->left), 问题是如何找到前驱，遍历完左子树之后该如何快速找到原节点的右子树根呢？
    // 显然有如下结论：
    // 某个节点的左子树中最后一个被访问的节点是此左子树中最右边的节点，也是该节点右子树的前驱结点
    // 设当前节点cur, 若其左子结点不为空，找到其左子树最右边的节点，作为前驱结点prev
    // prev->right = cur->right (直接把cur的右子树接到prev的右指针上)
    // cur->right = cur->left (子树移到右边, 因为显然左子树的根是先序遍历时cur的后继结点，接到next/right上即可)
    // cur->left = nullptr
    // cur = cur->right 
    // 可以结合动画来看，很直观，而且很精妙

public:
    void firstOrder(TreeNode* root, vector<int>& fOrderRes) {
        if (root == nullptr) {
            return;
        }
        fOrderRes.push_back(root->val);
        firstOrder(root->left, fOrderRes);
        firstOrder(root->right, fOrderRes);
    }
    void flatten(TreeNode* root) {
        // 我们先不管进阶要求，直接转化成vector在转成链表
        // vector<int> fOrder;
        // firstOrder(root, fOrder);
        // TreeNode* cur = root;
        // for(int i = 1; i < fOrder.size(); i++) {
        //     TreeNode* tmp = new TreeNode(fOrder[i]);
        //     cur->right = tmp;
        //     cur->left = nullptr;
        //     cur = cur->right;
        // }
        // return;
        // 10min, 准秒杀

        // I.
        // auto v = vector<TreeNode*>();
        // auto stk = stack<TreeNode*>();
        // TreeNode* node = root;
        // while (node != nullptr || !stk.empty()) {
        //     while (node != nullptr) {
        //         v.push_back(node);
        //         stk.push(node);
        //         node = node->left;
        //     }
        //     node = stk.top();
        //     stk.pop();
        //     node = node->right;
        // }
        // int sz = v.size();
        // for (int i = 1; i < sz; i++) {
        //     auto prev = v.at(i - 1), cur = v.at(i);
        //     prev->left = nullptr;
        //     prev->right = cur;
        // }

        // II.
        // if (root == nullptr) {
        //     return;
        // }
        // auto stk = stack<TreeNode*>();
        // stk.push(root);
        // TreeNode* prev = nullptr;
        // while (!stk.empty()) {
        //     TreeNode* cur = stk.top();
        //     stk.pop();
        //     if (prev != nullptr) {
        //         prev->left = nullptr;
        //         prev->right = cur;
        //     }
        //     TreeNode* left = cur->left, *right = cur->right;
        //     if (right != nullptr) {
        //         stk.push(right);
        //     }
        //     if (left != nullptr) {
        //         stk.push(left);
        //     }
        //     prev = cur;
        // }

        // III.
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                auto next = cur->left;
                auto predc = next;
                while (predc->right != nullptr) {
                    predc = predc->right;
                }
                // 这时predc已经是cur左子树的最右节点了
                predc->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


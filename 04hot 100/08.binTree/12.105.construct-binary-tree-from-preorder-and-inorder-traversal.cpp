/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    // I. 递归
    // 因为没有重复元素，所以关键是“定位根节点”
    // 扫描中序遍历的结果找到根节点是可行的，但是我们可以考虑使用哈希加速
    // 同样因为无重复元素，所以我们可以倒排文：键表示节点值，值表示中序遍历的位置
    // 这样我们就只需要在第一次的时候O(n)扫描，而构造的时候只需要O(1)查表即可。

    // II. 迭代
    // 考虑上一题，先序遍历的任意两个连续的节点u,v只有两种关系
    // v是u的左子
    // u无左子，那么v是u或者u的某个祖先的右子
    //         u无左子，那么下一个遍历的就是u的右子
    //          u无右子，我们会向上回溯，直到遇到第一个有右子，且u不在其右子树中的节点w, v一定是w的右子
    // 栈stack维护“当前节点cur所有还没有访问过右子的祖先节点”，栈顶作为当前节点
    // 指标idx指向中序遍历中的某个位置：对应cur不断左移能达到的最终节点，初始值为0
    // 先序的首个元素必然是根，入栈之后，0一定是它左子树最左的节点
    // 随后，我们访问先序遍历中的每个结点，以此判断他是栈顶节点的左子，还是栈中某个元素的右子
    // 怎么判断是不是左子呢？只要idx没有恰好指向栈顶，那就一定是左子，入栈
    //（显然，反证法, 如果某个元素时右子，那么说明当前元素idx无左子，idx应当恰好指向栈顶）
    // 下一个问题：如果遇到了idx指向栈顶，那么当前访问的先序元素是谁的右子该怎么确定呢？
    // 注意到，栈中的节点顺序（从底向上）一定和先序顺序一致，而一定和中序相反
    // (显然，先序的左子一定先于根, 而栈中元素是不断访问左子得到的序列)
    // 于是，我们不断右移idx并与栈顶比较，如果二者相等，idx++, 栈顶弹出
    // 直到弹出的最后一个节点p，就是当前先序遍历节点x的亲节点
    // （因为中序遍历时，x出现在了p和p在栈中的下一个节点的之间
    // (所以p一定是x所有还没有访问过右子的祖先节点中的第一个[栈的意义]，
    // 而x一定是某个元素的右子，那么x是只能是p的右子)
    // 至此我们完成了证明，可以参考官方的实例理解
    // 算法：
    // 声明栈stk和指标idx, stk.push(root), idx=0
    // 枚举前序遍历中从第二个开始的节点cur，
    //      如果idx恰好指向栈顶，不断弹出栈顶并同事右移idx
    //      cur设为最后弹出节点的右子，
    //      如果idx和栈顶不同，cur作为栈顶节点的左子
    // 最后无论如何，cur都需要入栈

    // 顺便，已知后序和中序也能类似的确定一棵树，但是已知后序和中序不行
public:

    // I.
    unordered_map<int, int> idx;

    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR) {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preRoot = preL;
        // 在中序遍历中定位根节点
        int inRoot = idx[preorder[preRoot]];

        // 建立根结点
        TreeNode* root = new TreeNode(preorder[preRoot]);
        // 左子树的节点数目
        int lTreeSize = inRoot - inL;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 lTreeSize」个元素
        // 就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = build(preorder, inorder, preL + 1, preL + lTreeSize, inL, inRoot - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素
        // 就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = build(preorder, inorder, preL + lTreeSize + 1, preR, inRoot + 1, inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // I.
        // int n = preorder.size();
        // // 构造哈希
        // for (int i = 0; i < n; i++) {
        //     idx[inorder[i]] = i;
        // }
        // return build(preorder, inorder, 0, n - 1, 0, n - 1);

        // II.
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int idx = 0;
        for (int i = 1; i < preorder.size(); i++) {
            int cur = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[idx]) {
                node->left = new TreeNode(cur);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[idx]) {
                    node = stk.top();
                    stk.pop();
                    idx++;
                }
                node->right = new TreeNode(cur);
                stk.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */


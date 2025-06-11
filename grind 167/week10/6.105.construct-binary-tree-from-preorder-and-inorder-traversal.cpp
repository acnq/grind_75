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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // I. 递归
    // 观察两种遍历的形式
    // [根，[左前序遍历结果]，[右前序遍历结果]]
    // [[左中序遍历结果]，根，[右中序遍历结果]]
    // 注意到因为preorder 和 inorder 均 无重复 元素
    // 所以可以快速的在中序遍历中找到根，进而确定左右中序遍历的结果，
    // 又因为两种遍历的结果长度总是相同的，于是前序遍历中的括号位置也可以确定
    // 这样我们又获得了左右子树两种遍历结果的序列，这就可以可以递归的构造出左右子树

    // 寻找根节点的时候可以用以下方法（哈希表）加速
    // 构造哈希表[结点值，中序遍历出现的位置]
    // 构造的时候一次扫描构造上述映射，这样就不用每次都扫描遍历了

    // II. 迭代
    // 前序遍历中，任意两个连续的节点u, v, 只有两种可能的关系
    // 1.v是u的左儿子；2.u无左子，那么v就是u的某个祖先(或者u本)的右子
    // 2cont'd: 如果u无左子，下一节点就是u的右子，若u无右子，向上回溯
    // 直到遇到第一个有右子的u_a, v是u_a的右子
    // 用stack维护[当前节点的所有还没有考虑过右子的祖先节点]，从preorder中构造
    // index: [当前节点不断左移（取左子树）达到的最终节点]， 从inorder中取值
    // 可能需要结合题解中的例子来理解
    // stack中每个节点的右子都没有被遍历过，那么他们的顺序一定和他们在中序遍历中的顺序相反
    // 发现index恰好指向栈顶元素(l)时，说明l已经没有左子了，故遍历preorder中遇到的元素r
    // 必须是栈中某个元素的右子，通过以下方法找到这个父节点：
    // index不断右移，和栈顶比较，若indx对应的元素恰好等于栈顶，则弹出元素
    // 最后弹出的元素x一定是r的亲节点，因为r出现在了x与x左子栈中下个节点的中序遍历之间
    // 这时r也要入栈

    
    // notes: 显然同理可得，已知后序遍历和中序遍历，也可以重构（唯一确定）一棵树
    // 但是仅仅已知后续和前序并不能，比如前序AB, 后序BA, 我们最多只能直到A是父节点，不知道B是左子还是右子 
public:
    unordered_map<int, int> index;

    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int> inorder, int p_left, int p_right, int i_left, int i_right) {
        // i_left: inorder_left, p_left: preorder_left;
        if (p_left > p_right)
        {
            return nullptr;
        }

        // 前序遍历第一个节点就是根结点
        int p_root = p_left;
        // 中序遍历中定位根结点
        int i_root = index[preorder[p_root]];

        // 建立根结点
        TreeNode* root = new TreeNode(preorder[p_root]);
        // 左子树的节点数目
        int size_l_subtr = i_root - i_left; // size_left_subtree
        // 递归构造左子树，连接点根
        // 先序中，[左边界+1： size_l_subtree]对应中序中[左边界：根位置-1]
        root->left = myBuildTree(preorder, inorder, p_left + 1, p_left + size_l_subtr, i_left, i_root - 1);
        // 右子树
        // 先序[左边界+1+左子树节点数目：右边界] <-> [根位置+1：右边界]
        root->right = myBuildTree(preorder, inorder, p_left + size_l_subtr + 1, p_right, i_root + 1, i_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // int n = preorder.size();
        // // 构造哈希
        // for (int i = 0; i < n; i++)
        // {
        //     index[inorder[i]] = i;
        // }
        // return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);

        if (!preorder.size())
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int Index = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int preoder_val = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[Index])
            {
                node->left = new TreeNode(preoder_val);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top() -> val == inorder[Index])
                {
                    node = stk.top();
                    stk.pop();
                    Index++;
                }
                node->right = new TreeNode(preoder_val);
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


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30204
 *
 * [230] 二叉搜索树中第 K 小的元素
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

#include <random> // random_device
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
// II
class MyBst {
private:
    TreeNode* root;
    unordered_map<TreeNode*, int> nodeNum;
    // 统计以node为根结点的子树的节点数
    int countNodeNum(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        nodeNum[node] = 1 + countNodeNum(node->left) + countNodeNum(node->right);
        return nodeNum[node];
    }
    // 获取node为根结点的子树节点数
    int getNodeNum(TreeNode* node) {
        if (node != nullptr && nodeNum.count(node)) {
            return nodeNum[node];
        } else {
            return 0;
        }
    }

public:
    MyBst(TreeNode* root) {
        this->root = root;
        countNodeNum(root);
    }

    // 返回bst第k小元素
    int kthSmallest(int k) {
        TreeNode* node = root;
        while (node != nullptr) {
            int left = getNodeNum(node->left);
            if (left < k - 1) {
                node = node->right;
                k -= left + 1;
            } else if (left == k - 1) {
                break;
            } else {
                node = node->left;
            }
        }
        return node->val;
    }
};

// III.
// AVL树节点
struct Node {
    int val;
    Node* parent;
    Node* left;
    Node* right;
    int size;
    int height;

    Node(int val) {
        this->val = val;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0; 
        // 结点高度：以node为根节点的子树的高度（高度定义：叶结点的高度是0）
        this->size = 1;
        // 结点元素数：以node为根节点的子树的节点总数
    }

    Node(int val, Node* parent) {
        this->val = val;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
        this->size = 1;
    }

    Node(int val, Node* parent, Node* left, Node* right) {
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->height = 0;
        this->size = 1;
    }
};

// AVL树：允许重复值
class AVL{
private:
    Node* root;

    // 获取以node为根结点的子树高度
    static int getHeight(Node* node) {
        return (node != nullptr) ? node->height : 0;
    }
    // 获取以node为根结点的子树节点数
    static int getSize(Node* node) {
        return node != nullptr ? node->size : 0;
    }

    // 返回以node为根结点的子树的第1个元素
    static Node* subtreeFirst(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    // 返回以node为根结点的子树的最后1个元素
    static Node* subtreeLast(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // 重新连接父结点和子结点（子结点允许为空）
    static void relink(Node* parent, Node* child, bool isLeft) {
        if (isLeft) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        if (child != nullptr) {
            child->parent = parent;
        }
    }

    // 获取node结点更高的子树
    Node* tallChild(Node* node) {
        if (getHeight(node->left) > getHeight(node->right)) {
            return node->left;
        } else {
            return node->right;
        }
    }
    
    // 获取node结点更高的子树中的更高的子树
    Node* tallGrandchild(Node* node) {
        Node* child = tallChild(node);
        return tallChild(child);
    }

    // 重新计算node结点的高度和元素数
    void recompute(Node* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }

    // 在以node为根结点的子树中搜索值为v的结点，
    // 如果没有值为v的结点，则返回值为v的结点应该在的位置的父结点
    Node* subtreeSearch(Node* node, int v) {
        if (node->val < v && node->right != nullptr) {
            return subtreeSearch(node->right, v);
        } else if (node->val > v && node->left != nullptr) {
            return subtreeSearch(node->left, v);
        } else {
            return node;
        }
    }

    // 判断node结点是否平衡
    bool isBalanced(Node* node) {
        return abs(getHeight(node->left) - getHeight(node->right)) <= 1;
    }


    // 旋转操作
    void rotate(Node* node) {
        Node* parent = node->parent;
        Node* grandparent = parent->parent;
        if (grandparent == nullptr) {
            root = node;
            node->parent = nullptr;
        } else {
            relink(grandparent, node, parent == grandparent->left);
        }
        if (node == parent->left) {
            relink(parent, node->right, true);
            relink(node, parent, false);
        } else {
            relink(parent, node->left, false);
            relink(node, parent, true);
        }
    }

    // trinode操作
    Node* restructure(Node* node) {
        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        if ((node == parent->right) == (parent == grandparent->right)) {
            // 处理需要一次旋转的情况
            rotate(parent);
            return parent;
        } else {
            // 处理需要两次旋转的情况：第1次旋转后即成为需要一次旋转的情况
            rotate(node);
            rotate(node);
            return node;
        }
    }

     // 从node结点开始（含node结点）逐个向上重新平衡二叉树，
     // 并更新结点高度和元素数
    void rebalance(Node* node) {
        while (node != nullptr) {
            int oldHeight = node->height, oldSize = node->size;
            if (!isBalanced(node)) {
                node = restructure(tallGrandchild(node));
                recompute(node->left);
                recompute(node->right);
            }
            recompute(node);
            if (node->height == oldHeight && node->size == oldSize) {
                // 如果结点高度和元素数都没有变化则不需要再继续向上调整
                node = nullptr;
            } else {
                node = node->parent;
            }
        }
    }

    // 删除结点p并用它的子结点代替它，结点p至多只能有1个子结点
    void Delete(Node* node) {
        if (node->left != nullptr && node->right != nullptr) {
            return;

        }
        Node* child = node->left != nullptr ? node->left : node->right;
        if (child != nullptr) {
            child->parent = node->parent;
        }
        if (node == root) {
            root = child;
        } else {
            Node* parent = node->parent;
            if (node == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        node->parent = node;
    }

public:
    // 根据vals[l:r]构造AVL搜索树->返回根节点
    Node* build(vector<int>& vals, int l, int r, Node* parent) {
        int m = (l + r) >> 1;
        Node* node = new Node(vals[m], parent);
        if (l <= m - 1) {
            node->left = build(vals, l, m - 1, node);
        }
        if (m + 1 <= r) {
            node->right = build(vals, m + 1, r, node);
        }
        recompute(node);
        return node;
    }

    AVL(vector<int>& vals) {
        if (!vals.empty()) {
            root = build(vals, 0, vals.size() - 1, nullptr);
        }
    }

    // 返回AVL BST第k小元素
    int kthSmallest(int k) {
        Node* node = root;
        while (node != nullptr) {
            int left = getSize(node->left);
            if (left < k - 1) {
                node = node->right;
                k -= left + 1;
            } else if (left == k - 1) {
                break;
            } else {
                node = node->left;
            }
        }
        return node->val;
    }

    void insert(int v) {
        if (root == nullptr) {
            root = new Node(v);
        } else {
            // 计算新节点的添加位置
            Node* node = subtreeSearch(root, v);
            bool isAddLeft = v <= node->val; // 是否将新结点添加到node的左子结点
            if (node->val == v) {
                // 如果值为v的结点已存在
                if (node->left != nullptr) {
                    // 值为v的结点存在左子结点，则添加到其左子树的最右侧
                    node = subtreeLast(node->left);
                    isAddLeft = false;
                } else {
                    // 值为v的结点不存在左子结点，则添加到其左子结点
                    isAddLeft = true;
                }
            }

            // 添加新节点
            Node* leaf = new Node(v, node);
            if (isAddLeft) {
                node->left = leaf;
            } else {
                node->right = leaf;
            }

            rebalance(leaf);
        }
    }

    // 删除值为v的结点 -> 返回是否成功删除结点
    bool Delete(int v) {
        if (root == nullptr) {
            return false;
        }

        Node* node = subtreeSearch(root, v);
        if (node->val != v) {
            // 没有找到需要删除的结点
            return false;
        }

        // 处理当前结点既有左子树也有右子树的情况
        // 若左子树比右子树高度低，则将当前结点替换为右子树最左侧的结点，并移除右子树最左侧的结点
        // 若右子树比左子树高度低，则将当前结点替换为左子树最右侧的结点，并移除左子树最右侧的结点
        if (node->left != nullptr && node->right != nullptr) {
            Node* replacement = nullptr;
            if (node->left->height <= node->right->height) {
                replacement = subtreeFirst(node->right);
            } else {
                replacement = subtreeLast(node->left);
            }
            node->val = replacement->val;
            node = replacement;
        }
        Node* parent = node->parent;
        Delete(node);
        rebalance(parent);
        return true;
    }
};

class Solution {
    // I. 中序遍历
    // 其实遍历的时候可以记录入栈的元素，直接取得第k小的元素
    // tc: O(H + k), H为树的高度，最小logN, 最大N; sc: O(H)

    // II. 记录子树的结点数。
    // 这是为了解决进阶问题：频繁查找而树又在变化的时候怎么办
    // 我们直接记录子树的节点数目
    // 1. node初始化为根结点开始搜索；
    // 2. 如下操作
    //      2.1 node左子树的节点数left < k - 1, 则目标在node的右子树中，
    //          node = node->right, k = k - left - 1, 继续搜索。
    //      2.2 node左子树的节点数left = k - 1, 则第k小的元素就是node, 返回其值
    //      2.3. node左子树的节点数left > k - 1, 目标在node左子树中，node = node->left, 继续
    // 参考答案直接自己设立了一个含有节点数的新数据结构。
    // sc/tc: O(N)

    // III. 平衡化
    // 直接把树修改为AVL树
private:
    // III.
    void inorder(TreeNode* node, vector<int>& inorderList) {
        if (node->left != nullptr) {
            inorder(node->left, inorderList);
        }
        inorderList.push_back(node->val);
        if (node->right != nullptr) {
            inorder(node->right, inorderList);
        }
    }
    void shuffle(vector<int>& arr) {
        std::random_device rd;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            int randIdx = rd() % length;
            swap(arr[i], arr[randIdx]);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // 感觉直觉上可以用中序遍历找第k个的方案
        // 先不管时间复杂度， 直接做
        // stack<TreeNode*> stk;
        // vector<int> inorder;
        // while (root != nullptr || (!stk.empty())) {
        //     while (root != nullptr) {
        //         stk.push(root);
        //         root = root->left;
        //     }
        //     root = stk.top();
        //     stk.pop();
        //     inorder.push_back(root->val);
        //     root = root->right;
        // }
        // int ans = inorder[k - 1];
        // return ans;
        // 准秒杀，10min a.c.

        // I. 
        // stack<TreeNode*> stk;
        // while (root != nullptr || stk.size() > 0) {
        //     while (root != nullptr) {
        //         stk.push(root);
        //         root = root->left;
        //     }
        //     root = stk.top();
        //     stk.pop();
        //     k--;
        //     if (k == 0) {
        //         break;
        //     }
        //     root = root->right;
        // }
        // return root->val;

        // II.
        // MyBst bst(root);
        // return bst.kthSmallest(k);

        // III.
        // 中序遍历生成数值列表
        vector<int> inorderList;
        inorder(root, inorderList);
        // 构造AVL树
        AVL avl(inorderList);

        // 模拟1000次插入删除
        vector<int> randomNums(1000);
        std::random_device rd;
        for (int i = 0; i < 1000; i++) {
            randomNums[i] = rd() % (10001);
            avl.insert(randomNums[i]);
        }
        shuffle(randomNums); // 列表乱序
        for (int i = 0; i < 1000; i++) {
            avl.Delete(randomNums[i]);
        }

        return avl.kthSmallest(k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */


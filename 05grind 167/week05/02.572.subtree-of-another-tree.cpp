// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=572 lang=cpp
 * @lcpr version=30204
 *
 * [572] 另一棵树的子树
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // 感觉递归检查相等与否就可以了？
    // I. DFS + 一一比对

    // II. DFS + 串匹配
    // 把s和t换成深度优先搜索序列（先序遍历），看t是否是s的子串
    // 问题在于，[1, 2]可以解为1为2的左子树或右子树，可能出现错误
    // 为此，需要用两个空值lNull, rNull分别表示左子和右子为空的情况
    // 子序列匹配用KMP算法
    // sc/tc: O(|s| + |t|)

    // III. 树哈希
    // s每个子树都映射为唯一的数值, t和这些数值比对即可
    // f_o = v_o + 31 * f_l * p(s_l) + 179 * f_r * p(s_r)
    // f_x: 节点x的哈希值，s_x：对应的子树大小, v_x: 对应节点值
    // p(n): 第n个质数， 这里的31和179只是为了区分左右子树，实际上可以任意选择
    // 这样冲突的可能性本题已经够用了，即使出现问题也可以双哈希解决
    // 计算第n个质数我们首先用埃拉托色尼筛选法获得arg \pi(max{|s|, |t|})个质数
    // \pi(x): x以内质数的个数，arg\pi为其反函数，最少多少以内包含x个质数
    // 对于x < 10^6, arg\pi(x) < 15x, 15x个自然数中大约能找到x个质数,故arg\pi略大于线性
    // sc/tc: O(arg\pi(max{|s|, |t|}) + |s| + |t|) = O(arg\pi(max{|s|, |t|}))
public:
    // I.
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr) {
            return (root1 == nullptr && root2 == nullptr);
        }
        return (root1->val == root2->val) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
    // II. 
    vector<int> sOrder, tOrder;
    int maxElem, lNull, rNull;
    void getMaxElem(TreeNode *o) {
        if(!o) {
            return;
        }
        maxElem = max(maxElem, o->val);
        getMaxElem(o->left);
        getMaxElem(o->right);
    }
    void getDFSOrder(TreeNode* o, vector<int>& tar) {
        if(!o) {
            return;
        }
        tar.push_back(o->val);
        if(o->left) {
            getDFSOrder(o->left, tar);
        } else {
            tar.push_back(lNull);
        }
        if(o->right) {
            getDFSOrder(o->right, tar);
        } else {
            tar.push_back(rNull);
        }
    }
    bool kmp() {
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector<int> fail(tOrder.size(), -1);
        for(int i = 1, j = -1; i < tLen; i++) {
            while(j != -1 && tOrder[i] != tOrder[j + 1]) {
                j = fail[j];
            }
            if (tOrder[i] == tOrder[j + 1]) {
                j++;
            }
            fail[i] = j;
        }
        for(int i = 0, j = -1; i < sLen; i++) {
            while(j != -1 && sOrder[i] != tOrder[j + 1]) {
                j = fail[j];
            }
            if(sOrder[i] == tOrder[j + 1]) {
                j++;
            }
            if(j == tLen - 1) {
                return true;
            }
        }
        return false;
    }

    // III.
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;
    
    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime() {
        vis[0] = vis[1] = 1;
        tot = 0;
        for(int i = 2; i < MAX_N; i++) {
            if(!vis[i]) {
                p[tot + 1] = i;
                tot++;
            }
            for(int j = 1; j <= tot && i * p[j] < MAX_N; j++) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) {
                    break;
                }
            }
        }
    }
    
    struct Status {
        int f, s; // f: 哈希值，s子树大小
        Status(int f_ = 0, int s_ = 0): f(f_), s(s_) {}
    };
    unordered_map<TreeNode*, Status> hS, hT;
    void dfs(TreeNode *o, unordered_map<TreeNode*, Status>& h) {
        h[o] = Status(o->val, 1);
        if(!o->left && !o->right) {
            return;
        }
        if(o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if(o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(subRoot == nullptr) return true;
        // if(root == nullptr) return false;
        // if(isSameTree(root, subRoot)) {
        //     return true;
        // }
        // return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        // // 9min 要做出来不难，

        // II. KMP + DFS
        // TreeNode* s = root, *t = subRoot;
        // maxElem = INT_MIN;
        // getMaxElem(s);
        // getMaxElem(t);
        // lNull = maxElem + 1;
        // rNull = maxElem + 2;

        // getDFSOrder(s, sOrder);
        // getDFSOrder(t, tOrder);
        // return kmp();

        TreeNode* s = root, *t = subRoot;
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for(const auto& [k, v]: hS) {
            if(v.f == tHash) {
                return true;
            }
        }
        return false;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n[4,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,2,null,null,null,null,0]\n[4,1,2]\n
// @lcpr case=end

 */


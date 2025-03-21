/*
 * @lc app=leetcode.cn id=297 lang=cpp
 * @lcpr version=30204
 *
 * [297] 二叉树的序列化与反序列化
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

#include <string>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // I. DFS
    // 选择先序遍历，注意需要None, 标记缺失的左右子节点
    // 如此可以通过先序遍历恢复
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr)
        {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }
    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None")
        {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    // II. 括号表示编码+递归下降解码
    // 空树表示为X
    // 不为空表示为 (<left_sub_tree>) cur_num (<right_sub_tree>）
    // i.e. T -> (T) num (T) | X
    // LL(1) 文法
    // 反序列化algo:
    //  递归函数传入两个参数，字符串和解析位置ptr, 
    //  当前位置为X则解析到了空树，直接返回
    //  否则一定是(, 对括号内部按照(T) num (T)解码即可
    inline int parseInt(const string& data, int& ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr]))
        {
            sgn = -1;
            ptr++;
        }
        while (isdigit(data[ptr]))
        {
            x = x * 10 + data[ptr] - '0';
            ptr++;
        }
        return x * sgn;
    }
    inline TreeNode* parseSubtree(const string& data, int& ptr) {
        ptr++; // 跳过左括号
        auto subtree = parse(data, ptr);
        ptr++; // 跳过右括号
        return subtree;
    }


    TreeNode* parse(const string& data, int& ptr) {
        if (data[ptr] == 'X')
        {
            ptr++;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }
    

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // string ret;
        // rserialize(root, ret);
        // return ret;

        if (!root)
        {
            return "X";
        }
        auto left = "(" + serialize(root->left) + ")";
        auto right = "(" + serialize(root->right) + ")";
        return left + to_string(root->val) + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // list<string> dataArray;
        // string str;
        // for(auto& ch: data) {
        //     if (ch == ',')
        //     {
        //         dataArray.push_back(str);
        //         str.clear();
        //     } else {
        //         str.push_back(ch);
        //     }
        // } 
        // if (!str.empty())
        // {
        //     dataArray.push_back(str);
        //     str.clear();
        // }
        // return rdeserialize(dataArray);
        int ptr = 0;
        return parse(data, ptr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */


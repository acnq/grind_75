/*
 * @lc app=leetcode.cn id=133 lang=cpp
 * @lcpr version=30204
 *
 * [133] 克隆图
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Node
{
private:
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    };
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        // DFS:
        // 使用哈希表存储已经被访问和克隆的节点
        // key: 原始节点，value: 克隆节点
        // 递归之前先创建并保存克隆节点到哈希表中
        // if (node == nullptr)
        // {
        //     return node;
        // }
        
        // // 若已经被访问过，则直接从哈希表取出对应的克隆节点返回
        // if (visited.find(node) != visited.end())
        // {
        //     return visited[node];
        // }

        // // 克隆节点，注意到深拷贝不会克隆邻居的列表
        // Node* cloneNode = new Node(node->val);
        // // 存储哈希表
        // visited[node] = cloneNode;

        // // 遍历该节点的邻居并更新克隆节点的邻居列表
        // for (auto& neighbor: node->neighbors)
        // {
        //     cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        // }
        // return cloneNode;
        
        // BFS:
        if (node == nullptr)
        {
            return node;
        }

        unordered_map<Node*, Node*> visited;

        // 添加到队列
        queue<Node*> q;
        q.push(node);
        // 克隆节点并存储到哈希表
        visited[node] = new Node(node->val);

        // bfs
        while (!q.empty())
        {
            // 取出队列头
            auto n = q.front();
            q.pop();
            // 遍历节点邻居
            for (auto& neighbor: n ->neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    // 如果没有被访问，就克隆并存储到哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    // 邻居节点加入到队列中
                    q.push(neighbor);
                }
                // 更新当前节点的邻居列表
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        
        return visited[node];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4],[1,3],[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


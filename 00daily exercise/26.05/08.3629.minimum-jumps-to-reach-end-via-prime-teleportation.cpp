/*
 * @lc app=leetcode.cn id=3629 lang=cpp
 * @lcpr version=30204
 *
 * [3629] 通过质数传送到达终点的最少跳跃次数
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

const int MX = 1e6 + 1;
vector<int> factors[MX];
bool init = [] () { // 匿名lambda 初始化，实现了埃拉托色尼筛法
    for (int i = 2; i < MX; i++) {
        if (factors[i].empty()) { // i为质数 (没有因数列表)
            for (int j = i; j < MX; j += i) { // 遍历i的倍数
                factors[j].push_back(i); // i加入j的因数表
            }
        }
    }
    return true;
} ();

class Solution {
    // I. 倒序BFS
    // 从数组末尾n - 1逆向寻找到达起点的最短路径
    // 预处理：首先用埃氏筛计算范围内的质数表factors,
    // 建图：遍历数组，数字是质数则将索引存入edges作为跳跃中转站
    // bfs: 对当前队列q中的索引i进行三种移动：
    // 1. 相邻：i左移到i-1，右移到i+1
    // 2. 跳跃：遍历nums[i]所有质因数p, edges[p]跳跃到p的索引j
    // 重复1,2直到回到第一个元素
    // tc: O((n + MX) logMX) [MX: 数组最大值]， sc: O(MXloglogMX)

    // 正序BFS
    // 建图的时候我们改变edges初始化方法，将所有数字的索引按照factors分类
    // tc: O((n + MX) logMX), sc: O(MXloglogMX)
public:
    int minJumps(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // unordered_map<int, vector<int>> edges;
        // for (int i = 0; i < n; i++) {
        //     int a = nums[i];
        //     if (factors[a].size() == 1) { // a为质数
        //         edges[a].push_back(i); // edges存入质数对应的下标（可能不止一个）
        //     }
        // }
        // int res = 0;
        // vector<bool> seen(n, false);
        // seen[n - 1] = true;
        // vector<int> q = {n - 1};
        // while (true) {
        //     vector<int> q2;
        //     for (int i: q) {
        //         if (i == 0) return res;
        //         if (i > 0 && !seen[i - 1]) {
        //             // 可以转移到i-1
        //             seen[i - 1] = true;
        //             q2.push_back(i - 1);
        //         }
        //         if (i < n - 1 && !seen[i + 1]) {
        //             // 可以转移到i+1
        //             seen[i + 1] = true;
        //             q2.push_back(i + 1);
        //         }
        //         for (int p: factors[nums[i]]) {
        //             // nums[i]对应的质因数对应的下标都可以转移到
        //             if (edges.count(p)) {
        //                 for (int j : edges[p]) {
        //                     if (!seen[j]) {
        //                         seen[j] = true;
        //                         q2.push_back(j);
        //                     }
        //                 }
        //                 edges[p].clear();
        //             } 
        //         }
        //     }
        //     q = move(q2); // q2: 可以到达的下一轮位置，
        //     res++;
        // }

        // II.
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int p: factors[nums[i]]) {
                edges[p].push_back(i); 
                // p如果是nums[i]的质因数，则edges[p]包含i
            }
        }
        int res= 0;
        vector<bool> seen(n, false);
        seen[0] = true;
        vector<int> q = {0};
        while (true) {
            vector<int> q2;
            for (int i : q) {
                if (i == n - 1) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }
                if (factors[nums[i]].size() == 1) {
                    int p = nums[i];
                    if (edges.count(p)) {
                        for (int j : edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q = move(q2);
            res++;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [4,6,5,8]\n
// @lcpr case=end

 */


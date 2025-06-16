/*
 * @lc app=leetcode.cn id=2360 lang=cpp
 * @lcpr version=30204
 *
 * [2360] 图中的最长环
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
class Solution {
    // 只有一个出边大大简化了这道题
    // 任意结点开始遍历，结果有三种：
    //      1. 最终到一个没有出边的结点，则这条路径上无环
    //      2. 最终发现u, u在‘此轮’遍历中被发现，
    //          记录第一次发现的指标x, 第二次y, 则长度为y - x,可以结束遍历
    //      3. 最终发现v, v在‘前某轮'遍历中被发现，则v和它的环必定在那轮遍历中被访问计算
    //          可以直接结束遍历
    // 使用current_label, 记录每个结点第一次被遍历到的编号，init = 0
    // 发现新节点，++，从节点i遍历，首先记录当前current_label, 记为start_label
    // 如果发现新节点，current_label++
    // 遍历到某节点，其编号>start_label, 则这个节点必然是在这一轮遍历中被访问的，得到环
    // 遍历到某节点，其编号<=start_label, 说明是之前某轮遍历到的
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> label(n);
        int current_label = 0, ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (label[i])
            { // i节点已经被访问过了
                continue;   
            }
            int pos = i, start_label = current_label;
            while (pos != -1)
            {
                current_label++;
                
                if (label[pos])
                {// 遇到已经遍历过的节点
                    if (label[pos] > start_label)
                    {// 这一次i循环中遍历的
                        ans = max(ans, current_label - label[pos]);
                    }
                    break;
                }
                label[pos] = current_label;
                pos = edges[pos];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,4,2\n[2,-1,3,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2975 lang=cpp
 * @lcpr version=30204
 *
 * [2975] 移除栅栏得到的正方形田地的最大面积
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
    // I. 枚举够了
    // 因为hFences.leng, vFences.leng <= 600
    // 分别求出水平、垂直方向上去除栅栏所能得到的所有边长
    // 得到两个集合，再求出两个集合交集中的最大值，求平方即可
    // 交集为空，则答案=-1
    // 具体而言，我们在两个方向上计算出任意两个栅栏之间的距离
    // (去除两栅栏之间的栅栏后形成的边长)即可
    // tc = sc: O(h^2 + v^2), h = |hFences|, v = |vFences|
public:
    int MOD = 1e9 + 7;
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges) {
            if (vEdges.find(e) != vEdges.end()) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = 1ll * res * res % MOD;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n3\n[2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 6\n7\n[2]\n[4]\n
// @lcpr case=end

 */


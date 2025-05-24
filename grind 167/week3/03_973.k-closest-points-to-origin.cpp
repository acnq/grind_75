// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=973 lang=cpp
 * @lcpr version=30204
 *
 * [973] 最接近原点的 K 个点
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

#include <cmath>
#include <random>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // static bool cmp(vector<int>& a, vector<int>& b) {
    //     return a[0] < b[0];
    // }
    mt19937 gen{random_device{}()};
    void random_select(vector<vector<int>>& points, int left, int right, int k) {
        // random_select(left, right, k)表示划分数组points的[left, right]区间
        // 找到其中第k个距离最小的点，一次划分之后，设pivot下标为i,
        // [left, i-1] 都小于等于pivot, [i + 1, right]都大于pivot
        // 若 k = i - left + 1, pivot就是第k个距离最小的点，结束递归
        // 若 k < i - left + 1, 第k个距离最小的点在pivot左侧，random_select(left, i-1, k)
        // 若 k > i - left + 1, 第k个距离最小的点在pivot右侧，random_select(i+1, right, k - (i - left + 1))
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[right], points[pivot_id]);
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot)
            {
                ++i;
                swap(points[i], points[j]);
            }
        }
        ++i;
        swap(points[i], points[right]);
        // [left, i-1] 均 <= pivot, [i+1, right]均>= pivot
        if (k < i - left + 1)
        {
            random_select(points, left, i - 1, k);
        } else if (k > i - left + 1)
        {
            random_select(points, i + 1, right, k - (i - left + 1));
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // int n = points.size(); 
        // vector<vector<int>> dist(n, vector<int>(2));
        // vector<vector<int>> k_clos;
        // for(int i = 0; i < points.size(); i++) {
        //     dist[i][0] = pow(points[i][1], 2) + pow(points[i][0], 2);
        //     dist[i][1] = i;
        // }
        // sort(dist.begin(), dist.end(), cmp); // 降序
        // for (int i = 0; i < k; i++)
        // {
        //     k_clos.push_back(points[dist[i][1]]);
        // }
        // return k_clos;
        // 化简
        // sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v){
        //     return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        // });
        // return {points.begin(), points.begin() + k};
        // 大根堆
        // priority_queue<pair<int, int>> q;
        // for (int i = 0; i < k; i++)
        // {
        //     q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        // }
        // int n = points.size();
        // for (int i = k; i < n; i++)
        // {
        //     int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        //     if (dist < q.top().first)
        //     {
        //         q.pop();
        //         q.emplace(dist, i);
        //     }
        // }
        // vector<vector<int>> ans;
        // while (!q.empty())
        // {
        //     ans.push_back(points[q.top().second]);
        //     q.pop();
        // }
        // return ans;
        // 快速选择
        int n = points.size();
        random_select(points, 0, n - 1, k);
        return {points.begin(), points.begin() + k};      
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[-2,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,3],[5,-1],[-2,4]]\n2\n
// @lcpr case=end

 */


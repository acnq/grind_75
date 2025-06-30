/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
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
    // I. 堆
    // 首先遍历整个数组，记录每个数字出现的次数，然后返回出现次数数组的前k个最大值
    // 这个“出现次数数组”要是直接排序容易O(NlogN), 我们使用小顶堆即可
    // 遍历“频率数组”，堆的元素个数<k, 入堆，
    //                          =k, 检查堆顶和当前元素，堆顶大则直接舍弃当前; 否则弹出堆顶，当前值入堆
    // tc: O(N logk), sc: O(N)
    
    // 快速排序
    // 同样获得一个“出现次数数组”， 但这次我们使用基于快速排序的方案求出前k个最大
    // arr[l:r]划分之后，根据k与左半arr[i:(q-1)]的关系
    //  若k <= q-i, 则arr[l:r]前k的最大值就是arr[i:(q-1)]前k的最大值
    //            否则，arr[l:r]前k的最大值，等于左侧全部，加上右侧arr[(q+1):j]前k - (q - i)大的值
    // 因为只需要在一个分支递归搜索，所以平均tc降为O(N)
public:
    // I.
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    // II.
    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k) {
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int idx = start;
        for (int i = start + 1; i <= end; i++)
        {
            // 双指针把不小于pivot的元素放到左边
            // 小于pivot的放到右边
            if (v[i].second >= pivot)
            {
                swap(v[idx + 1], v[i]);
                idx++;
            }
        }
        swap(v[start], v[idx]);

        if (k <= idx - start)
        {
            // 前k大的值都在左侧
            qsort(v, start, idx - 1, ret, k);
        } else
        {
            // 前k大的值等于左侧全部元素
            // +右侧前k-(idx - start + 1)大的元素
            for (int i = start; i <= idx; i++)
            {
                ret.push_back(v[i].first);
            }
            if (k > idx - start + 1)
            {
                qsort(v, idx + 1, end, ret, k - (idx - start + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // I.
        // unordered_map<int, int> occurs;
        // for(auto& v: nums) {
        //     occurs[v]++;
        // }
        // // pair首元素代表数组值，第二个代表出现次数
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);   
        // for (auto& [num, count] : occurs) {
        //     if (q.size() == k)
        //     {
        //         if (q.top().second < count)
        //         {
        //             q.pop();
        //             q.emplace(num, count);
        //         }
        //     } else
        //     {
        //         q.emplace(num, count);
        //     }
        // }
        // vector<int> ret;
        // while (!q.empty())
        // {
        //     ret.emplace_back(q.top().first);
        //     q.pop();
        // }
        // return ret;

        // II.
        // 获取出现次数
        unordered_map<int, int> occurs;
        for (auto& v: nums) {
            occurs[v]++;
        }
        vector<pair<int, int>> values;
        for(auto& kv: occurs) {
            values.push_back(kv);
        }
        vector<int> ret;
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=2747 lang=cpp
 * @lcpr version=30204
 *
 * [2747] 统计没有收到请求的服务器数目
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 排序+滑动窗口
    // logs按照时间排序，queries连同下标按时间排序
    // 对于q = queries[i], 使用双指针维护实践范围[q - x, q]内的log
    // 右指针不断加入时间不超过q的日志，如果对应服务器的请求数从0变1
    // 则说明首次出现在窗口中，服务器数量s++,。
    // 左指针移除小于q-x的日志；如果服务器的请求数减为0，
    // 说明他已经不在窗口中，s--。此时窗口内共有s台收到请求
    // 答案为n - s;
    // tc: O(n + mlogm + qlogq), O(n): 初始化cnt用时， 双指针O(m + q)耗时合并在排序中
    // sc: O(n + q + logm + logq) 哈希+临时数组+排序
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        vector<int> ids(queries.size());
        iota(ids.begin(), ids.end(), 0); // 填充0,1,2, ......, |queries|-1
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        }); // 根据访问时间将queries的索引排序

        vector<int> ans(queries.size()), cnt(n + 1);
        int left = 0, right = 0, active = 0;
        for (int i : ids) {
            int q = queries[i];
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right][0];
                right++;
                if (cnt[id] == 0) {
                    active++;
                }
                cnt[id]++;
            }

            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];
                left++;
                cnt[id]--;
                if(cnt[id] == 0) {
                    active--;
                }
            }
            ans[i] = n - active;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,3],[2,6],[1,5]]\n5\n[10,11]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[2,4],[2,1],[1,2],[3,1]]\n2\n[3,4]\n
// @lcpr case=end

 */


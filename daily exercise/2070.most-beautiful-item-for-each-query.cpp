// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2070 lang=cpp
 * @lcpr version=30204
 *
 * [2070] 每一个查询的最大美丽值
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
    // 二分查找
        // 每次查找两步：1. 寻找所有价格小于等于价格的物品
        // 2. 求出最大美丽值
        // 1. items 升序排序，找到临界下标
        // 2. 将items[i][1]修改为下标<= i的物品的最大美丽值
        // 将此作为查询值，如果下标不合法，则所有物品价格均高于查询值，返回0

public:
    static bool compare_item(vector<int>& item1, vector<int>& item2) {
        return item1[0] < item2[0];
    }
    int query_binearch(const vector<vector<int>>& items, int q) {
        int n = items.size();
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (items[mid][0] > q)
            {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0)
        {
            // 所有物品价格均大于查询价格
            return 0;
        } else {
            // 返回小于等于查询值的最大美丽值
            return items[l - 1][1];
        }
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // 首先按照价格排序
        sort(items.begin(), items.end(), compare_item);
        int n = items.size();

        // 修改美丽值
        for (int i = 1; i < n; i++)
        {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        // 二分查找
        vector<int> res;
        for (int q: queries)
        {
            res.push_back(query_binearch(items, q));
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumBeauty
// paramTypes= ["number[][]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,2],[3,2],[2,4],[5,6],[3,5]]\n[1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,2],[1,3],[1,4]]\n[1]\n
// @lcpr case=end

// @lcpr case=start
// [[10,1000]]\n[5]\n
// @lcpr case=end

 */


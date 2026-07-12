/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 * @lcpr version=30204
 *
 * [1331] 数组序号转换
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
    // I. 排序 + 哈希
    // 保存排序玩的元素，然后用哈希表保存各个元素序号
    // tc: O(nlogn), sc: O(n)
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> ranks;
        vector<int> ans(arr.size());
        for (auto& a: sorted){
            if (!ranks.count(a)) {
                ranks[a] = ranks.size() + 1;
                // 排序后元素的序号就是其之前元素之个数+1
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [40,10,20,30]\n
// @lcpr case=end

// @lcpr case=start
// [100,100,100]\n
// @lcpr case=end

// @lcpr case=start
// [37,12,28,9,100,56,80,5,12]\n
// @lcpr case=end

 */


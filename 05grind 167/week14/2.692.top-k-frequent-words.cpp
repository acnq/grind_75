/*
 * @lc app=leetcode.cn id=692 lang=cpp
 * @lcpr version=30204
 *
 * [692] 前K个高频单词
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
    // I. 哈希表 + 排序
    // 哈希表存储每个单词出现的频率，然后根据此降序排序，返回前k个字符串即可
    // 排序时，如果有相同频率，要对哈希表中两者字典序排序
    // tc: O(l * n + l * mlogm), n: words.length, l: words元素的平均长度，m: 字符串种类的数量
    // sc: O(l * m) (哈希表大小)

    // II. 优先队列
    // 将每个字符串插入到小根优先队列中，如果大小超过了k, 那么就将队顶元素弹出，
    // 这样最终剩下的k个元素就是前k个出现最多的单词
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // I.
        // unordered_map<string, int> cnt;
        // for (auto& word: words) {
        //     cnt[word]++;
        // }
        // vector<string> rec;
        // for (auto& [key, value]: cnt) {
        //     rec.emplace_back(key);
        // }
        // sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
        //     return cnt[a] == cnt[b] ? a < b: cnt[a] > cnt[b];
        // });
        // rec.erase(rec.begin() + k, rec.end());
        // return rec;

        // II.
        unordered_map<string, int> cnt;
        for (auto& word: words) {
            cnt[word]++;
        }
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
        for (auto& it: cnt) {
            que.emplace(it);
            if (que.size() > k)
            {
                que.pop();
            }
        }

        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = que.top().first;
            que.pop();
        }
        return ret;       
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["i", "love", "leetcode", "i", "love", "coding"]\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */


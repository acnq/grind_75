/*
 * @lc app=leetcode.cn id=1733 lang=cpp
 * @lcpr version=30204
 *
 * [1733] 需要教语言的最少人数
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
    // I. 贪心
    // 一对好友之间的无非两种情况
    // 1. 掌握的语言有交集->可以互相沟通
    // 2. 掌握的语言没有交集->不能沟通
    // 第一种情况无需考虑
    // 第二种情况需要我们考虑选择某种语言，使得二者互相沟通
    // 要找到需要教授的用户数量最少，首先列出所有不能互相沟通的好友
    // 然后，我们直接贪心的选择"不能互相沟通的人中，被最多人掌握的语言"
    // 作为目标语言教授，这是因为没有掌握该语言的人数最少。
    // 可以证明：选择其他语言，需要教授的人数一定不会更少
    // 视线中，哈希表mp判断这对好友是否能够互相沟通，
    // 集合cncon存储不能互相沟通的好友。
    // 长度=n的数组cnt来统计每种语言被多少人掌握
    // 遍历cnt， 找出最大的值max_cnt, 需要教的语言最少人数就是
    // |cncon| - max_cnt
    // tc: O(m * n), sc: O(m + n) [m: 好友对数，n: 语言类数] 
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> cncon;// 不能交流的朋友集合
        for (auto friendship: friendships) {
            unordered_map<int, int> mp;
            bool conm = false; // 这对朋友能否交流
            for (int lan: languages[friendship[0] - 1]) {
                mp[lan] = 1;
            }
            for (int lan: languages[friendship[1] - 1]) {
                if (mp[lan]) {
                    conm = true;
                    break;
                }
            }
            if (!conm) {
                cncon.insert(friendship[0] - 1);
                cncon.insert(friendship[1] - 1);
            }
        }
        int max_cnt = 0;
        vector<int> cnt(n + 1, 0);
        for (auto friendship: cncon) { // 仅在不可交流的朋友中贪心
            for (int lan: languages[friendship]) {
                cnt[lan]++;
                max_cnt = max(max_cnt, cnt[lan]);
            }
        }
        return cncon.size() - max_cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1],[2],[1,2]]\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[2],[1,3],[1,2],[3]]\n[[1,4],[1,2],[3,4],[2,3]]\n
// @lcpr case=end

 */


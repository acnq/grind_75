// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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

#include <numeric> // accumulate
// @lcpr-template-end
// @lc code=start
class Solution {
    // meta data: str.size <= 1e4, str[i].size <= 100, str[i] only contains little letter
    // 思考：10000 能暴力么，但是好像不枚举也没有办法？
    // 结论：暴力不过，都想到skipIdx了，看了答案之后想到，为什么不直接一次遍历提取map, 然后分组呢？
public:
    bool isAnagrams(string s, string t) {
        vector<int> stats(26, 0);
        for(char s_ch: s) {
            stats[s_ch - 'a']++;
        }
        for(char t_ch: t) {
            stats[t_ch - 'a']--;
        }
        for(int i : stats) {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 超时
        // vector<vector<string>> res;
        // unordered_set<int> skipIdx;
        // for (int i = 0; i < strs.size(); i++)
        // {
        //     if (skipIdx.count(i) == 0)
        //     {
        //         vector<string> group;
        //         group.push_back(strs[i]);
        //         skipIdx.insert(i);

        //         for (int j = i + 1; j < strs.size(); j++)
        //         {
        //             if (skipIdx.count(j) == 0 && isAnagrams(strs[i], strs[j]))
        //             {
        //                 group.push_back(strs[j]);
        //                 skipIdx.insert(j);
        //             }
        //         }
        //     res.push_back(group);
        //     }
        // }
        // return res;   

        // I. 排序法
        // unordered_map<string, vector<string>> mp;
        // for(string str: strs) {
        //     string key = str;
        //     sort(key.begin(), key.end());
        //     mp[key].push_back(str);
        // } 

        // vector<vector<string>> ans;
        // for (auto it: mp)
        // {
        //     vector<string> group = it.second;
        //     ans.push_back(group);
        // }
        // return ans;

        // II. 哈希部分可以改成字母表统计数据，不过要自定义哈希函数，有点难，下面的代码是参考的标准答案
        // 对 array<int, 26>> 的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);// hash<int> 是C++ std 整数哈希
            });
        }; 

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for(string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; i++)
            {
                counts[str[i] - 'a']++;
            }
            mp[counts].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */


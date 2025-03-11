/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 * @lcpr version=30204
 *
 * [3305] 元音辅音字符串计数 I
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

#include <set>
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long count_k(const string& word, int m, const set<char>& vowels) {
        int n = word.size(), consonants = 0;
        long long res = 0;
        map<char, int> occ;

        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n && (consonants < m || occ.size() < vowels.size()))
            {
                if (vowels.count(word[j]))
                {
                    occ[word[j]]++;
                } else {
                    consonants++;
                }
                j++;
            }
            if (consonants >= m && occ.size() == vowels.size())
            {
                res += n - j + 1;
            }
            if (vowels.count(word[i]))
            {
                occ[word[i]]--;
                if (occ[word[i]] == 0)
                {
                    occ.erase(word[i]);
                }
            } else {
                consonants--;
            }
        }
        return res;
    }

    int countOfSubstrings(string word, int k) {
        // 暴力枚举
        // set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        // int n = word.size();
        // long long res = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     set<char> occ;
        //     int consonants = 0;
        //     for (int j = i; j < n; j++)
        //     {
        //         if (vowels.count(word[j]))
        //         {
        //             occ.insert(word[j]);
        //         } else {
        //             consonants++;
        //         }
                
        //         if (occ.size() == vowels.size() && consonants == k)
        //         {
        //             res++;
        //         }
        //     }
        // }
        // return res;

        // 滑动窗口
        // count(i): 每个元音至少出现一个，并且至少包含i个辅音的子串总数
        // 答案为count(i) - count(i + 1)
        // 区间[i, j), 右移j, 直到[i, j)包含每个元音和k个辅音，或者j = n;
        // 如果满足k辅音全元音，左端点为i的子串满足条件的数目 n - j + 1
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return count_k(word, k, vowels) - count_k(word, k + 1, vowels);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aeioqq"\n1\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n0\n
// @lcpr case=end

// @lcpr case=start
// "ieaouqqieaouqq"\n1\n
// @lcpr case=end

 */


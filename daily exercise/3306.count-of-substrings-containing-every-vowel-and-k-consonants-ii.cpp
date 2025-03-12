/*
 * @lc app=leetcode.cn id=3306 lang=cpp
 * @lcpr version=30204
 *
 * [3306] 元音辅音字符串计数 II
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

#include <map>
#include <set>

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

    // 和昨天的题目3305一样，只是时间变紧了
    // 用昨天第二种方法就可以了

    long long countOfSubstrings(string word, int k) {
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


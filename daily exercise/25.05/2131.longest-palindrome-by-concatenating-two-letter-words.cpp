// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2131 lang=cpp
 * @lcpr version=30204
 *
 * [2131] 连接两字母单词得到的最长回文串
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
    // 审题：“两个""小写字母”的单词, 难度陡降
    // 本身不是回文串的，找到他的镜像即可，否则不能取
    // 如果本身是回文串（只有"xx"这一种情况），而找不到镜像，则只能取一份放在中间
public:
    int longestPalindrome(vector<string>& words) {
        // int res = 0;
        // unordered_map<string, int> stats1, stats2;
        // for(string word: words) {
        //     if (word[0] == word[1])
        //     {
        //         if (stats1.count(word) != 0 && stats1[word] > 0)
        //         {
        //             res += 4;
        //             stats1[word]--;
        //         } else {
        //             stats1[word]++;
        //         }
        //     } else {
        //         string tmp = word;
        //         reverse(tmp.begin(), tmp.end());
        //         if (stats2.count(tmp) && stats2[tmp] > 0)
        //         {
        //             res += 4;
        //             stats2[tmp]--;
        //         } else {
        //             stats2[word]++;
        //         }
        //     }
        // }
        // if (!stats1.empty())
        // {
        //     for(auto& [wd, cnt]: stats1) {
        //         if (cnt > 0)
        //         {
        //             res += 2;
        //             break;
        //         }
        //     }
        // }
        
        // return res;

        // 官方解法（空间复杂度更低）：
        unordered_map<string, int> freq;
        for(const string& word: words) {
            ++freq[word];
        }

        int res = 0;
        bool mid = false;
        for(const auto& [word, cnt]: freq) {
            string rev = string(1, word[1]) + word[0];
            if (word == rev)
            {
                if (cnt % 2 == 1)
                {
                    mid = true;
                }
                res += 2 * (cnt / 2 * 2);                
            }
            else if (word > rev) // 避免重复
            {
                res += 4 * min(freq[word], freq[rev]);
            }
        }
        if (mid)
        {
            res += 2;
        }
        return res;
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=longestPalindrome
// paramTypes= ["string[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// ["lc","cl","gg"]\n
// @lcpr case=end

// @lcpr case=start
// ["ab","ty","yt","lc","cl","ab"]\n
// @lcpr case=end

// @lcpr case=start
// ["cc","ll","xx"]\n
// @lcpr case=end

// @lcpr case=start
// ["dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"]\n
// @lcpr case=end

// @lcpr case=start
// ["bb","bb"]\n
// @lcpr case=end

 */


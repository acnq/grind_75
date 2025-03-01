// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30204
 *
 * [125] 验证回文串
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
public:
    bool isPalindrome(string s) {
        // string s_ = "";
        // for(char ch: s) {
        //     if (isalnum(ch))
        //     {
        //         s_.append(1, ch);
        //     }
        // }
        // int N = s_.size();
        // int i = 0, j = N - 1;
        // while (i <= j)
        // {
        //     if(tolower(s_[i]) != tolower(s_[j])){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;        

        int N = s.size();
        int i = 0, j = N - 1; // begin, end ptr
        if(i == j) return true;
        while (i < j && i < N)
        {
            while (!isalnum(s[i]) && i < N)
            {
                i++;
            }
            while (!isalnum(s[j]) && j > 0)
            {
                j--;
            }
            
            if(i < j) { // 注意这个判断，否则'.,'之类的会进入下一个判断导致错判
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
                i++;
                j--;
            }
            
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// ".,"\n
// @lcpr case=end

 */


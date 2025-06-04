// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 * @lcpr version=30204
 *
 * [1163] 按字典序排在最后的子串
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
    // I. 双指针
    // 官方题解有点太难懂了，ylb的解法比较好懂
    // 显然，最大子串一定是后缀（s[i:-1])
    // 使用i,j双指针，其中指针i指向当前已知字典序最大的子串的起始位置
    // 指针j指向当前考虑子串的起始位置。另外，还需要一个变量k记录当前比较到的位置
    // 我们从最左边开始比较，i.e. i = 0, j = 1, k = 0
    // 枚举k, 比较s[i + k]和s[j + k]
    //  如果s[i + k] = s[j + k], 说明s[i:i+k]和s[j:j+k]相同，k++, 继续比较s[i + k]和s[j + k]
    //  如果s[i + k] < s[j + k], 说明s[j:j+k]的字典序更大，更新i=i+k+1, k=0,若有i>=j, 也将j=i+1
    //      这意味着我们跳过了s[i:i+k]开头的所有后缀子串，因为他们一定小于s[j:j+k]为起始的后缀子串
    //  同理，如果s[i + k] > s[j + k], j=j+k+1, k = 0, 跳过s[j:j+k]起始的所有子串，因为他们一定小于s[i:i+k]
    // 返回最后的i
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0;
        for (int j = 1, k = 0; j + k < n; )
        {
            if (s[i + k] == s[j + k])
            {
                k++;
            } else if (s[i + k] < s[j + k])
            {
                i += k + 1;
                k = 0;
                if (i >= j)
                {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=lastSubstring
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */


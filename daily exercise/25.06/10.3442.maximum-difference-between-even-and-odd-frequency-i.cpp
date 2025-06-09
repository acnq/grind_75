/*
 * @lc app=leetcode.cn id=440 lang=cpp
 * @lcpr version=30204
 *
 * [3442] 奇偶频次之间的最大差值 I
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
    int maxDifference(string s) {
        // int n = s.size();
        // vector<int> freq(26, 0);
        // for(int i = 0; i < n; i++) {
        //     freq[s[i] - 'a']++;
        // } 
        // int maxOdd = 0, minEven = INT_MAX;
        // for(int i = 0; i < 26; i++) {
        //     // cout << i << " " << freq[i] << endl;
        //     if(freq[i] % 2 == 1) { 
        //         maxOdd = max(maxOdd, freq[i]);
        //     } else if(freq[i] % 2 == 0 && freq[i] != 0) {
        //         minEven = min(minEven, freq[i]);
        //     }
        // }
        // return maxOdd - minEven;

        // 官方用的哈希
        unordered_map<char, int> c;
        for(char ch: s) {
            c[ch]++;
        }
        int maxOdd = 1, minEven = s.size();
        for(const auto& [_, value]: c) {
            if (value % 2 == 1) {
                maxOdd = max(maxOdd, value);
            } else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};

int main() {
    Solution s;
    int res1 = s.maxDifference("aaaaabbc");
    cout << res1 << endl;
    int res2 = s.maxDifference("abcabcab");
    cout << res2 << endl;
}
// @lc code=end



/*
// @lcpr case=start
// "aaaaabbc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcab"\n
// @lcpr case=end

 */


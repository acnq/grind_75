/*
 * @lc app=leetcode.cn id=1980 lang=cpp
 * @lcpr version=30204
 *
 * [1980] 找出不同的二进制字符串
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

#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 化为整数
    // 长为n的二进制字符串看做[0, 2^n - 1]区间内的整数的二进制表示
    // 注意到nums中总共是n个元素，而[0, n]中总共n+1个，所以在这个闭区间中一定有个不在nums中
    // 我们预处理哈希集合，遍历[0, n]中的整数，找到第一个不在nums中的即可
    // tc: O(n^2), sc: O(n)
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // 预处理对应整数的哈希集合
        unordered_set<int> vals;
        for (const string& num : nums) {
            vals.insert(stoi(num, nullptr, 2));
        }
        // 找出首个不在哈希集合中的元素
        int val = 0;
        while (vals.count(val)) {
            val++;
        }
        // 整数转化回二进制字符串返回
        // bitset<16>: 固定16位，不够补0，高位在左的比特集合
        // to_string: 直接转化为字符串
        // substr(start, len): 攫取第16-n位开始之后最多16位的子串 
        return bitset<16>(val).to_string().substr(16 - n, 16);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["01","10"]\n
// @lcpr case=end

// @lcpr case=start
// ["00","01"]\n
// @lcpr case=end

// @lcpr case=start
// ["111","011","001"]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3756 lang=cpp
 * @lcpr version=30204
 *
 * [3756] 连接非零数字并乘以其数字和 II
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

const int MOD = 1e9 + 7;
const int MAX_N = 100001; // queries和s长度最大值
long long pow10[MAX_N];

// init 对于所有测试用例只运行一次
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
    // I. 前缀数组
    // pow10[i]表示10的i次幂后的求余结果
    // 我们通过T3754的数字转字符串的方法，得到任意前缀的x和sum值
    // 我们还维护第三个数组:
    // cnt用来表示字符串前缀中包含的非零数字的数量
    // queries查询，利用前缀数组求差的方法，得到任意范围内的x和sum值
    //
    // tc = sc = O(MAX_N)
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        vector<long long> x(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            x[i + 1] = (d > 0) ? (x[i] * 10 + d) % MOD : x[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            int l =queries[i][0];
            int r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_x = (x[r] - x[l] * pow10[length] % MOD + MOD) % MOD;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_x * val_sum) % MOD;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "10203004"\n[[0,7],[1,3],[4,6]]\n
// @lcpr case=end

// @lcpr case=start
// "1000"\n[[0,3],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// "9876543210"\n[[0,9]]\n
// @lcpr case=end

 */


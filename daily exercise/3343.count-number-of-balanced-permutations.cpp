/*
 * @lc app=leetcode.cn id=3343 lang=cpp
 * @lcpr version=30204
 *
 * [3343] 统计平衡排列的数目
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
    // I.
    // 设num长度为n, 数字i出现次数为cnt[i]，数字总和为tot
    // 则num可以构成不同的排列总数为： S = \frac{n!}{\Prod_i=0^9cnt[i]!}
    // num 有 m = \ceiling{n / 2}个奇数位，有 \floor{n / 2} = m - n个偶数位
    // 设数字i中填充奇数位的数目为k_i，则填充偶数位的数目为cnt[i] - k_i

    // 首先考虑数字0, 奇数位填了k_0个，有m个位置可选，偶数位填了cnt[0] - k_0, 有 n - m 个位置
    // 此时方案数 T_0 = C_m^{k_0} * C_{n-m}^{cnt[0] - k_0}
    // 数字i(>0), T_i = C_{m - \sum_{j=0}^{i-1}k_j}^{k_i} * C_{n - m - \sum_{j=0}^{i-1}(cnt[j] - k_j)}^{cnt[i] - k_i}
    // 总数 T = \prod_{i=0}^9T_i;

    // 记忆化搜索：
    // dfs(i, curr, oddcnt): 
    // 剩余需要填充的数字为[i: 9],
    // 剩余奇数位上的元素个数为oddcnt, 
    // 奇数位上元素和为curr

    // 枚举数字i分出j个填充在奇数位上的情况，此时oddCnt选择j个位置
    // 剩余cnt[i] - j个放到\sum_{k=i}^9cnt[k] - oddCnt个偶数位上
    // i的填充方案为S_j = C_{oddCnt}^j * C_{\sum_{k=i}^9cnt[k] - oddCnt}^{cnt[i] - j}

    // 剩余子问题
    // 还需要分配的数字为：[i + 1, 9];
    // 奇数位上还需要填充：oddCnt - j 个；
    // 奇数位剩余的元素和为： curr - j * i;
    // 递推公式
    // dfs(i, curr, oddCnt) = \sum_{j=0}^{cnt[i]} S_j * dfs(i + 1, curr - j * i, oddCnt - j);
    // 入口：
    // dfs(0, m, \frac{tot}/2)
    // i > 10 终止，i = 10, oddCnt = 0, curr = 0 返回1，否则返回0

    // 剪枝：
    // i. 假设i在奇数位上的填充数为k_i, 
    // 则1. k_i <= min(cnt[i], oddCnt); 2. cnt[i] - k_i \sum_{j=i}^9cnt[i] - oddCnt (偶数位空位也不能超过总空位)
    // ii. 未填充的数字总数小于oddCnt, 非法状态，提前终止
    // iii. T可以化简位\frac{m!}{\prod_{i=0}^9k_i!}\frac{(n - m)!}{\prod{i=0}^9(cnt[i] - k_i)!}
    //      注意分子是固定的，只需计算分母即可，代码中我们使用乘法逆元

    // II. 自底向上

    // f[i][curr][oddCnt]: 当前已分配[0, i], 奇数位上已分配个数oddCnt, 元素和为curr的方案数
    // 偶数位上已分配的数字个数为\sum_{k=0}^i cnt[k] - oddCnt
    // 枚举当前奇数位上分配数字个数j, 此时偶数位上分配数字cnt[i] - j个
    // 此时数字i填充方案数为W_j = C_{oddCnt}^j * C_{\sum_{k=0}^i cnt[k] - oddCnt}^{cnt[i] - j}

    // 递推公式
    // f[i][curr][oddCnt] = \sum_{j=0}^{cnt[i]} W_j * f[i - 1][cur - j * i][oddCnt - j]
    // f[0][0][0] = 1
    // res = f[9][tot/2][m]
    // 注意j <= OddCnt, 依次去除无效状态

public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {

        // I.
        // int tot = 0, n = num.size();
        // vector<int> cnt(10);
        // for(char ch: num) {
        //     int d = ch - '0';
        //     cnt[d]++;
        //     tot += d;
        // }

        // if (tot % 2 != 0)
        // {
        //     return 0;
        // }

        // int target = tot / 2;
        // int m = (n + 1) / 2;
        // vector<int> psum(11);
        // vector<vector<long long>> comb(m + 1, vector<long long>(m + 1));
        // long long memo[10][target + 1][m + 1];
        // for (int i = 0; i <= m; i++)
        // {
        //     comb[i][i] = comb[i][0] = 1;
        //     for (int j = 1; j < i; j++)
        //     {
        //         comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        //     }
        // }

        // for (int i = 0; i >= 0; i--)
        // {
        //     psum[i] = psum[i + 1] + cnt[i];
        // }
        
        // function<long long(int, int, int)> dfs = [&](int pos, int curr, int oddCnt) -> long long {
        //     if (oddCnt < 0 || psum[pos] < oddCnt || curr > target)
        //     {
        //         return 0;
        //     }
        //     if (pos > 0)
        //     {
        //         return curr == target && oddCnt == 0;
        //     }
            
        //     if (memo[pos][curr][oddCnt] != -1)
        //     {
        //         return memo[pos][curr][oddCnt];
        //     }
            
        //     int evenCnt = psum[pos] - oddCnt;
        //     int long long res = 0;
        //     for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt); i++)
        //     {
        //         long long ways = comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
        //         res = (res + ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) % MOD;
        //     }
        //     memo[pos][curr][oddCnt] = res;
        //     return res;
        // };

        // return dfs(0, 0, m);
        
        // II.
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for(char ch: num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }

        if (tot % 2 != 0)
        {
            return 0;
        }

        int target = tot / 2;
        int m = (n + 1) / 2;
        vector<vector<long long>> comb(m + 1, vector<long long>(m + 1));
        vector<vector<long long>> f(target + 1, vector<long long>(m + 1));

        for (int i = 0; i <= m; i++)
        {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++)
            {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        
        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++)
        {
            /*前i个数字数目之和*/
            psum += cnt[i];
            /* 前i个数字的元素和*/
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, m); oddCnt >= max(0, psum - (n - m)); oddCnt--)
            {
                /* 偶数位需要填充的位数 */
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target); curr >= max(0, totSum - target); curr--)
                {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++)
                    {
                        /* 当前数字在奇数位填充i位，偶数位填充cnt[i] - j位 */
                        long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }
        
        return f[target][m];

    }
};
// @lc code=end



/*
// @lcpr case=start
// "123"\n
// @lcpr case=end

// @lcpr case=start
// "112"\n
// @lcpr case=end

// @lcpr case=start
// "12345"\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1390 lang=cpp
 * @lcpr version=30204
 *
 * [1390] 四因数
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

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 枚举
    // 和我的算法差不多
    // tc: O(N\sqrt(C)), N = |nums|, C: nums最大值的大小，sc:O(1)
    // II. 预处理
    // 算数基本定理：若x有分解: x= \Prod_{i=1}^k p_i^{a_i}, p_i为不同质数
    // 那x的因数总数为factor_cnt(x) = \Prod_{i=1}^k{a_i + 1}
    //  证：因数总数等价于从每个p_i中选择0-a_i个，每个有1+a_i中选择，共k步选完，用乘法原则连乘即可
    // 如果factor_cnt(x) == 4:
    // 则或者x只有一个因数，对应指数3，或者有两个，对应均为1
    // 第一种情况，找到所有不大于C^{1/3}的质数，（C: nums中的最大值）
    //  第二种，找到所有不大于C的质数，两两相乘并筛去超过C的结果
    // 找到所有质数我们用埃拉托色尼筛法或者欧拉筛法
public:
    int fourDiv(int num) {
        int limit = sqrt(num);
        int cnt = 0, divisor = 0;
        for (int i = 2; i <= limit; i++) {
            if (i * i == num) {
                cnt++; // 不能直接break, 
                // 否则16直接被当做四因数返回多算了
                // 看大模型找出来的bugTAT
            }
            if (num % i == 0) {
                cnt++;
                divisor = i;
            }
        }
        if (cnt != 1) {
            return 0;
        } else {
            return 1 + num + divisor + (num / divisor);
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        // I.
        // int sum = 0;
        // for (int num: nums) {
        //     sum += fourDiv(num);
        // }
        // return sum;

        // II
        // C: nums数组元素上限，C3 = \sqrt^3(C)
        int C = 1e5, C3 = 46;
        vector<int> isprime(C + 1, 1);
        vector<int> primes;

        // 埃拉托色尼筛法
        for (int i = 2; i <= C; i++) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int j = i + i; j <= C; j += i) {
                isprime[j] = 0;
            }
        }
        // 欧拉筛法
        // for (int i = 2; i <= C; i++) {
        //     if (isprime[i]) {
        //         primes.push_back(i);
        //     }
        //     for (int prime: primes) {
        //         if (i * prime > C) {
        //             break;
        //         }
        //         isprime[i * prime] = 0;
        //         if (i % prime == 0) {
        //             break;
        //         }
        //     }
        //}
        // 从质数表primes构造四因数
        unordered_map<int,int> factor4;
        for (int prime: primes) {
            if (prime <= C3) {
                factor4[prime * prime * prime] = 1 + prime + prime * prime + prime * prime * prime;
            }
        }
        for (int i = 0; i < primes.size(); i++) {
            for (int j = i + 1; j < primes.size(); j++) {
                if (primes[i] <= C / primes[j]) {
                    factor4[primes[i] * primes[j]]  = 1 + primes[i] + primes[j] + primes[i] * primes[j];
                }
                else {
                    break;
                }
            }
        }

        int ans = 0;
        for (int num: nums) {
            if (factor4.count(num)) {
                ans += factor4[num];
            }
        }
        return ans;
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=sumFourDivisors
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [21,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [21,21]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n
// @lcpr case=end

 */


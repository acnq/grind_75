// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2829 lang=cpp
 * @lcpr version=30204
 *
 * [2829] k-avoiding 数组的最小总和
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
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 瞄了一眼说贪心可以搞定，先自己编编试试
    // 竟然过了，太棒了，第一次自己做出来中等题（也可能是时隔一年，不记得上次有没有了）

    // II. 官方题解的方案更有意思：
    // 若k为奇数，k-a在=> a不在，所以我们只要要求小a在数组中就可以了
    // 从1开始挑，直到\ceiling{k / 2}, 这之后直到k-1位置，都不能放入
    // 如果到\celing{k/2}为止还没到n个，从k开始连续挑选k - \celing{k/2}即可
    // 观察到结果一定是两段等差数列的和，只要按照\ceiling{k / 2}和n的大小关系
    // 讨论即可
    // 感觉这才是面试官想看到的解答，太有才了
public:
    int arithmeticSum(int a1, int d, int n){
        return a1 * n + (n - 1) * n * d / 2;
    }
    int minimumSum(int n, int k) {
        // int sum = 0;
        // set<int> s;
        // for (int i = 1; s.size() < n; i++)
        // {
        //     int j = k - i;
        //     if (s.count(j) >= 1)
        //     {
        //         continue;
        //     } else {
        //         sum += i;
        //         s.insert(i);
        //     }
        // }
        // return sum;

        if(k == 1) {
            return arithmeticSum(1, 1, n);
        }
        if (k / 2 > n)
        {
            return arithmeticSum(1, 1, n);  
        } else {
            return arithmeticSum(1, 1, k / 2) + arithmeticSum(k, 1, n - k / 2);
        }
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumSum
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end

 */


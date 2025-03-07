/*
 * @lc app=leetcode.cn id=2234 lang=cpp
 * @lcpr version=30204
 *
 * [2234] 花园的最大总美丽值
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // 选择flowers中最大的若干元素，加到至少target朵花，成为完善花园
    // 剩余的花加入剩余的元素，使得最小元素尽可能大。

    // 对flowers（假设长度为n）降排序，枚举完善/不完善分界线
    // [0, i) 完善，[i, n) 不完善
    // 完善部分： target * i - \sum_{k=0}^{i-1}flowers[k] (求和部分是一个前缀和，用pre表示)
    // 剩余部分记为rest, 我们首先找到下标j, s.t. 
    // flowers[j]*(n - j) - \sum_{k=j}^{n-1}flower[k] <= rest （求和部分是一个后缀和，用pre表示）
    // flowers[j - 1] * (n - j + 1) - \sum_{k = j-1}^{n-1}flower[k] > rest
    // 也就是说，在[flowers[j], flower[j - 1])这个范围内
    // 用完所有newFlowers可以把每个不完美花园的花卉都增加到至少flowers[j]而不能增加到flowers[j-1]
    // 如果rest还剩下值rest', 平均加到[j, n)的部分下就可以了，
    // 可以证明（见附录)f[j-1] > f[j] + \floor(rest' / n - j)
    // 美丽值：
    // full * i + partial * (min{flower[j] + \floor{rest' / (n - j)}, target - 1})

public:

    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        for (int& x: flowers)
        {
            x = min(x, target); 
            // 大于target的部分不用考虑
            // 因为‘至少’target朵花都会有full的分数
        }
        sort(flowers.begin(), flowers.end(), greater<int>()); 
        //注意这个greater的简单写法，这是<functional>中定义的
        long long sum = accumulate(flowers.begin(), flowers.end(), 0LL); 
        // 0LL: 累加初值，在<numeric>中定义, 也是上文中提及的后缀和
        long long ans = 0;
        if (static_cast<long long>(target) * n - sum <= newFlowers)
        {
            ans = static_cast<long long>(full) * n;
        }
        
        long long pre = 0; // 前缀和
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                pre += flowers[i - 1];
            }
            if (flowers[i] == target)
            {
                continue;
            }
            long long rest = newFlowers - (static_cast<long long>(target) * i - pre);
            if (rest < 0)
            {
                break;
            }
            while (!(j >= i && 
                static_cast<long long>(flowers[j]) * (n - j) - sum <= rest))
            {
                sum -= flowers[j];
                ++j;
            }
            rest -= static_cast<long long>(flowers[j]) * (n - j) - sum;
            ans = max(ans, static_cast<long long>(full) * i + 
                static_cast<long long>(partial) * (min(flowers[j] + rest / (n - j), 
                                                                static_cast<long long>(target) - 1)));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1,1]\n7\n6\n12\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,4,5,3]\n10\n5\n2\n6\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=1526 lang=cpp
 * @lcpr version=30204
 *
 * [1526] 形成目标数组的子数组最少增加次数
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
    // I. 差分数组
    // target[0]需要操作target[0]次变为0
    // 而相邻的target[i]和target[i + 1], 如果target[i] >= target[i + 1]
    // 给target[i] +1时，顺便给target[i + 1] +1, 这样后者就不会占用操作
    // 否则，target[i + 1]还需要target[i + 1] - target[i]次
    // 所以总操作数：
    // target[0] + \sum_{i=0}^{n - 2}\max(target[i + 1] - target[i], 0)
    // 我们可以给出严格证明：
    // d[i] = { a[i]            i = 0
    //      = { a[i] - a[i - 1] i > 0
    // 作为差分数组
    // 1. d[i]的前缀和>= 0 (d[i]的前缀和即是a[i], 而已知a[i] >= 0)
    // 2. \sum_{i=0}^{n-1} d[i] >= 0 (1取i = n - 1)
    // 3. 对a的子数组[L, R]进行操作时，差分数组内外的元素其实都不会变
    // 只有d[L]会-1，d[R + 1]会+1， R = n - 1时，则吸收了+1操作
    // 所以操作的下界：
    // T = \sum_{i=0}^{n-1}\max{d[i], 0}
    // 下界是可以取到的，理由如下
    // 4. d中若有d[i] < 0, 则有0 <= j <= i, s.t. d[i] > 0(否则与1冲突)
    // 于是我们可以找到每个d[R + 1] < 0和d[L] > 0, 前+1后-1直到d>=0
    // 这时我们再找到d[L] > 0, R + 1取n, 操作[L, R]使得d没有正数
    // 这就取到了下界，显然，d变为全0和全0变为d的操作数量相同，
    // 这就得解
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; i++) {
            ans += max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */


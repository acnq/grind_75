/*
 * @lc app=leetcode.cn id=2179 lang=cpp
 * @lcpr version=30204
 *
 * [2179] 统计数组中好三元组数目
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
class FenwickTree
{
private:
    vector<int> tree;
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size())
        {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index ++;
        int res = 0;
        while (index > 0)
        {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};


class Solution {
    // 若i, j, k满足0 <= i < j < k < n,
    // 且 0 <= pos2_{nums1[i]} < pos2_{nums1[j]} < pos2_{nums1[k]} < n
    // 则nums1[i], nums1[j], nums1[k]构成好三元组
    // (因为显然pos1_{nums1[i]} = i)
    
    // 用数组idxMapping表述关系
    // idxMapping[i] = pos2_{nums1[i]}
    // 可见idxMapping也是0到n-1的排列，
    // 求符合i,j,k的三元组，首先固定j, 然后统计
    // idxMapping中，j左侧有多少小于idxMapping[j]的数，记为left
    // 再统计j右侧有多少大于idxMapping[j]的数，记为right
    // left * right 即为中间元素为j的三元组数目，遍历j可得答案
    
    // 计算某侧大于/小于当前元素的个数可以用“树状数组”，
    // 参考T315
    // 应用时，按照idxMapping中值
    // 从小到大遍历，对当前下标pos
    // 求前缀和，i.e. 下标左侧有多少小于idxMapping[pos]的数字
    // 再通过计算得到pos右侧有多少大于idxMapping[pos]
    // 因为按照值大小遍历，我们用reverseIdxMapping保存idxMapping下标
    // 而省略idxMapping本身
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n), reversedIdxMapping(n);
        for (int i = 0; i < n; i++)
        {
            pos2[nums2[i]] = i;
        }
        
        for (int i = 0; i < n; i++)
        {
            reversedIdxMapping[pos2[nums1[i]]] = i;
        }
        FenwickTree tree(n);
        long long res = 0;
        for (int value = 0; value < n; value++)
        {
            int pos = reversedIdxMapping[value];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n - 1 - value) - (pos - left);
            // (pos右侧元素总数) - (pos右侧小于pos元素的数目)
            // 右边括号：所有可能小于pos的元素数(i.e. 当前下标) - 左侧小于pos的元素数
            res += (long long) left * right;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,1,3]\n[0,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,0,1,3,2]\n[4,1,0,2,3]\n
// @lcpr case=end

 */


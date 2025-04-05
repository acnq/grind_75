// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 * @lcpr version=30204
 *
 * [1863] 找出所有子集的异或总和再求和
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
    // I. 递归法 
    // dfs(val, idx)
    // val: 当前选取部分的异或值，idx当前位置
    // n: nums长度，dfs(val, idx)
    // 表示[0, idx-1]表示确定，[idx, n)部分未确定
    // 在idx位置上，两种情况：
    //  选取：val' = val ^ nums[idx], 
    //  不选： val' = val
    // 递归求解dfs(val', idx + 1)
    // idx = n, 出口

    // II. 迭代法
    // 自己编出来了
    
    // III. 数学
    // 子集异或总和某位=0：子集内该位为1的元素数量为偶
    // 子集异或总和某位=1：子集内该位为1的元素数量为奇
    // 数组内某位=1的个数为m, 它的自己里面包含k个1的数量
    // 2^(n - m)C_m^k [n-m个元素的部分随便选，剩下的m选k个]
    // 包含奇数个1的子集数量 2^(n - m) \sum_{k is odd, 0<=k<=m}C_m^k
    //    偶数             2^(n - m) \sum_{k is even, 0<=k<=m}C_m^k
    // 由于(-1 + 1)^m = \sum_{k=0}^mC_m^k(-1)^k 1^{m - k} = 
    // \sum_{k is odd, 0<=k<=m}C_m^k - 2^(n - m) \sum_{k is even, 0<=k<=m}C_m^k = 0
    // 所以包含奇数个1的子集数目 = 包含偶数个1的子集数目 = 全体子集一半 = 2^{n - 1}
    // 用res保存全体元素的按位或
    // res某位为1，对于结果的贡献为2^{n - 1}(奇数个子集的数目)
public:
    int res;
    int n;
    void dfs(int val, int idx, vector<int>& nums) {
        if (idx == n)
        {
            // 终止递归
            res += val;
            return;
        }
        // 选择当前数字
        dfs(val ^ nums[idx], idx + 1, nums);
        // 不选择
        dfs(val, idx + 1, nums);
        
    }
    int subsetXORSum(vector<int>& nums) {

        // I. 递归法 
        // res = 0;
        // n = nums.size();
        // dfs(0, 0, nums);
        // return res;

        // II. 迭代法
        // int n = nums.size();
        // int res = 0;
        // for (int i = 0; i < pow(2, n); i++)
        // {
        //     int xores = 0;
        //     int k = i;
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (k % 2 == 1)
        //         {
        //             xores ^= nums[j];
        //         }
        //         k = k >> 1;
        //     }
        //     res += xores;
        // }
        // return res;
        
        // II.i 官方迭代法
        // int res = 0;
        // int n = nums.size();
        // for (int i = 0; i < (1 << n); i++)
        // {
        //     int tmp = 0;
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i & (1 << j))
        //         {
        //             tmp ^= nums[j];
        //         }
        //     }
        //     res += tmp;            
        // }
        // return res;
        int res = 0;
        int n = nums.size();
        for(auto num: nums) {
            res |= num;
        }
        return res << (n - 1);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=subsetXORSum
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,6,7,8]\n
// @lcpr case=end

 */


// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3356 lang=cpp
 * @lcpr version=30204
 *
 * [3356] 零数组变换 II
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
    //  注意顺序二字, 这直接让题目的复杂度减少了一个档次
    // 1. 二分
    // 顺序k个之后可以，k+1个必然也可以，我们使用二分查找
    // 固定范围K之后，仿照昨天的题目来做即可，只需要修改我们可以减去的数为val_i即可

    // II. 双指针
    // 依旧是构建差分数组diff，不同的是此时我们只在还原的过程中判断差分能否还原为>0的nums
    // 一旦不能，则需要设法调用目前可调用的第一个queries, 
    // 每次调用首先都会影响diff[li]和diff[ri], 进而影响之后的差分运算，然后就是令根据差分还原的前缀和（修改后的nums）变小
    // 如果能够在用完queries中的每一项之前让前缀和变小到0，则此项nums可满足，
    // 需要更新当前queries的最后坐标K, 并操作下一项差分，否则，即，如果queries用完
    // 则说明此项nums无法满足，返回-1
    // q: 调用query之后diff[li], diff[ri]和前缀和psum的更新没有互相重复，
    // 如果i在li, ri之中，此时更新diff[li]已经来不及，因此在if子句中直接psum更新，ri此时更新，以后psum需要
    // 如果i不在li, ri之中，或者li, ri对于此时的i来说都在未来，则更新相应的diff数组，不更新此时的psum，
    // 或者li, ri都在过去，则对过去的diff操作不会影响当下的nums（显然，因为diff 加减相抵，而nums不变）所以psum也不会有影响
    // (但毕竟diff的代码都要跑一遍，进一步优化可考虑加判断跳过)
    // 发布了题解：https://leetcode.cn/problems/zero-array-transformation-ii/solutions/3683110/3356-ling-shu-zu-bian-huan-ii-shuang-zhi-c8p1/ 
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // I.i, 下文代码是正确的，但是超时，主要是check调用次数太多了
        //
        // int n = queries.size();
        // if(n == 1) {
        //     if(check(nums, queries, 1) == false) {
        //         return -1;
        //     } else {
        //         return 1;
        //     };
        // }


        // int left = 0, right = n;
        // while ( right - left > 1)
        // {
        //     if (check(nums, queries, left) == false && check(nums, queries, right) == true)
        //     {
        //         int mid = left + (right - left) / 2;
        //         if (check(nums, queries, mid) == true)
        //         {
        //             right = mid;
        //         } else {
        //             left = mid;
        //         }
        //     } else if (check(nums, queries, left) == true)
        //     {
        //         return 0;
        //     } else {
        //         return -1;
        //     }
        // }
        // return left + 1;

        // I.ii
        // int n = queries.size();
        // if (check(nums, queries, n) == false)
        // {
        //     return -1;
        // }
        // int left = 0, right = n;
        // while (left < right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (check(nums, queries, mid) == true)
        //     {
        //         right = mid;
        //     } else {
        //         left = mid + 1; // 记住这个+1就行
        //     }
        // }
        // return left;

        // II.
        int n = nums.size();
        vector<int> diff(n + 1);
        diff[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            diff[i] = nums[i] - nums[i - 1];
        }

        int k = 0; // res
        int psum = 0; // psum = \sum_{j=0}^i diff[j]
        for(int i = 0; i < n; i++) {
            psum += diff[i];
            while (k < queries.size() && psum > 0)
            {
                int li = queries[k][0], ri = queries[k][1], vali = queries[k][2];
                diff[li] -= vali;
                diff[ri + 1] += vali;
                if (li <= i && i <= ri)
                {
                    psum -= vali;
                }
                k++;                
            }
            
            if (psum > 0)
            {
                return -1;
            }
        }
        return k;
    }

    int check(vector<int>& nums, vector<vector<int>>& queries, int K) {
        // 用差分数组来做
        int n = nums.size();
        vector<int> diff(n + 1); // 见xx行，要+1
        diff[0] = nums[0];
        // 构建差分数组
        for(int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }

        for(int i = 0; i < K; i++) {
            vector<int> query = queries[i];
            int li = query[0], ri = query[1], vi = query[2];
            diff[li] -= vi;
            diff[ri + 1] += vi; // 注意是ri + 1, diff[ri]还是可以减到的，不需要处理
        }

        if (diff[0] > 0)
        {
            return false;
        }

        for (int i = 1; i < n; i++)
        {
            diff[i] += diff[i - 1]; // 注意这个从差分数组恢复原数组的习语
            if (diff[i] > 0)
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minZeroArray
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,0,2]\n[[0,2,1],[0,2,1],[1,1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n[[1,3,2],[0,2,1]]\n
// @lcpr case=end


// @lcpr case=start
// [3,6,4]\n[[2,2,4]]\n
// @lcpr case=end
 */


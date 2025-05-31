// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 * @lcpr version=30204
 *
 * [1007] 行相等的最少多米诺旋转
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
    // I. 贪心
    // i：骨牌下标，A[i]: 此骨牌上半部分数字，B[i]: 此骨牌下半部分数字
    // 若要成功旋转，则存在i, 我们以数字A[i](或者B[i])为基准，可以A(或B)中的所有值都变为A[i](或B[i])
    // 这意味着，他的上半部分或者下半部分的数字x, 在所有其他骨牌中都出现过，
    // 所以我们只要任选骨牌，判断他的上半部分或者下半部分能否可以作为x即可
    // 
    // 选择第一块多米诺骨牌，取A[0], B[0]
    // 检查其余的骨牌是否出现过A[0], 若有，求出最少翻转次数，其为将A[0]全部翻到A和全部翻到B中较少的次数
    //           ...         B[0] ...                         B[0] ... 
    // 如果两次检查失败，返回-1。 
public:

    // int check(int tgt, vector<int> tops, vector<int> bottoms, int pos) {
    //     int rotNum1 = 0, rotNum0 = 0; //1 for top, 0 for bottom
    //     for (int i = 1; i < tops.size(); i++)
    //     {
    //         if (tops[i] == tgt && bottoms[i] == tgt)
    //         { // 不需要旋转
    //             continue;
    //         }
    //         if (tops[i] == tgt)
    //         {
    //             rotNum1++;
    //         } else if (bottoms[i] == tgt)
    //         {
    //             rotNum0++;
    //         } else {
    //             return -1;
    //         }
    //     }
    //     if (pos == 0)
    //     {
    //         return min(rotNum1, rotNum0 + 1);
    //     } else {
    //         return min(rotNum1 + 1, rotNum0);
    //     }
    // }
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        int rot_a = 0, rot_b = 0;
        for (int i = 0; i < n; i++)
        {
            // couldn't rotate
            if (A[i] != x && B[i] != x)
            {
                return -1;
            } else if (A[i] != x)
            {
                rot_a++;
            } else if (B[i] != x)
            {
                rot_b++;
            }
            // 用不等式会比等式好理解不少
        }
        // min of rotat to have all elem equal to x in A or B
        return min(rot_a, rot_b);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // int n = tops.size(), m = bottoms.size();
        // int A = tops[0], B = bottoms[0];
        // int rotA = check(A, tops, bottoms, 1);
        // int rotB = check(B, tops, bottoms, 0);
        // if (rotA == -1 && rotB == -1)
        // {
        //     return -1;
        // } else if (rotA == -1)
        // {
        //     return rotB;
        // } else if (rotB == -1)
        // {
        //     return rotA;
        // } else {
        //     return min(rotA, rotB);
        // }
        // 官方写法：
        int n = tops.size();
        int rot = check(tops[0], bottoms, tops, n);
        // if one could make all elem in A or B equals to A[0]
        if (rot != -1 || bottoms[0] == tops[0])
        { // 只有A找不到才有必要看B, 如果A和B都找得到，则二者一定相等
            return rot;
        } else { // if one could make all elem in A or B equals to B[0]
            return check(bottoms[0], bottoms, tops, n); // 只有
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,2,4,2,2]\n[5,2,6,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,2,3]\n[3,6,3,3,4]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=3337 lang=cpp
 * @lcpr version=30204
 *
 * [3337] 字符串转换后的长度 II
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
    // I. 矩阵乘法 + 快速幂
    // f(i, c) 表示进行i次转换后，字符串中包含字符c的数量
    // c \in [0, 26) 对应[a:z]
    // f(0, c): c在s中出现的次数
    // 递推式：
    // f(i, c) = \sum_{c' = 0}^25[f(i - 1, c') * T(c, c')]
    // T(c, c') = 0 或 1， c'在一次转换中的替换包含c, 取1，否则为0
    // T(c, c')需要根据nums得来

    // 注意到T(c, c')的取值与i无关，也就是每次递推都确定
    // 把f(i, c)和f(i - 1, c')写成n * 1的列向量，T(c, c')写成n * n的方阵
    // (f(i, 0))   (T(0, 0)   T(0, 1) ... T(0, 25)  )     (f(i-1, 0))
    // (f(i, 1))   (T(1, 0)   T(1, 1) ... T(1, 25)  )     (f(i-1, 1))
    //  ... ...  = ( ... ...                        )   * (...      )
    // (f(i, 25))  (T(25, 0)  T(25, 1) ... T(25, 25))     (f(i-1, 25))
    // => F(i, n) = T * F(i - 1, n)
    // => F(t, n) = T^t F(0, n)
    // 计算F(0, n), 并用快速幂计算T^t, 最后即得答案
public:
    static constexpr int L = 26;
    static constexpr int mod = 1e9 + 7;

    struct Mat {
        Mat() {
            memset(a, 0, sizeof(a));
        }
        Mat(const Mat& that) {
            for (int i = 0; i < L; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    a[i][j] = that.a[i][j];
                }
            }
        }
        Mat& operator=(const Mat& that) {
            if (this != &that)
            {
                for (int i = 0; i < L; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        a[i][j] = that.a[i][j];
                    }
                }
            }
            return *this;
        }

        int a[L][L];
    };

    Mat multi(const Mat& u, const Mat& v) {
        Mat w;
        for(int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++)
            {
                for (int k = 0; k < L; k++)
                {
                    w.a[i][j] = (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
                }
            }
        }
        return w;
    }

    // 单位矩阵
    Mat I() {
        Mat w;
        for (int i = 0; i < L; i++)
        {
            w.a[i][i] = 1;
        }
        return w;
    }

    // 快速幂
    Mat quickmul(const Mat& x, int y) {
        Mat ans = I(), cur = x;
        while (y)
        {
            if (y & 1)
            {
                ans = multi(ans, cur);
            }
            cur = multi(cur, cur);
            y >>= 1;
        }
        return ans;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat T;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                T.a[(i + j) % 26][i] = 1;
            }
        }
        Mat res = quickmul(T, t);
        int ans = 0;
        vector<int> f(26);

        for(char ch: s){
            f[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
            }           
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcyy"\n2\n[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// "azbk"\n1\n[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]\n
// @lcpr case=end

 */


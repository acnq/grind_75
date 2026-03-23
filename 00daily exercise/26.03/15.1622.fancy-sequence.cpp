/*
 * @lc app=leetcode.cn id=1622 lang=cpp
 * @lcpr version=30204
 *
 * [1622] 奇妙序列
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
class Fancy {
    // 本题的难点就是"总计会有10^5次对addAll和multAll的调用",仅仅模拟必然溢出
    // I. 乘法逆元
    // 我们将若干次addAll和multAll操作浓缩为一次,记为二元组(a, b)
    // 相当于对每个元素x变化为ax + b, 所以a,b满足:
    // - 开始 (a, b) = (1, 0);
    // - allAll(inc) => b += inc;
    // - multAll(m) => a *= m; b *= m
    // 假设(a_i, b_i)表示v_i被加入v之前,所有操作得到的浓缩结果
    // 则getIdx(idx)时, 考虑(a_idx, b_idx)和(a_l, b_l)
    // 其中(a_idx, b_idx)表示v_idx被放入v之前的浓缩操作
    // (a_l, b_l)表示执行getIdx时浓缩的操作
    // 若要求的getIdx, 只需要知道(a_idx, b_idx)辩伪(a_l, b_l)的操作即可
    // 记为a_o, b_o
    // 有:
    //  { a_idx * a_o = a_l;
    //  { b_idx * a_o + b_o = b_l
    // getIdx(idx) = a_o * v_idx + b_o
    // 其中:
    // { a_o = a_l / a_idx
    // { b_o = b_l - b_idx * a_l / a_idx
    // 而为了防止(a, b)越界,我们需要通过数论知识提前令答案对10^9 + 7取模
    // 如果 a*a^(-1) = 1 (mod m), 则我们说a^(-1)是a模m的乘法逆元
    // m | a => a^(-1)不存在,否则,存在a^(-1), 且a^(-1)*a = km + 1(k \in NN, 根据定义)
    // a^(-1) a - km = 1, 
    // 若m为质数,根据裴蜀定理,gcd(a, m) = 1, 存在a^(-1), k, s.t.方程有解
    // 且如果a_0^(-1), k_0为解, 则(a_0^(-1) + cm, k_0 + ac)也是一组解
    // 为此我们知道存在一组a_0^(-1) \in (0, m), 即为所求乘法逆元
    // 那么如何求得a^(-1), 根据费马小定理
    // a^(m-1) = 1 (mod m)成立
    // 1 * a^(-1) = a^(m-1) * a^(-1) = a^(m - 2)
    // 我们用快速幂计算出a^(m - 2)即可, 如此b / a = b * a^(-1)
    // {a_o = a_l * a_{idx}^(-1) (mod m)
    // {b_o = b_l - b_{idx} * a_l * a_{idx}^(-1)(mod m)
    // 这样 a_o * v_idx + b_o 即得getIdx的答案 
private:
    static constexpr int mod = 1e9 + 7;
    vector<int> v, a, b;
public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }
    // 快速幂辅助函数
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long) ret * cur % mod;
            }
            cur = (long long) cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }
    // 乘法逆元
    int inv(int x) {
        return quickmul(x, mod - 2);
    }
    
    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }
    
    void addAll(int inc) {
        b.back() = (b.back() + inc) % mod;
    }
    
    void multAll(int m) {
        a.back() = (long long)a.back() * m % mod;
        b.back() = (long long)b.back() * m % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }   
        int ao = (long long)inv(a[idx]) * a.back() % mod;
        int bo = (b.back() - (long long)b[idx] * ao % mod + mod) % mod;
        int ans = ((long long)ao * v[idx] % mod + bo) % mod;
        return ans;
    }

    // 备注1
    // 裴蜀定理:
    // 如果a,b不全为0且有最大公约数d, 则有
    // \forall x, y, d | ax + by, 
    // 且\exist x, y, s.t. ax + by = d 有解
    // 备注2
    // 费马小定理
    // 如果p为素数, 则\forall a \ ZZ 并且 a非p的倍数
    // 有a^(p - 1) = 1 (mod p)
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex","getIndex"][[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]\n
// @lcpr case=end

 */


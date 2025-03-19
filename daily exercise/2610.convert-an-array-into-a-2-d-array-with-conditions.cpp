// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2610 lang=cpp
 * @lcpr version=30204
 *
 * [2610] 转换二维数组
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
public:
    // 利用cnt保存每个数字出现的次数cnt[i]
    // max(cnt[i])就是返回的二维数组的行数（显然）
    // 遍历cnt[i], 每次创建一个新的一维数组，
    // 让i对应的cnt[i]-1，将i放到一维数组中
    // cnt[i] = 0则抹除此数，cnt为空则停止遍历，
    // 最后将所有的一维数组组成的二维数组返回即可

    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int i: nums) {
            cnt[i]++;
        }

        vector<vector<int>> res;
        while (!cnt.empty())
        {
            vector<int> arr;
            for (auto it = cnt.begin(); it != cnt.end();) // 必须用指针
            {
                arr.emplace_back(it->first);
                it->second--;
                if (it->second == 0)
                {
                    it = cnt.erase(it); // 不能写成erase(it->first)
                } else {
                    it++;
                }
            }
            
            res.emplace_back(arr);
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findMatrix
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3,4,1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */


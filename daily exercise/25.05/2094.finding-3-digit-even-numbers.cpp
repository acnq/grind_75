// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 * @lcpr version=30204
 *
 * [2094] 找出 3 位偶数
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
    // I. 穷竭法
    // 可行不会超时

    // II. 反向遍历
    // 直接从小到大遍历所有3位偶数[100:999]
    // 判断三个数位是否是digits数组中三个不同元素

    // 首先用哈希表freq维护digits数组中每个数出现的次数
    // 另用freq_1维护每个遍历偶数中每个数出现的次数，
    // 此时，此偶数能够被数组不重复元素表示的充要条件为：
    // freq_1中每个元素出现的次数不大于他在freq中出现的次数

public:
    bool contains(unordered_map<int, int> freq, unordered_map<int, int> freq1) {
        for(auto& [key, value]: freq) {
            int value1 = freq1[key];
            if (value > value1)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        // I.
        // vector<int> res;
        // unordered_set<int> nums;
        // int num = 0;
        // for (int i = 0; i < digits.size(); i++)
        // {
        //     if (digits[i] != 0)
        //     {
        //         num += 100 * digits[i];
        //         for (int j = 0; j < digits.size(); j++)
        //         {
        //             if (i != j)
        //             {
        //                 num += 10 * digits[j];
        //                 for (int k = 0; k < digits.size(); k++)
        //                 {
        //                     if (k != i && k != j && digits[k] % 2 == 0)
        //                     {
        //                         num += digits[k];
        //                         nums.insert(num);
        //                         num -= digits[k];
        //                     }
        //                 }
        //                 num -= 10 * digits[j];
        //             }
        //         }
        //     }
        //     num -= 100 * digits[i];            
        // }
        // res.assign(nums.begin(), nums.end());
        // sort(res.begin(), res.end());
        // return res;

        // II.
        unordered_map<int, int> freq1;
        unordered_set<int> tmp;
        vector<int> res;
        for (int i = 0; i < digits.size(); i++)
        {
            freq1[digits[i]] ++;
        }
        
        for (int i = 100; i < 1000; i += 2)
        {
            // extract each digis from i 
            // and stats its freq;
            unordered_map<int, int> freq;
            int num = i;
            while (num != 0)
            {
                int digit = num % 10;
                freq[digit] ++;
                num = num / 10;
            }
            
            if(contains(freq, freq1)) {
                tmp.insert(i);
            }
        }
        res.assign(tmp.begin(), tmp.end());
        sort(res.begin(), res.end());
        return res;        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findEvenNumbers
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,1,3,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,8,8,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,5]\n
// @lcpr case=end

 */


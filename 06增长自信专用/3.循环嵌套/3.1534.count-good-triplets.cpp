/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 * @lcpr version=30204
 *
 * [1534] 统计好三元组
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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n - 2; i++)
        {
            for(int j = i + 1; j < n - 1; j++) 
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,1,1,9,7]\n7\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,3]\n0\n0\n1\n
// @lcpr case=end

 */


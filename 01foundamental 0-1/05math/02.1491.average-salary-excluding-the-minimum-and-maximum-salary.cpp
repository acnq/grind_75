// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 * @lcpr version=30204
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
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

#include <numeric> // accumulate 
// @lcpr-template-end
// @lc code=start
class Solution {
    // \bar{a_{n + 1}} - \bar{a_n} = \frac{a_{n + 1}}{n + 1} + (\frac{n}{n + 1} - 1) \bar{a_n}
    // \bar{a_{n + 1}} = \frac{1}{n + 1}(a_{n + 1} + n\bar{a_n}) 
    //  = \frac{a_{n + 1}}{n + 1} + \frac{n}{n + 1}\bar{a_n}
public:
    double average(vector<int>& salary) {
        // sort(salary.begin(), salary.end());
        // int n = salary.size();
        // double move_avg = salary[1] * 1.0;
        // if(n == 3) {
        //     return move_avg;
        // }
        // for(int i = 2; i < n - 1; i++) {
        //     move_avg = salary[i] * 1.0 / i + move_avg / i * (i - 1);
        // }
        // return move_avg;

        // 官方甚至没有用移动平均
        double maxValue = *max_element(salary.begin(), salary.end());
        double minValue = *min_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), - maxValue - minValue);
        return sum / (int)(salary.size() - 2);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=average
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4000,3000,1000,2000]\n
// @lcpr case=end

// @lcpr case=start
// [1000,2000,3000]\n
// @lcpr case=end

// @lcpr case=start
// [6000,5000,4000,3000,2000,1000]\n
// @lcpr case=end

// @lcpr case=start
// [8000,9000,2000,3000,6000,1000]\n
// @lcpr case=end

 */


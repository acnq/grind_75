// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=860 lang=cpp
 * @lcpr version=30204
 *
 * [860] 柠檬水找零
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
    bool canChange(vector<int>& stats, int bill) {
        switch (bill) {
            case 5:
                return true;
                break;
            case 10:
                if(stats[5] >= 1) {
                    stats[5]--;
                    return true;
                } else {
                    return false;
                }
                break;
            case 20:
                if(stats[10] >= 1 && stats[5] >= 1) {
                    stats[10]--;
                    stats[5]--;
                    return true;
                }  else if (stats[5] >= 3) {
                    stats[5] -= 3;
                    return true;
                }else {
                    return false;
                }
                break;
            default:
                break;
        }
        return false;
    }
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) {
            return false;
        } else {
            int n = bills.size();
            vector<int> stats(21, 0);
            for(int i = 0; i < n; i++) {
                if(canChange(stats, bills[i])) {
                    stats[bills[i]]++;
                } else {
                    return false;
                }
            }
        }
        return true;
        // 整体来说不难，26min, 但是stats一开始只设置了10，半天搞不出来
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,5,5,10,20]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,10,10,20]\n
// @lcpr case=end

 */


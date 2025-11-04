/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 * @lcpr version=30204
 *
 * [2043] 简易银行系统
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
class Bank {
private:
    vector<long long> balance;

public:
    Bank(vector<long long>& balance) : balance(balance){
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > balance.size() || account2 > balance.size() || balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > balance.size()) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > balance.size() || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"][[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]\n
// @lcpr case=end

 */


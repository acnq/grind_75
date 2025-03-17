// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=721 lang=cpp
 * @lcpr version=30204
 *
 * [721] 账户合并
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

#include <map>
// @lcpr-template-end
// @lc code=start

class UnionFind
{
private:
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    };

    void unionSet(int idx1, int idx2) {
        parent[find(idx2)] = find(idx1);
    }

    int find(int idx) {
        if (parent[idx] != idx)
        {
            parent[idx] = find(parent[idx]);
        }
        return parent[idx];
    }
};


class Solution {
    // 并查集
    // 两个哈希表，分别记录每个邮箱对应的编号和每个邮箱对应的名称
    // 然后并查集合并
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailIdx;
        map<string, string> emailName;
        int emailCnt = 0;
        for (auto& account: accounts)
        {
            string& name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++)
            {
                string& email = account[i];
                if (!emailIdx.count(email))
                {
                    emailIdx[email] = emailCnt++;
                    emailName[email] = name;
                }
            }
        }
        UnionFind uf(emailCnt);
        for (auto& account: accounts)
        {
            string& firstEmail = account[1];
            int firstIdx = emailIdx[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++)
            {
                string& nextEmail = account[i];
                int nextIdx = emailIdx[nextEmail];
                uf.unionSet(firstIdx, nextIdx);
            }
        }
        map<int, vector<string>> idxEmail;
        for (auto& [email, _]: emailIdx)
        {
            int idx = uf.find(emailIdx[email]);
            vector<string>& account = idxEmail[idx];
            account.emplace_back(email);
            idxEmail[idx] = account;
        }
        vector<vector<string>> merged;
        for (auto& [_, emails] : idxEmail)
        {
            sort(emails.begin(), emails.end());
            string& name = emailName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto& email: emails)
            {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John","johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]\n
// @lcpr case=end

// @lcpr case=start
// [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]\n
// @lcpr case=end

 */


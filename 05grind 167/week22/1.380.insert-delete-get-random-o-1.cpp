/*
 * @lc app=leetcode.cn id=380 lang=cpp
 * @lcpr version=30204
 *
 * [380] O(1) 时间插入、删除和获取随机元素
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
class RandomizedSet {
    // I. 变长数组 + 哈希表
    // 变长数组O(1)获取随机元素，但是难以在O(1)内判断元素的存在性，所以插入删除不合题意
    // 哈希表O(1)内完成插入删除操作，但是无法根据下标定位到特定元素，(find只是摊还O(1)，不合题意)
    // 为此，我们将二者组合，变长数组存储元素，哈希表存储每个元素在变长数组的下标
    // 插入：判断val是否在哈希表中，已经有则返回false, 不存在则插入val，具体如下：
    //      1. 变长数组末尾添加val;
    //      2. 添加val之前的变长数组长度为val所在下标idx, [val, idx]入哈希
    //      3. 返回true
    // 删除：判断val是否在哈希表中，不存在返回False，存在则删除val, 具体如下：
    //      1. 哈希表中获得val的下标idx
    //      2. 变长数组的最后一个元素last移动到下标idx, 哈希表last下标更新为idx
    //      3. 变长数组删除最后一个元素，哈希表删除val;
    //      4. 返回true
private:
    vector<int> nums;
    unordered_map<int, int> indices;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (indices.count(val))
        {
            return false;
        }
        int idx = nums.size();
        nums.emplace_back(val);
        indices[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if (!indices.count(val))
        {
            return false;
        }
        int idx = indices[val];
        int last = nums.back();
        nums[idx] = last;
        indices[last] = idx;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % nums.size();
        return nums[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end




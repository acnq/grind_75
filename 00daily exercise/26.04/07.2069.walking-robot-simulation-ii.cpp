/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 * @lcpr version=30204
 *
 * [2069] 模拟行走机器人 II
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
class Robot {
    // I. 模拟
    // 注意到机器人只会在网格最外圈循环移动
    // 我们预处理机器人移动的循环节, 实现move
    // 细节：
    // 我们预处理数组中原点的朝向为‘南’，用布尔变量记录机器人是否移动过
    //  未移动则返回‘东’
    //  移动过，则idx返回预处理数组中的朝向
    // tc: O(width + height) (预处理)
    // sc: O(width + height)
private:
    bool moved = false;
    int idx = 0;
    vector<pair<int, int>> pos;
    vector<int> dir;
    unordered_map<int, string> to_dir = {
        {0, "East"},
        {1, "North"},
        {2, "West"},
        {3, "South"}
    };

public:
    Robot(int width, int height) {
        for (int i = 0; i < width; i++) {
            pos.emplace_back(i, 0);
            dir.emplace_back(0);
        }

        for (int i = 1; i < height; i++) {
            pos.emplace_back(width - 1, i);
            dir.emplace_back(1);
        }
        for (int i = width - 2; i >= 0; i--) {
            pos.emplace_back(i, height - 1);
            dir.emplace_back(2);
        }
        for (int i = height - 2; i > 0; i--) {
            pos.emplace_back(0, i);
            dir.emplace_back(3);
        }
        dir[0] = 3;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx].first, pos[idx].second};
    }
    
    string getDir() {
        if (!moved) {
            return "East";
        }
        return to_dir[dir[idx]];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"][[6, 3], [2], [2], [], [], [2], [1], [4], [], []]\n
// @lcpr case=end

 */


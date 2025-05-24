/*
 * @lc app=leetcode.cn id=127 lang=cpp
 * @lcpr version=30204
 *
 * [127] 单词接龙
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
    // I. BFS + 优化图
    // 每个单词都抽象为一个点，若两个单词可以只改变一个字母转换，
    // 则添加一条双向边，以此构成，为了方便表示, 每个单词分配一个id
    // 创建一个word2id的映射wordId, beginWord与wordList中所有单词都加入映射
    // 检查endWord是否在映射中，不存在，则输入误解
    // 之后就需要构建图，枚举每一对单词组合会超时，构建虚拟节点
    // e.g. hit->*it,h*t, hi*, 如果有单词能转化为hit, 则该单词也能链接到三个虚拟节点之一
    // 对每个单词，枚举虚拟节点，把该单词对应的id与这些虚拟节点对应的id相连即可
    // 起点加入队列开始BFS, 注意因为存在虚拟节点，所以得到的距离是实际上的两倍，起点自己也算一个
    // 所以路径还要加一 

    // II. 双向BFS
    // 如果每一层都是满N叉数扩展，节点数量会议N为底数指数增长
    // 如果一边从beginWord开始，另一边从endWord开始，每次从两边各扩展一层
    // 某时刻发现两边都访问过的节点就停止，可以可观的减少搜索空间大小 
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;
    void addWord(string& word) {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for(char& it: word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string& word: wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord))
        {
            return 0;
        }
        // I. 
        // vector<int> dis(nodeNum, INT_MAX);
        // int beginId = wordId[beginWord], endId = wordId[endWord];
        // dis[beginId] = 0;

        // queue<int> que;
        // que.push(beginId);
        // while (!que.empty())
        // {
        //     int x = que.front();
        //     que.pop();
        //     if (x == endId)
        //     {
        //         return dis[endId] / 2 + 1;
        //     }
        //     for(int& it: edge[x]) {
        //         if (dis[it] == INT_MAX)
        //         {
        //             dis[it] = dis[x] + 1;
        //             que.push(it);
        //         }
        //     }
        // }
        // return 0;
        // II. 修改部分：
        vector<int> disBegin(nodeNum, INT_MAX);
        int beginId = wordId[beginWord];
        disBegin[beginId] = 0;
        queue<int> queBegin;
        queBegin.push(beginId);

        vector<int> disEnd(nodeNum, INT_MAX);
        int endId = wordId[endWord];
        disEnd[endId] = 0;
        queue<int> queEnd;
        queEnd.push(endId);

        while (!queBegin.empty() && !queEnd.empty())
        {
            int queBeginSize = queBegin.size();
            for (int i = 0; i < queBeginSize; i++)
            {
                int nodeBegin = queBegin.front();
                queBegin.pop();
                if (disEnd[nodeBegin] != INT_MAX)
                {
                    return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
                }
                for(int& it : edge[nodeBegin]) {
                    if (disBegin[it] == INT_MAX)
                    {
                        disBegin[it] = disBegin[nodeBegin] + 1;
                        queBegin.push(it);
                    }
                }
            }
            
            int queEndSize = queEnd.size();
            for (int i = 0; i < queEndSize; i++)
            {
                int nodeEnd = queEnd.front();
                queEnd.pop();
                if (disBegin[nodeEnd] != INT_MAX)
                {
                    return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
                }
                for(int& it: edge[nodeEnd]) {
                    if (disEnd[it] == INT_MAX)
                    {
                        disEnd[it] = disEnd[nodeEnd] + 1;
                        queEnd.push(it);
                    }                   
                }
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

 */


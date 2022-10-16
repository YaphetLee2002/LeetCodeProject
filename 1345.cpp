#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idxSameValue; //关键字是值，值对是与相同值的其他位置的下标
        for (int i = 0; i < arr.size(); i++) {
            idxSameValue[arr[i]].push_back(i); //idxSameValue[i]为一个vector<int>，其中存放着所有在arr中值为i的序号
        }
        unordered_set<int> visitedIndex; //存放已经访问过的下标
        queue<pair<int, int>> q; //q为bfs队列
        q.emplace(0, 0);
        visitedIndex.emplace(0);
        while(!q.empty()) { 
            int idx = q.front().first;
            int step = q.front().second;
            q.pop();
            if(idx == arr.size() - 1) //这个节点的下标就是最后一个，那么直接返回当前的step
                return step;
            int v = arr[idx]; //v为idx这个位置的值
            step++; //步数加一
            //先处理所有与这个节点值相同的节点，这些节点都是step+1
            if(idxSameValue.count(v)) { //如果这个值在idxSameValue中也就是说这个值没访问过
                for (auto &i : idxSameValue[v]) { //对于存放这个值的所有位置
                    if(!visitedIndex.count(i)) { //如果这个位置没有访问过
                        visitedIndex.emplace(i); //现在访问咯
                        q.emplace(i, step); //这个点进入BFS的队列
                    }
                }
                idxSameValue.erase(v); //这个值已经访问过了，擦除
            }
            //再处理这个点后面的点
            if(idx + 1 < arr.size() && !visitedIndex.count(idx + 1)) {
                visitedIndex.emplace(idx + 1);
                q.emplace(idx + 1, step);
            }
            //最后再看这个点前面的点
            if(idx - 1 >= 0 && !visitedIndex.count(idx - 1)) {
                visitedIndex.emplace(idx - 1);
                q.emplace(idx - 1, step);
            }
        }
        return -1;
    }
};
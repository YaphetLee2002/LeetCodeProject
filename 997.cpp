#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n + 1, vector<int>(2, 0));
        for (auto &&i : trust) {
            graph[i[0]][0]++; //出度
            graph[i[1]][1]++; //入度，寻找出度为0，入读为n-1的点
        }
        for (int i = 1; i < n + 1; i++) {
            if (graph[i][0] == 0 && graph[i][1] == n - 1)
                return i;
        }
        return -1;
    }
};
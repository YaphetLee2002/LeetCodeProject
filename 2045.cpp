#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto &i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<vector<int>> path(n + 1, vector<int>(2, INT_MAX));
        queue<pair<int, int>> city;

        city.emplace(1, 0);

        while (path[n][1] == INT_MAX) {
            int nowCity = city.front().first;
            int nowLength = city.front().second;
            city.pop();

            for (auto &i : graph[nowCity]) {
                if (nowLength + 1 < path[i][0]) {
                    path[i][0] = nowLength + 1;
                    city.emplace(i, nowLength + 1);
                }
                else if (nowLength + 1 > path[i][0] && nowLength + 1 < path[i][1]) {
                    path[i][1] = nowLength + 1;
                    city.emplace(i, nowLength + 1);
                }
            }
        }

        int timeCount = 0;
        for (int i = 0; i < path[n][1]; i++) {
            if ((timeCount / change) % 2)
                timeCount += (change - (timeCount % change));
            timeCount += time;
        }
        

        return timeCount;
    }
};
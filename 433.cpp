#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        unordered_set<string> cnt;
        unordered_set<string> visited;
        for (auto &&i : bank)
            cnt.emplace(i);
        if (!cnt.count(end)) return -1;
        queue<string> q;
        q.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            
        }
    }
};
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<bool>> lightsOn(n, vector<bool>(n, false)); //lightsOn[i][j] delegates light's state
        for (auto &i : lamps)
            lightsOn[i[0]][i[1]] = true; 
        int queryTimes = queries.size();
        vector<int> ans(queryTimes, 0);

    }
};
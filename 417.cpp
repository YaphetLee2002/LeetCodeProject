#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> heights;
    void dfs(int m, int n, vector<bool> v);
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    }
};
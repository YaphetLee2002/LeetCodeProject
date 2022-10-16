#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // 俯视图里每有一个数字就加1
        // 正视图中取每一列最高的
        // 侧视图中取每一行最高的
        int ans = 0;
        int n = grid.size();
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
                if (grid[i][j]) ans++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans += row[i];
            ans += col[i];
        }
        return ans;
    }
};
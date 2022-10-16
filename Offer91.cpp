#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        for (int i = 1; i < size; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][2], costs[i - 1][0]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return min(costs[size - 1][0], min(costs[size - 1][1], costs[size][2]));
    }
};
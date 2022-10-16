#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        if (stations.empty()) return  -1;
        int count = 0;
        priority_queue<int> fuel;
        for (auto v: stations) {
            startFuel -= v[0];
            target -= v[1];
            if (startFuel < 0) {
                if (fuel.empty()) return -1;
                startFuel += fuel.top();
                fuel.pop();
                count++;
            }
            fuel.push(v[1]);
        }
        return count;
    }
};
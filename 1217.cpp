#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int size = position.size();
        if (size < 2) return 0;
        int a = 0, b = 0;
        for (int i = 0; i < size; ++i) {
            if (position[i] & 1) a++;
            else b++;
        }
        return min(a, b);
    }
};
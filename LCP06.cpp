#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int minCount(vector<int>& coins) {
        return accumulate(coins.begin(), coins.end(), 0, [](int sum, int a) -> int {
            return sum + (a + 1) / 2;
        });
    }
};
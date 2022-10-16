#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        for (auto &&i : nums) {
            n ^= i;
        }
        int index = 0;
        while (n & 1 == 0) {
            index++;
            n >>= 1;
        }
        
    }
};
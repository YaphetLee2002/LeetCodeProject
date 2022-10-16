#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>min_nums;
        for (int i : nums) {
            auto pos = lower_bound(min_nums.begin(), min_nums.end(), i);
            if (pos == min_nums.end()) {
                min_nums.push_back(i);
            } else {
                *pos = i;
            }
        }
        return min_nums.size();
    }
};
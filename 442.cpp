#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for (size_t i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        for (size_t i = 0; i < n; i++) {
            if (nums[i] > 2 * n) ret.push_back(i + 1);
        }
        return ret;
    }
};
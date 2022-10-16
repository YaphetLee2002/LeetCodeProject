#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[k - 1] - nums[0];
        for (int i = 0; i <= nums.size() - k; i++)
            ans = min(nums[k + i - 1] - nums[i], ans);
        return ans;
    }
};
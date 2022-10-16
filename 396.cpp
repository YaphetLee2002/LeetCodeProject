#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int sum = 0, max = INT_MIN, temp = INT_MIN;
        bool order = true;
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[0] += nums[i] * i;
            sum += nums[i];
            if (temp < nums[i]) {
                temp = nums[i];
            } else {
                order = false;
            }
        }

        if (order) return dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] - sum + n * nums[i - 1];
            max = dp[i] > max ? dp[i] : max;
        }
        
        return max;
    }
};
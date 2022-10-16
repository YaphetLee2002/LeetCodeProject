#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        unordered_map<int, int> numsList;
        for (auto &i : nums) {
            minNum = min(i, minNum);
            maxNum = max(i, maxNum);
            numsList[i]++;
        }
        vector<int> dp(maxNum + 1, 0);
        dp[minNum] = minNum * numsList[minNum];
        for (int i = minNum + 1; i <= maxNum; i++) {
            if(numsList.count(i))
                dp[i] = max(dp[i - 1], dp[i - 2] + i * numsList[i]);
            else
                dp[i] = dp[i - 1];
        }
        return dp[maxNum];
    }
};
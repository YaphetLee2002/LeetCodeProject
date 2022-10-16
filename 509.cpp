#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
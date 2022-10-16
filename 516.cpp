#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));
        for (int i = length - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < length; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][length - 1];
    }
};
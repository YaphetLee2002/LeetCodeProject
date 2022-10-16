#include<vector>
#include<string>
#include<iostream>
#include<utility>
using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) //初始化，所有长度为1的子串都是回文串
            dp[i][i] = true;
        for (int length = 2; length <= n; length++){ //从更短的长度入手
            for (int left = 0; left < n; left++){
                int right = length + left - 1;
                if (right >= n) //已经考虑了该left指针情况下的所有长度子串，跳出循环寻找下一个length
                    break;
                
                if (s[left] != s[right]) //自left至right不为回文串，dp[left][right]设为false
                    dp[left][right] = false;
                else{ //若left处与right处相同
                    if (right - left <= 2) //若left与right长度为1或2，直接为true
                        dp[left][right] = true;
                    else //否则其情况等同于左右各缩进一个单位的情况，而该情况在两重循环前已经考虑；另外，在两重循环前不会进入这里
                        dp[left][right] = dp[left + 1][right - 1];
                }

                if (dp[left][right] && right - left + 1 > maxLen){ //若left至right为回文串，并且其长度更长
                    maxLen = right - left + 1; //那么更新maxLen
                    begin = left; //更新头指针
                }
            }
        }
        return s.substr(begin, maxLen); //
    }
};

class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return 0;
        string hexNum = "0123456789abcdef";
        string ans = "";
        while (num && ans.size() < 8) {
            ans = hexNum[num & 0xf] + ans;
            num >>= 4;
        }
        return ans;
    }
};
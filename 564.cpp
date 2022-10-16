#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string nearestPalindromic(string n) {
        int num = stoi(n);
        if (num <= 10)
            return to_string(num - 1);
        int length = n.size();
        string a(length, '0');
        string b(length, '0');
        string c(length, '0');
        string temp = n.substr(0, length / 2); // temp is the prefix of the num
        
    }
};
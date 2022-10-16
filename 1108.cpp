#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string newString = "";
        for (auto &&i : address) {
            if (i == '.') {
                newString.append("[.]");
            } else {
                newString += i;
            }
        }
        return newString;
    }
};
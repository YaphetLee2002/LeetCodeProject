#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        string stringBuilder;
        for (int i = index; i >= 0; i--)
            stringBuilder.push_back(word[i]);
        stringBuilder.append(word.substr(index + 1));
        return stringBuilder;
    }
};
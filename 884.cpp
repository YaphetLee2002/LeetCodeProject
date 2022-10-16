#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> strList;
        string str = s1 + " " + s2;
        vector<string> res;
        int size = str.size();
        for (int i = 0; i < size; i++) {
            string temp;
            while (str[i] != ' ' && i < size) {
                temp.push_back(str[i]);
                i++;
            }
            strList[temp]++;
        }
        for (auto &i : strList) {
            if (i.second == 1)
                res.push_back(i.first);
        }
        return res;
    }
};
#include<iostream>
#include<string>
#include<sstream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stringstream stringStream;
        stringStream << sentence;
        int count = 0;
        string temp, ans;
        while (stringStream >> temp) {
            count++;
            if (!set.count(temp[0]))
                temp = temp.substr(1) + temp[0];
            temp += "ma" + string(count, 'a');
            ans.append(temp + " ");
        }
        ans.pop_back();
        return ans;
    }
};
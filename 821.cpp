#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int length = s.size();
        vector<int> vec(length);
        int front = -1, behind = -100000;
        
        while (s[++front] != c) {}

        for (int i = 0; i < length; i++) {
            if (i < front) {
                vec[i] = min(front - i, i - behind);
            } else {
                behind = front;
                while (++front != length + 1 && s[front] != c) { }
                if (front == length + 1)
                    front = INT_MAX;
                vec[i] = min(front - i, i - behind);
            }
        }
        return vec;
    }
};
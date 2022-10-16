#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLength = 0;
        int ans = 0;
        for (auto &i : rectangles) {
            int length = min(i[0], i[1]);
            if (length == maxLength)
                ans++;
            else if (length > maxLength)
                ans = 1; maxLength = length;
        }
        return ans;
    }
};
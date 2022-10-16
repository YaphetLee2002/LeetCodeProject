#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = INT_MIN;
        for (auto v : accounts) {
            int temp = 0;
            for (auto i : v) {
                temp += i;
            }
            if (temp > max) {
                max = temp;
            }
            
        }
        return max;
    }
};
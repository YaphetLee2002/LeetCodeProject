#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorElement = *nums.begin();
        for (auto &&i : nums) {
            if (i == majorElement) {
                count++;
            } else {
                count--;
                if (count < 0) {
                    count = 0;
                    majorElement = i;
                }
            }
        }
        return majorElement;
    }
};
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && (nums[j] & 1)) --j;
            while (i < j && !(nums[i] & 1)) ++i;
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
        return nums;
    }
};
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<int> ans;
public:
    Solution(vector<int>& nums) {
        ans = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int index = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == target) {
                count++;
                if (rand() % count == 0)
                    index = i;
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
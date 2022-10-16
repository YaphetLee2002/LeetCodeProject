#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    static int findMaxLength(vector<int>& nums) {
        vector<int>prefixNums;
        for (auto &&i : nums)
            prefixNums.emplace_back((i?i:-1));
        vector<int>prefixSum(nums.size(), 0);
        prefixSum[0] = prefixNums[0];
        for (int i = 1; i < nums.size(); i++) {
                prefixSum[i] = prefixSum[i - 1] + prefixNums[i];
        } //prefixSum[i]代表从prefixSum[0]到prefixSum[i]的和
        // for (auto &&i : prefixSum)
        // {
        //     cout << i << endl;
        // }
        
        unordered_map<int, int> maps;
        maps.emplace(prefixSum[0], 0);
        int maxLength = 0;
        for (int i = 1; i < nums.size(); i++) {
            if(prefixSum[i] == 0)
                maxLength = (i + 1) > maxLength ? (i + 1) : maxLength;
            if(maps.count(prefixSum[i])) {
                int tempLength = i - maps[prefixSum[i]];
                maxLength = tempLength > maxLength ? tempLength : maxLength;
            }
            else
                maps.emplace(prefixSum[i], i);
        }
        return maxLength;
    }
};

int main()
{
    vector<int> v(3, 0);
    for (auto &&i : v) {
        cin >> i;
    }
    int n = Solution::findMaxLength(v);
    cout << n << endl;
    return 0;
}
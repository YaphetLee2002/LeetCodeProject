#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>(0));
        for (auto num : nums) {
            int temp = ans.size();
            for (int i = 0; i < temp; ++i) {
                vector<int> tempv = ans[i];
                tempv.push_back(num);
                ans.push_back(tempv);
            }
        }
        return ans;
    }
};
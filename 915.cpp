#include <vector>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int left_max = nums[0];
        int max_num = nums[0];
        int size = nums.size();
        for (int i = 1; i < nums.size(); ++i) {
            max_num = max(max_num, nums[0]);
            if (nums[i] > left_max) {
                size = i;
                left_max = nums[i];
            }
        }
        return size;
    }
};
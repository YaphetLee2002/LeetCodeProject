#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                int j = lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin();
                cnt += i - j;
            }
            if (cnt >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
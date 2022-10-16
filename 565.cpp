#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
    unordered_set<int> visited;

public:

    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited.count(i)) {
                int temp = i;
                int length = 0;
                while (temp != i || length == 0) {
                    length++;
                    temp = nums[temp];
                    visited.emplace(temp);
                }
                maxLength = max(maxLength, length);
                if (maxLength > nums.size() / 2) return maxLength;
            }
        }
        return maxLength;

    }
};
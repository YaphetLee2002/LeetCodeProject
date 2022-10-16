#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size == 1) return 1;
        int ans_forward = 0, ans_reverse = 0;
        int forward_min = INT_MIN, reverse_min = INT_MIN;
        vector<int> forward (size, 0);
        vector<int> reverse (size, 0);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                forward[i] = forward[i - 1] + 1;
            } else {
                forward[i] = forward[i - 1] - 1;
            }
            forward_min = min(forward_min, forward[i]);


            if (ratings[size - 1 - i] > ratings[size - i]) {
                reverse[size - 1 - i] = reverse[size - i] + 1;
            } else {
                reverse[size - 1 - i] = reverse[size - i] - 1;
            }
            reverse_min = min(reverse_min, reverse[i]);
        }
        for (int i = 0; i < size; ++i) {
            ans_forward += forward[i] - forward_min + 1;
            ans_reverse += reverse[i] - reverse_min + 1;
        }
        return min(ans_forward, ans_reverse);
    }
};
#include <vector>
using namespace std;
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        size_t size = nums1.size();
        int change = 1, noChange = 0;
        int preChange = 1, preNoChange = 0;
        for (int i = 1; i < size; i++) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                    change = min(preChange,preNoChange) + 1;
                    noChange = min(preChange, preNoChange);
                } else {
                    change = preChange + 1;
                    noChange = preNoChange;
                }
            } else {
                change = preNoChange + 1;
                noChange = preChange;
            }
            preChange = change;
            preNoChange = noChange;
        }
        return min(change, noChange);
    }
};
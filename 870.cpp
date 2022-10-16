#include <vector>
#include <algorithm>
#include <set>
#include <ios>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        ios::sync_with_stdio(false);
        multiset<int> multiset1(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto num2: nums2) {
            auto it = multiset1.upper_bound(num2);
            if (it == multiset1.end()) {
                ans.emplace_back(*multiset1.begin());
                multiset1.erase(multiset1.begin());
            } else {
                ans.emplace_back(*it);
                multiset1.erase(it);
            }
        }
        return ans;
    }
};
#include<vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int length = arr.size();
        vector<int> res;
        for (auto &&i : arr) {
            if (i == 0) {
                res.push_back(0);
                res.push_back(0);
            }
            else {
                res.push_back(i);
            }
            if (res.size() >= length) break;
        }
        if (res.size() > length)
            res.pop_back();
        arr = res;
    }
};
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int l = 0, r = n;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') ans.push_back(l++);
            else ans.push_back(r--);
        }
        ans.push_back(r);
        return ans;
    }
};
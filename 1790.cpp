#include <string>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = -1;
        for (int i = 0; i != s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (diff != -1) {
                    swap(s1[diff], s1[i]);
                    return s1 == s2;
                }
                diff = i;
            }
        }
        return diff == -1;
    }
};
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        int deep = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                deep++;
            else {
                deep--;
                if (s[i - 1] == '(') {
                    ans += 1 << deep;
                }
            }
        }
        return ans;
    }
};
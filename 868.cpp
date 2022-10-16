#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int distance = 0; //记录当前最大距离
        int count = INT_MAX; //记录上一个1的位置
        for (int digit = 1; n > 0; digit++) {
            if (n & 1) {
                distance = max(digit - count, distance);
                count = digit;
            }
            n >>= 1;
        }
        
        return distance;
    }
};
int main() {
    int n;
    cin >> n;
    Solution solution;
    cout << solution.binaryGap(n);
    return 0;
}

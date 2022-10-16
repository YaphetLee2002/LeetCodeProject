#include<iostream>
using namespace std;
class Solution {
public:
    static bool hasAlternatingBits(int n) {
        int temp = n ^ (n >> 1);
        int temptemp = temp & (temp + 1);
        return temptemp == 0;
    }
};

int main() {
    int n = 0;
    scanf("%d", &n);
    if(Solution::hasAlternatingBits(n)) {
        printf("True.\n");
    } else {
        printf("False.\n");
    }
    return 0;
}
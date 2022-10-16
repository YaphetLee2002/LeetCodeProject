#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0;
        int second = 0;
        int size = cost.size();
        for (int i = 2; i <= size; i++) {
            int temp = second;
            second = min(first + cost[i - 2], temp+ cost[i - 1]);
            first = temp;
        }
        
        return second;
    }
};
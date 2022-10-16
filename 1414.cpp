#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> Fib(2, 1);
        
        int times = 1;
        if(k == 1 || k == 2)
            return 1;
        else {
            int i = 2;
            while(Fib[i - 1] < k) {
                Fib.push_back(Fib[i - 1] + Fib[i - 2]);
                if(Fib[i] == k)
                    return 1;
                ++i;
            }
            k -= Fib[i - 2];
        }
        if(k < 0)
            return -2;
        while(k > 0) {
            int i = 0;
            while(Fib[i] < k) { i++; }
            i--;
            if(Fib[i] == k)
                return times + 1;
            else
                k -= Fib[i];
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int k;
    cin >> k;
    cout << solution.findMinFibonacciNumbers(k) << endl;
    return 0;
}
#include<string>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> number;
        int ans = 0, num = 0;
        char character = '+';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0')
            {
                num = num * 10 - '0' + s[i];
            }
            
            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1)
            {
                if (character == '+')
                {
                    number.push(num);
                }
                else if (character == '-')
                {
                    number.push(-num);
                }
                else if (character == '*' || character == '/')
                {
                    int temp = character == '*' ? num * number.top() : number.top() / num;
                    number.pop();
                    number.push(temp);
                }
                character = s[i];
                num = 0;
            }
        }
        for (; !number.empty(); number.pop())
        {
            ans += number.top();
        }
        
        return ans;
        
    }
};
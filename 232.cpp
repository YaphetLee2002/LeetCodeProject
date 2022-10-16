#include<iostream>
#include<list>
#include<stack>
using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int elem = s2.top();
        s2.pop();
        return elem;
    }
    
    int peek() {
        int elem = this->pop();
        s2.push(elem);
        return elem;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
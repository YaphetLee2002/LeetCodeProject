#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MUTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int>& cards) { //启动函数
        vector<double> l;
        for (auto &i : cards) {
            l.emplace_back(static_cast<double>(i)); //类型全都转化为double
        }
        return solve(l);
    }
    bool solve(vector<double>& l) {
        if(l.size() == 0)
            return false;
        if(l.size() == 1)
            return fabs(l[0] - TARGET) < EPSILON; //因为是浮点数运算，可以取极小量ε判断结果和目标值的差是否小于ε
            
        int size = l.size();
        for (int i = 0; i < size; i++) { //i和j分别是抽的两个数
            for (int j = 0; j < size; j++) {
                if(i != j) { //这两个不能抽同一张牌
                    vector<double> list2;
                    for (int k = 0; k < size; k++) {
                        if(k != i && k != j) //把除了选的ij以外的数先放进list2
                            list2.emplace_back(l[k]);
                    }
                    for (int k = 0; k < 4; k++) {
                        if(k < 2 && i < j) //如果是加法和乘法，跳过一半
                            continue;
                        if(k == ADD) 
                            list2.emplace_back(l[i] + l[j]);
                        else if(k == MUTIPLY)
                            list2.emplace_back(l[i] * l[j]);
                        else if(k == SUBTRACT)
                            list2.emplace_back(l[i] - l[j]);
                        else if(k == DIVIDE) {
                            if(fabs(l[j] < EPSILON))
                                continue;
                            list2.emplace_back(l[i] / l[j]);
                        }
                        if(solve(list2)) //用这个新得到的数组去做solve
                            return true;
                        list2.pop_back(); //去掉刚刚加进来的这种运算思路，继续换下一种运算（k++）
                    }
                }
            }
        }
        return false;
    }
};
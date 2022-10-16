#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> pointList;

    DetectSquares() {
    }
    
    void add(vector<int> point) {
        pointList[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if(!pointList.count(y))
            return 0;
        unordered_map<int, int>& colList = pointList[y];
        for (auto &i : pointList) {
            int _y = i.first;
            if(_y == y)
                continue;
            unordered_map<int, int> _yList = i.second;
            int a = y - _y;
            res += (_yList.count(x) ? _yList[x] : 0) *
                   (_yList.count(x+a) ? _yList[x+a] : 0) *
                   (colList.count(x+a) ? colList[x+a] : 0);
            res += (_yList.count(x) ? _yList[x] : 0) *
                   (_yList.count(x-a) ? _yList[x-a] : 0) *
                   (colList.count(x-a) ? colList[x-a] : 0);
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
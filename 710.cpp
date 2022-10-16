#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    unordered_map<int, int> dictionary;
    int distance;
public:
    Solution(int n, vector<int>& blacklist) {
        int size = blacklist.size();
        distance = n - size;
        int bound = distance;
        unordered_set<int> black;
        for (auto i : blacklist) {
            if (i >= distance) {
                black.emplace(i);
            }
        }
        for (auto i : blacklist) {
            if (i > distance) {
                while (black.count(bound)) bound++;
                dictionary[i] = bound++;
            }
        }
    }

    int pick() {
        int num = rand() % distance;
        if (dictionary.count(num)) return dictionary[num];
        else return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
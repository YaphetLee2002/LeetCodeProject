#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        vector<string> res;
        for (auto cp : cpdomains) {
            int space = cp.find(' ');
            int num = stoi(cp.substr(0 ,space));
            cp = cp.substr(space + 1);
            map[cp] += num;
            for (int i = 0; i < cp.size(); ++i) {
                if (cp[i] == '.') {
                    string domain = cp.substr(i + 1);
                    map[domain] += num;
                }
            }
        }
        for (const auto& [domain, num] : map) {
            res.push_back(to_string(num) + " " + domain);
        }
        return res;
    }
};
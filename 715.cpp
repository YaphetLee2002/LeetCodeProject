#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class RangeModule {
    map<int, int> range;
public:
    RangeModule() = default;

    void addRange(int left, int right) {
        auto p = range.lower_bound(left);
        int l = left, r = right;
        while (p != range.end() && p->second <= right) {
            l = min(l, p->second);
            r = max(r, p->first);
            range.erase(p++);
        }
        range[r] = l;
    }

    bool queryRange(int left, int right) {
        auto p = range.lower_bound(left);
        if (p == range.end()) return false;
        if (p->second <= left && p->first >= right) {
            return true;
        }
        return false;
    }

    void removeRange(int left, int right) {
        auto p = range.lower_bound(left + 1);

        while (p != range.end() && p->second < right) {
            if (p->second < left) {
                range[left] = p->second;
            }
            if (p->first > right) {
                range[p->first] = right;
                break;
            } else {
                range.erase(p++);
            }
        }
    }
};
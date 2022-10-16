#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    unordered_set<int> nums_set;
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        bool go_on = false;
        for (auto &&num: nums) {
            nums_set.insert(num);
        }
        while (head != nullptr) {
            if (nums_set.count(head->val)) {
                if (!go_on) {
                    ans++;
                }
                go_on = true;
            } else {
                go_on = false;
            }
            head = head->next;
        }
        return ans;
    }
};
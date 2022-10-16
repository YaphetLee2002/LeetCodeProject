#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 深度优先搜索
class Solution {
    unordered_map<int, int> cnt;
    int max_count = 0;
    int dfs(TreeNode * root) {
        if (root == nullptr) return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        max_count = max(max_count, ++cnt[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        dfs(root);
        for (auto &[s, c]:cnt) {
            if (c == max_count) {
                res.push_back(s);
            }
        }
        return res;
    }
};
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>(0);
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                v[i] = node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
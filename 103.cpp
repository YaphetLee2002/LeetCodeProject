#include<vector>
#include<queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>(0);
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool is_reverse = false;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v (size, 0);
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                v[is_reverse ? size - i - 1 : i] = node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            is_reverse ^= true;
            ans.push_back(v);
        }
        return ans;
    }
};

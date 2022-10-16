#include<vector>
#include<queue>
#include <climits>

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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return vector<int> (0);
        queue<TreeNode*> q;
        vector<int> ans;
        q.emplace(root);
        while (!q.empty()) {
            int max_num = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                max_num = max(node->val, max_num);
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            ans.push_back(max_num);
        }
        return ans;
    }
};
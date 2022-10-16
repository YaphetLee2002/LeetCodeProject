#include <vector>
#include <queue>

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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root != nullptr) q.emplace(root, 1);
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            if (node->left == nullptr && node->right && nullptr) return depth;
            if (node->left != nullptr) q.emplace(node->left, depth + 1);
            if (node->right != nullptr) q.emplace(node->right, depth + 1);

        }
        return 0;
    }
};
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
    long val = LONG_MIN;
public:
    bool dfs(TreeNode* root) {
        if (root == nullptr) return true;
        if (!dfs(root->left)) return false;
        if (root->val <= val) return false;
        val = root->val;
        if (!dfs(root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
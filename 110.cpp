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
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        if (abs(lh - rh) <= 1 && lh >= 0 && rh >= 0) return max(lh, rh) + 1;
        else return -1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }
};
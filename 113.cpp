#include <vector>
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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int> &temp, int sum) {
        if (root == nullptr) return;
        temp.push_back(root->val);
        if (root->val == sum && root->left == nullptr && root->right == nullptr) ans.push_back(temp);
        dfs(root->left, temp, sum - root->val);
        dfs(root->right, temp, sum - root->val);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root, temp, targetSum);
        return ans;
    }
};
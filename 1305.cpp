#include<iostream>
#include<vector>
#include<algorithm>
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

    void preOrderTraverse(TreeNode* root, vector<int>& v) {
        if (root != NULL) {
            preOrderTraverse(root->left, v);
            v.push_back(root->val);
            preOrderTraverse(root->right, v);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, ans;
        preOrderTraverse(root1, v1);
        preOrderTraverse(root2, v2);
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans));
        return ans;
    }
};
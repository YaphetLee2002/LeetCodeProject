#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        TreeNode* tree = root;
        int times = k;
        stack<TreeNode*> s = stack<TreeNode*>();
        while (tree || !s.empty()) {
            while (tree) {
                s.push(tree);
                tree = tree->right;
            }
            if (!s.empty()) {
                tree = s.top();
                s.pop();
                if (--times == 0)
                    return tree->val;
                tree = tree->left;
            }
        }
        return -1;
    }
};
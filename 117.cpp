#define NULL nullptr
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.emplace(root);
        if (root == nullptr) return nullptr;
        while(!q.empty()) {
            int size = q.size();
            Node* pre_node = nullptr;
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                if (pre_node != nullptr) pre_node->next = node;
                pre_node = node;
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);

            }
        }
        return root;
    }
};
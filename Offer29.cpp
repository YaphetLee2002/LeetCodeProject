#include<vector>
using namespace std;
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto node = new Node(insertVal);
        if (head == nullptr) {
            head = node;
            head->next = head;
            return head;
        }
        auto current = head;
        auto next = current->next;
        while (current->val <= next->val) {
            current = next;
            next = next->next;
            if (current == head) break;
        }
        auto realHead = next;
        while (next->val < node->val) {
            current = next;
            next = next->next;
            if (next == realHead) break;
        }
        node->next = current->next;
        current->next = node;
        return head;
    }
};